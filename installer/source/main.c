#include <ps4.h>

#include "defines.h"
// #include "debug.h"
#include "ddebug.h"
#include "offsets.h"

#define PS4_UPDATE_FULL_PATH "/update/PS4UPDATE.PUP"
#define PS4_UPDATE_TEMP_PATH "/update/PS4UPDATE.PUP.net.temp"

#define ROUND_PG(x) (((x) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))

extern char kpayload[];
extern unsigned kpayload_size;

int install_payload(struct thread *td, struct payload_info* payload_info)
{
	struct ucred* cred;
	struct filedesc* fd;

	fd = td->td_proc->p_fd;
	cred = td->td_proc->p_ucred;

	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - XFAST_SYSCALL_addr);

	int( * printf)(const char * format, ...) = (kernel_base + 0x450e80);
	uint8_t* kernel_ptr = (uint8_t*)kernel_base;

	printf("kernel base: %p\n", kernel_base);
	void** got_prison0 = (void**)&kernel_ptr[PRISON0_addr];
	void** got_rootvnode = (void**)&kernel_ptr[ROOTVNODE_addr];

	void (*pmap_protect)(void * pmap, uint64_t sva, uint64_t eva, uint8_t pr) = (void *)(kernel_base + pmap_protect_addr);
	// void* (*malloc)(unsigned long size, void* type, int flags) = (void *)(kernel_base + malloc_addr);
	void *kernel_pmap_store = (void *)(kernel_base + PMAP_STORE_addr);

	uint8_t* payload_data = payload_info->buffer;
	printf("payload_data: %p\n", payload_data);
	size_t payload_size = payload_info->size;
	printf("payload_size: %zu\n", payload_size);
	struct payload_header* payload_header = (struct payload_header*)payload_data;
	uint8_t* payload_buffer = (uint8_t*)&kernel_base[DT_HASH_SEGMENT_addr];

	printf("payload_header->signature: %llx\n", payload_header->signature);

	if (!payload_data || payload_size < sizeof(payload_header) || payload_header->signature != 0x5041594C4F414458ull) {
		printf("payload header signature not found\n");
		return -1;
	}

	printf("payload_header->entrypoint_offset: %zu\n", payload_header->entrypoint_offset);
	cred->cr_uid = 0;
	cred->cr_ruid = 0;
	cred->cr_rgid = 0;
	cred->cr_groups[0] = 0;

	printf("cred: %p\n", cred);
	cred->cr_prison = *got_prison0;
	fd->fd_rdir = fd->fd_jdir = *got_rootvnode;

	// escalate ucred privs, needed for access to the filesystem ie* mounting & decrypting files
	void *td_ucred = *(void **)(((char *)td) + 304); // p_ucred == td_ucred
	// printf("td_ucred: %p\n", td_ucred);

	// sceSblACMgrIsSystemUcred
	uint64_t *sonyCred = (uint64_t *)(((char *)td_ucred) + 96);
	*sonyCred = 0xffffffffffffffff;
	// printf("sceSblACMgrIsSystemUcred: %p\n", sonyCred);

	// sceSblACMgrGetDeviceAccessType
	uint64_t *sceProcType = (uint64_t *)(((char *)td_ucred) + 88);
	*sceProcType = 0x3801000000000013; // Max access
	// printf("sceSblACMgrGetDeviceAccessType: %p\n", sceProcType);

	// sceSblACMgrHasSceProcessCapability
	uint64_t *sceProcCap = (uint64_t *)(((char *)td_ucred) + 104);
	*sceProcCap = 0xffffffffffffffff; // Sce Process
	// printf("sceSblACMgrHasSceProcessCapability: %p\n", sceProcCap);

	// Disable write protection
	uint64_t cr0 = readCr0();
	writeCr0(cr0 & ~X86_CR0_WP);

	// printf("cr0: %llx\n", cr0);

	// debug menu error patches 5.05
	*(uint32_t *)(kernel_base + debug_menu_error_patch1) = 0;
	*(uint32_t *)(kernel_base + debug_menu_error_patch2) = 0;
	// printf("debug menu error patches applied\n");

	// flatz disable pfs signature check 5.05
	*(uint32_t *)(kernel_base + disable_signature_check_patch) = 0x90C3C031;
	// printf("disable pfs signature check patch applied\n");

	// flatz enable debug RIFs 5.05
	*(uint32_t *)(kernel_base + enable_debug_rifs_patch1) = 0x90C301B0;
	*(uint32_t *)(kernel_base + enable_debug_rifs_patch2) = 0x90C301B0;
	// printf("enable debug RIFs patch applied\n");

	// flatz allow sys_dynlib_dlsym in all processes 5.05
	*(uint64_t*)(kernel_base + sys_dynlib_dlsym_patch) = 0x8b48900000013ae9;
	// printf("allow sys_dynlib_dlsym in all processes patch applied\n");

	// spoof sdk_version - enable vr 5.05
	// *(uint32_t *)(kernel_base + sdk_version_patch) = FAKE_FW_VERSION;
	// *(uint32_t *)(kernel_base + fake_dex_patch) = FAKE_DEX;

	// enable debug log
	// *(uint16_t*)(kernel_base + enable_debug_log_patch) = 0x38EB;
	// printf("enable debug log patch applied\n");

	// enable uart output
	// *(uint32_t *)(kernel_base + enable_uart_patch) = 0;

	// install kpayload
	memset(payload_buffer, 0, ROUND_PG(kpayload_size));
	memcpy(payload_buffer, payload_data, payload_size);
	printf("payload copied to kernel memory\n");

	uint64_t sss = ((uint64_t)payload_buffer) & ~(uint64_t)(PAGE_SIZE-1);
	uint64_t eee = ((uint64_t)payload_buffer + payload_size + PAGE_SIZE - 1) & ~(uint64_t)(PAGE_SIZE-1);
	printf("kernel base: %p\n", kernel_base);
	// printf("sss: %llx %llx\n", sss, eee);
	kernel_base[pmap_protect_p_addr] = 0xEB;
	pmap_protect(kernel_pmap_store, sss, eee, 7);
	kernel_base[pmap_protect_p_addr] = 0x75;
	printf("payload memory protected\n");

	// Restore write protection
	writeCr0(cr0);

	int (*payload_entrypoint)();
	*((void**)&payload_entrypoint) = (void*)(&payload_buffer[payload_header->entrypoint_offset]);
	printf("payload_entrypoint: %p\n", payload_entrypoint);
	return payload_entrypoint();
}

static inline void patch_update(void)
{
	unlink(PS4_UPDATE_FULL_PATH);
	unlink(PS4_UPDATE_TEMP_PATH);

	mkdir(PS4_UPDATE_FULL_PATH, 0777);
	mkdir(PS4_UPDATE_TEMP_PATH, 0777);
}

int _main(struct thread *td)
{
	int result;

	initKernel();
	initLibc();

#ifdef DEBUG_SOCKET
	initNetwork();
	initDebugSocket();
#endif

	printfsocket("Starting...\n");

	struct payload_info payload_info;
	payload_info.buffer = (uint8_t *)kpayload;
	payload_info.size = (size_t)kpayload_size;

	errno = 0;
	result = 0;

	result = kexec(&install_payload, &payload_info);
	result = !result ? 0 : errno;
	// printfsocket("install_payload: %d\n", result);

	patch_update();

	initSysUtil();
	notify("Welcome to PS4HEN v"VERSION" by BestPig");

	printfsocket("Done.\n");

#ifdef DEBUG_SOCKET
	closeDebugSocket();
#endif

	return result;
}

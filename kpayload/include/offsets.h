#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data
#define	XFAST_SYSCALL_addr              0x00001c0
#define M_TEMP_addr                     0x1a5fe30
#define MINI_SYSCORE_SELF_BINARY_addr   0x1541e78
#define ALLPROC_addr                    0x2269f30
#define SBL_DRIVER_MAPPED_PAGES_addr    0x2646ca8
#define SBL_PFS_SX_addr                 0x265c310
#define SBL_KEYMGR_KEY_SLOTS_addr       0x2660858
#define SBL_KEYMGR_KEY_RBTREE_addr      0x2660868
#define SBL_KEYMGR_BUF_VA_addr          0x2664000
#define SBL_KEYMGR_BUF_GVA_addr         0x2664808
#define FPU_CTX_addr                    0x26796c0
#define DIPSW_addr                      0x1be45d0

// common
#define memcmp_addr                     0x02a020
#define _sx_xlock_addr                  0x0977a0
#define _sx_xunlock_addr                0x097960
#define malloc_addr                     0x36e120
#define free_addr                       0x36e2e0
#define strstr_addr                     0x2fdb20
#define fpu_kern_enter_addr             0x300a80
#define fpu_kern_leave_addr             0x300b40
#define memcpy_addr                     0x0d7370
#define memset_addr                     0x00d090
#define strlen_addr                     0x160da0
#define printf_addr                     0x450e80
#define eventhandler_register_addr      0x0ed020

// Fself
#define sceSblACMgrGetPathId_addr       0x1f4520
#define sceSblServiceMailbox_addr       0x630550
#define sceSblAuthMgrSmIsLoadable2_addr 0x643bf0
#define _sceSblAuthMgrGetSelfInfo_addr  0x644430
#define _sceSblAuthMgrSmStart_addr      0x63beb0
#define sceSblAuthMgrVerifyHeader_addr  0x643c50

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x350360
#define Sha256Hmac_addr                 0x441bb0
#define AesCbcCfb128Encrypt_addr        0x33ee60
#define AesCbcCfb128Decrypt_addr        0x33f090
#define sceSblDriverSendMsg_0_addr      0x61b3c0
#define sceSblPfsSetKeys_addr           0x622f50
#define sceSblKeymgrSetKeyStorage_addr  0x622910
#define sceSblKeymgrSetKeyForPfs_addr   0x625670
#define sceSblKeymgrCleartKey_addr      0x6259b0
#define sceSblKeymgrSmCallfunc_addr     0x625240

// Patch
#define vmspace_acquire_ref_addr        0x476140
#define vmspace_free_addr               0x475f70
#define vm_map_lock_read_addr           0x4762d0
#define vm_map_unlock_read_addr         0x476320
#define vm_map_lookup_entry_addr        0x476910
#define proc_rwmem_addr                 0x4244a0

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x64117c
#define sceSblAuthMgrIsLoadable2_hook                               0x6412ce
#define sceSblAuthMgrVerifyHeader_hook1                             0x641a66
#define sceSblAuthMgrVerifyHeader_hook2                             0x642749
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x63e2fd
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x63ef38

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x6229b5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x62682d
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x64b880
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x64c64e
#define mountpfs__sceSblPfsSetKeys_hook1                            0x6b59f9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x6b5c2a

// SceShellUI patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x01cfc0
#define sceSblRcMgrIsStoreMode_patch                                0x01d320

// SceShellUI patches - remote play patches
// #define CreateUserForIDU_patch                                      0x1B11D6 // done
// #define remote_play_menu_patch                                      0xEE638E // bypass

// SceRemotePlay patches - remote play patches
// #define SceRemotePlay_patch1                                        0x3C33F // bypass
// #define SceRemotePlay_patch2                                        0x3C35A // bypass

// SceShellCore patches
// call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x16b664 // done
#define sceKernelIsGenuineCEX_patch2    0x85bab4 // done
#define sceKernelIsGenuineCEX_patch3    0x8abce2 // done
#define sceKernelIsGenuineCEX_patch4    0xa0ca84 // done

// call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x16b692 // done
#define nidf_libSceDipsw_patch2         0x249b0c // done
#define nidf_libSceDipsw_patch3         0x85bae2 // done
#define nidf_libSceDipsw_patch4         0xa0cab2 // done

// enable data mount
#define enable_data_mount_patch         0x31e890 // done

// enable fpkg
#define enable_fpkg_patch               0x3d544f // done

// debug pkg free string
#define fake_free_patch                 0xfb5d59 // done

// make pkgs installer working with external hdd
#define pkg_installer_patch             0x9f5fd1 // bypass

// enable support with 6.xx external hdd
#define ext_hdd_patch                   0x606b7d // done

// enable debug trophies on retail
// #define debug_trophies_patch            0x6ABE39 // bypass

// disable screenshot block
// #define disable_screenshot_patch        0xCB8C6 // bypass

#endif
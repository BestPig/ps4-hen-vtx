#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data
#define	XFAST_SYSCALL_addr              0x00001C0 // done
#define M_TEMP_addr                     0x1a5fe30 // done
#define MINI_SYSCORE_SELF_BINARY_addr   0x1541e78 // done
#define ALLPROC_addr                    0x2269f30 // done
#define SBL_DRIVER_MAPPED_PAGES_addr    0x2646ca8 // done
#define SBL_PFS_SX_addr                 0x265c310 // done
#define SBL_KEYMGR_KEY_SLOTS_addr       0x2660858 // done
#define SBL_KEYMGR_KEY_RBTREE_addr      0x2660868 // done
#define SBL_KEYMGR_BUF_VA_addr          0x2664000 // done
#define SBL_KEYMGR_BUF_GVA_addr         0x2664808 // done
#define FPU_CTX_addr                    0x26796c0 // done
#define DIPSW_addr                      0xaccf2 // unsure

// common
#define memcmp_addr                     0x2a020 // done
#define _sx_xlock_addr                  0x977a0 // done
#define _sx_xunlock_addr                0x97960 // done
#define malloc_addr                     0x36e120 // done
#define free_addr                       0x36e2e0 // done
#define strstr_addr                     0x2fdb20 // done
#define fpu_kern_enter_addr             0x300a80 // done
#define fpu_kern_leave_addr             0x300b40 // done
#define memcpy_addr                     0xd7370 // done
#define memset_addr                     0xd090 // done
#define strlen_addr                     0x160da0 // done
#define printf_addr                     0x450e80 // done
#define eventhandler_register_addr      0xed020 // done

// Fself
#define sceSblACMgrGetPathId_addr       0x1f4520 // done
#define sceSblServiceMailbox_addr       0x630550 // done
#define sceSblAuthMgrSmIsLoadable2_addr 0x643bf0 // done
#define _sceSblAuthMgrGetSelfInfo_addr  0x644430 // done
#define _sceSblAuthMgrSmStart_addr      0x63beb0 // done
#define sceSblAuthMgrVerifyHeader_addr  0x63dc30 // done

// Fpkg
// #define RsaesPkcs1v15Dec2048CRT_addr    0x1FD7D0
#define Sha256Hmac_addr                 0x441bb0 // done
#define AesCbcCfb128Encrypt_addr        0x33ee60 // done
#define AesCbcCfb128Decrypt_addr        0x33f090 // done
#define sceSblDriverSendMsg_0_addr      0x61b3c0 // done
#define sceSblPfsSetKeys_addr           0x622f50 // done
#define sceSblKeymgrSetKeyStorage_addr  0x622910 // done
#define sceSblKeymgrSetKeyForPfs_addr   0x625670 // done
#define sceSblKeymgrCleartKey_addr      0x6259b0 // done
#define sceSblKeymgrSmCallfunc_addr     0x625240 // done

// Patch
#define vmspace_acquire_ref_addr        0x476140 // done
#define vmspace_free_addr               0x475f70 // done
#define vm_map_lock_read_addr           0x4762d0 // done
#define vm_map_unlock_read_addr         0x476320 // done
#define vm_map_lookup_entry_addr        0x476910 // done
#define proc_rwmem_addr                 0x4244a0 // done

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x64117c // done
#define sceSblAuthMgrIsLoadable2_hook                               0x6412ce // done
#define sceSblAuthMgrVerifyHeader_hook1                             0x641a66 // done
#define sceSblAuthMgrVerifyHeader_hook2                             0x642749 // done
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x63e2fd // done
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x63ef38 // done

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x6229b5 // done
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x62682d // done
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x64b880 // done
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x64c64e // done
#define mountpfs__sceSblPfsSetKeys_hook1                            0x6b59f9 // done
#define mountpfs__sceSblPfsSetKeys_hook2                            0x6b5c2a // done

// SceShellUI patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x1cfc0 // done
#define sceSblRcMgrIsStoreMode_patch                                0x1d320 // done

// SceShellUI patches - remote play patches
// #define CreateUserForIDU_patch                                      0x1A8FA0 // bypass
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
// #define pkg_installer_patch             0x9312A1 // bypass

// enable support with 6.xx external hdd
// #define ext_hdd_patch                   0x606b7d // done
// #define ext_hdd_patch1                  0x5e8dcc // unsure
// #define ext_hdd_patch2                  0x26e5c1 // unsure

// enable debug trophies on retail
// #define debug_trophies_patch            0x6ABE39 // bypass

// disable screenshot block
// #define disable_screenshot_patch        0xCB8C6 // bypass

#endif
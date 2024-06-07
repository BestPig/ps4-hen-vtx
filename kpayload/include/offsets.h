#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data
#define	XFAST_SYSCALL_addr              0x00001c0
#define M_TEMP_addr                     0x15415b0
#define MINI_SYSCORE_SELF_BINARY_addr   0x155cc48
#define ALLPROC_addr                    0x22d0a98
#define SBL_DRIVER_MAPPED_PAGES_addr    0x2646688
#define SBL_PFS_SX_addr                 0x264c080
#define SBL_KEYMGR_KEY_SLOTS_addr       0x26606e8
#define SBL_KEYMGR_KEY_RBTREE_addr      0x26606f8
#define SBL_KEYMGR_BUF_VA_addr          0x2664000
#define SBL_KEYMGR_BUF_GVA_addr         0x2664808
#define FPU_CTX_addr                    0x2653280
#define DIPSW_addr                      0x221c5d0

// common
#define memcmp_addr                     0x0948b0
#define _sx_xlock_addr                  0x0e3200
#define _sx_xunlock_addr                0x0e33c0
#define malloc_addr                     0x1a4220
#define free_addr                       0x1a43e0
#define strstr_addr                     0x2c5740
#define fpu_kern_enter_addr             0x0c0660
#define fpu_kern_leave_addr             0x0c0720
#define memcpy_addr                     0x2dddf0
#define memset_addr                     0x0482d0
#define strlen_addr                     0x21dc40
#define printf_addr                     0x2fcbd0
#define eventhandler_register_addr      0x43e440

// Fself
#define sceSblACMgrGetPathId_addr       0x3d0e90
#define sceSblServiceMailbox_addr       0x62f810
#define sceSblAuthMgrSmIsLoadable2_addr 0x642f90
#define _sceSblAuthMgrGetSelfInfo_addr  0x6437d0
#define _sceSblAuthMgrSmStart_addr      0x63e9c0
#define sceSblAuthMgrVerifyHeader_addr  0x640740

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x3c8060
#define Sha256Hmac_addr                 0x2d1ca0
#define AesCbcCfb128Encrypt_addr        0x2deaa0
#define AesCbcCfb128Decrypt_addr        0x2decd0
#define sceSblDriverSendMsg_0_addr      0x61af60
#define sceSblPfsSetKeys_addr           0x61d900
#define sceSblKeymgrSetKeyStorage_addr  0x62edc0
#define sceSblKeymgrSetKeyForPfs_addr   0x625df0
#define sceSblKeymgrCleartKey_addr      0x626130
#define sceSblKeymgrSmCallfunc_addr     0x6259c0

// Patch
#define vmspace_acquire_ref_addr        0x357720
#define vmspace_free_addr               0x357550
#define vm_map_lock_read_addr           0x3578b0
#define vm_map_unlock_read_addr         0x357900
#define vm_map_lookup_entry_addr        0x357ef0
#define proc_rwmem_addr                 0x3838a0

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x63d13c
#define sceSblAuthMgrIsLoadable2_hook                               0x63d28e
#define sceSblAuthMgrVerifyHeader_hook1                             0x63da26
#define sceSblAuthMgrVerifyHeader_hook2                             0x63e709
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x640e0d
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x641a48

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x62ee65
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x626fad
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x64d230
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x64dffe
#define mountpfs__sceSblPfsSetKeys_hook1                            0x6993b9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x6995ea

// SceShellUI patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x01d100
#define sceSblRcMgrIsStoreMode_patch                                0x01d460

// SceShellUI patches - remote play patches
// #define CreateUserForIDU_patch                                      0x1B11D6 // done
// #define remote_play_menu_patch                                      0xEE638E // bypass

// SceRemotePlay patches - remote play patches
// #define SceRemotePlay_patch1                                        0x3C33F // bypass
// #define SceRemotePlay_patch2                                        0x3C35A // bypass

// SceShellCore patches
// call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x16b664
#define sceKernelIsGenuineCEX_patch2    0x86bd24
#define sceKernelIsGenuineCEX_patch3    0x8bc022
#define sceKernelIsGenuineCEX_patch4    0xa1d6c4

// call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x16b692
#define nidf_libSceDipsw_patch2         0x249e0c
#define nidf_libSceDipsw_patch3         0x86bd52
#define nidf_libSceDipsw_patch4         0xa1D6f2

// enable data mount
#define enable_data_mount_patch         0x31f070

// enable fpkg
#define enable_fpkg_patch               0x3d7c9f

// debug pkg free string
#define fake_free_patch                 0xfc8439

// make pkgs installer working with external hdd
#define pkg_installer_patch             0xa06c11

// enable support with 6.xx external hdd
#define ext_hdd_patch                   0x60e17d

// enable debug trophies on retail
// #define debug_trophies_patch            0x6ABE39 // bypass

// disable screenshot block
// #define disable_screenshot_patch        0xCB8C6 // bypass

#endif
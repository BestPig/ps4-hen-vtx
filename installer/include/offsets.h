#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 5.05
#define	XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x111b910
#define ROOTVNODE_addr                  0x1bf81f0
#define PMAP_STORE_addr                 0x1b2cee0
#define DT_HASH_SEGMENT_addr            0x0ce7008
#define M_TEMP_addr                     0x1a5fe30

// Functions
#define pmap_protect_addr               0x046ef0
#define pmap_protect_p_addr             0x046f37
#define malloc_addr                     0x36e120
#define printf_addr                     0x450e80

// Patches
// debug menu error
#define debug_menu_error_patch1         0x4e6da8
#define debug_menu_error_patch2         0x4e7e6e

// disable signature check
#define disable_signature_check_patch   0x6c4c00

// enable debug RIFs
#define enable_debug_rifs_patch1        0x64e930
#define enable_debug_rifs_patch2        0x64e960

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1          0x213088
#define sys_dynlib_dlsym_patch2          0x2dab60

// sdk version spoof - enable all VR fws
// #define sdk_version_patch               0xCE8332 // unsure

// enable debug log
#define enable_debug_log_patch          0x450f67

// enable uart output
// #define enable_uart_patch               0x1a3bca0 // unsure

#endif
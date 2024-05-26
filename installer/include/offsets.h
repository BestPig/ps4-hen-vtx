#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 5.05
#define	XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x111b910 // sus
#define ROOTVNODE_addr                  0x1bf81f0
#define PMAP_STORE_addr                 0x22CB570 // not done yet
#define DT_HASH_SEGMENT_addr            0x0B5EF30 // not done yet

// Functions
#define pmap_protect_addr               0x46ef0 // unsure
#define pmap_protect_p_addr             0x46f37 // unsure

// Patches
// debug menu error
#define debug_menu_error_patch1         0x4e6da6 // unsure
#define debug_menu_error_patch2         0x4eefe8 // unsure

// disable signature check
#define disable_signature_check_patch   0x6c4bfd // unsure

// enable debug RIFs
#define enable_debug_rifs_patch1        0x64e930 // unsure
#define enable_debug_rifs_patch2        0x64e990 // unsure

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch          0x0237F3A // not done yet

// sdk version spoof - enable all VR fws
#define sdk_version_patch               0x14A63F0 // not done yet

// enable debug log
#define enable_debug_log_patch          0x450f73 // unsure

// enable uart output
#define enable_uart_patch               0x1a3bca0 // unsure

#endif
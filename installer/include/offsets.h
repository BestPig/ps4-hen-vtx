#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 5.05
#define	XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x111f830
#define ROOTVNODE_addr                  0x2116640
#define PMAP_STORE_addr                 0x2162a88
#define DT_HASH_SEGMENT_addr            0x0ce9dd8
#define M_TEMP_addr                     0x15415b0

// Functions
#define pmap_protect_addr               0x0116cb0
#define pmap_protect_p_addr             0x0116cf7
#define malloc_addr                     0x01a4220
#define printf_addr                     0x02fcbd0

// Patches
// debug menu error
#define debug_menu_error_patch1         0x04ee328
#define debug_menu_error_patch2         0x04ef3ee

// disable signature check
#define disable_signature_check_patch   0x0684eb0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x064bfd0
#define enable_debug_rifs_patch2        0x064c000

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x01e4ca8
#define sys_dynlib_dlsym_patch2         0x0088ce0

// sdk version spoof - enable all VR fws
// #define sdk_version_patch               0xCE8332 // unsure

// enable debug log
// #define enable_debug_log_patch          0x450f67 // not done

// enable uart output
// #define enable_uart_patch               0x1a3bca0 // unsure

#endif
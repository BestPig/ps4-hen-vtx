#ifndef __DEBUG_H__
#define __DEBUG_H__
#pragma once

#include "libc.h"
#include "network.h"
#include "syscall.h"
#include "types.h"

int debug_sock;

void initDebugSocket(void);
void closeDebugSocket(void);

#ifdef DEBUG_SOCKET
#define printfsocket(format, ...)														\
do {																					\
	char __printfsocket_buffer[512];													\
	int __printfsocket_size = sprintf(__printfsocket_buffer, format, ##__VA_ARGS__);	\
	SckSend(debug_sock, __printfsocket_buffer, __printfsocket_size);					\
} while(0)

#else
#define printfsocket(format, ...) (void)0
#endif

void notify(char *message);

#endif

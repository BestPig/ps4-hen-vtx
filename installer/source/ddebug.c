#include <ps4.h>

#include "defines.h"

#ifdef DEBUG_SOCKET

extern int debug_sock;

void initDebugSocket(void)
{
	struct sockaddr_in server;

	server.sin_len = sizeof(server);
	server.sin_family = AF_INET;
	sceNetInetPton(AF_INET, LOG_IP, &server.sin_addr);
	server.sin_port = sceNetHtons(LOG_PORT);
	memset(server.sin_zero, 0, sizeof(server.sin_zero));
	debug_sock = sceNetSocket("debug", AF_INET, SOCK_DGRAM, 0);
	sceNetConnect(debug_sock, (struct sockaddr *)&server, sizeof(server));

	// int flag = 1;
	// sceNetSetsockopt(sock, SCE_NET_IPPROTO_UDP, TCP_NODELAY, (char *)&flag, sizeof(int));
}

void closeDebugSocket(void) {
	sceNetSocketClose(debug_sock);
}
#endif

void notify(char *message)
{
	char buffer[512];
	sprintf(buffer, "%s", message);
	sceSysUtilSendSystemNotificationWithText(222, buffer);
}

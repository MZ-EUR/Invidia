#include <stdlib.h>
#include <string.h>

char* xorStr(char*message, char*key)
{
	size_t messagelen = strlen(message);
	size_t keylen = strlen(key);

	char * encrypted = (char*)malloc(messagelen + 1);

	int i;
	for (i = 0; i < messagelen; i++) {
		encrypted[i] = message[i] ^ key[i % keylen];
	}
	encrypted[messagelen] = '\0';

	return encrypted;
}
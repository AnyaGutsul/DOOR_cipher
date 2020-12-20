#include "Header.h"


char* iterATT(char* cipherText, int key[2][2])
{
	char* tmpText, * lastText;
	int cnt = 0;

	lastText = (char*)malloc((strlen(cipherText) + 1) * sizeof(char));
	tmpText = door_encryption(cipherText, key);

	while (strcmp(cipherText, tmpText) != 0) {
		strcpy(lastText, tmpText); //for each iteration save the last text
		tmpText = door_encryption(tmpText, key);
		cnt++;
	}

	printf("\nNumber of iterative attack attempts: %d \n", cnt + 1);
	return lastText;
}
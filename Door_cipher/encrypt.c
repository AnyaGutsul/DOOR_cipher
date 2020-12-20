#include "Header.h"

char* door_encryption(char* plaintext, int keyMatrix[2][2]) {

	int vX[2], vResult[2], i, length;
	char* ptext, * ctext;
	int M[2][2];

	length = strlen(plaintext);

	if (length % 2 == 1) {
		ptext = (char*)malloc((length + 2) * sizeof(char));
		strcpy_s(ptext, length + 1, plaintext);
		ptext[length] = 'z';
		ptext[length + 1] = '\0';
		length = strlen(ptext);
	}
	else ptext = plaintext;

	ctext = (char*)malloc((length + 1) * sizeof(char));
	R3(keyMatrix, M);

	for (i = 0; i < length; i = i + 2) {
		vX[0] = charToInt(ptext[i]);
		vX[1] = charToInt(ptext[i + 1]);
		VmulM(vX, M, vResult);
		ctext[i] = intToChar(vResult[0]);
		ctext[i + 1] = intToChar(vResult[1]);
	}
	if (strlen(plaintext) % 2 == 1)
		ctext[i - 1] = '\0';
	else ctext[i] = '\0';

	return ctext;
}
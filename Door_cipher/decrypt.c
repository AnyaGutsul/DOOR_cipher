#include "Header.h"

char* door_decryption(char* ciphertext, int keyMatrix[2][2]) {
	char* ctext, * dtext;
	int M[2][2], invM[2][2];
	int vY[2], vResult[2];
	int length, i;

	length = strlen(ciphertext);

	if (length % 2 == 1) {
		ctext = (char*)malloc((length + 2) * sizeof(char));
		strcpy_s(ctext, length + 1, ciphertext);
		ctext[length] = 'z';
		ctext[length + 1] = '\0';
		length = strlen(ctext);
	}
	else ctext = ciphertext;

	dtext = (char*)malloc((length + 1) * sizeof(char));

	R3(keyMatrix, M);
	invertibleM(M, invM);
	printf("\nThe Invertible matrix is: \n");
	printMatrix(invM);

	for (i = 0; i < length; i = i + 2) {
		vY[0] = charToInt(ctext[i]);
		vY[1] = charToInt(ctext[i + 1]);
		VmulM(vY, invM, vResult);
		dtext[i] = intToChar(vResult[0]);
		dtext[i + 1] = intToChar(vResult[1]);
	}
	if (strlen(ciphertext) % 2 == 1)
		dtext[i - 1] = '\0';
	else dtext[i] = '\0';

	return dtext;
}
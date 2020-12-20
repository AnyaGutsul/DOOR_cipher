#include "Header.h"


void KeyToMatrix(int key[2][2], char* encryptionKey) {
	key[0][0] = charToInt(encryptionKey[0]);
	key[0][1] = charToInt(encryptionKey[1]);
	key[1][0] = charToInt(encryptionKey[2]);
	key[1][1] = charToInt(encryptionKey[3]);
}

int charToInt(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
}

char intToChar(int number) {
	return number + 'a';
}

void printMatrix(int matrix[2][2]) {
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("  %d  ", matrix[i][j]);
		}
		printf("\n");
	}
}

void R3(int keyMatrix[2][2], int finalRes[2][2]) {
	int result2[2][2], result3[2][2];

	MmultM(keyMatrix, keyMatrix, result2); //A^2
	MmultM(result2, keyMatrix, result3);//A^3
	SmultM(2, keyMatrix, result2); //scalar mult key matrix===>2*A
	sumM(result3, result2, finalRes);
}

int modN(int number) {
	number = number % N;
	if (number < 0)
		number = number + N;
	return number;
}

void MmultM(int m1[2][2], int m2[2][2], int result[2][2]) {
	int i, j, k;

	//Initialize to 0
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			result[i][j] = 0;


	for (i = 0; i < 2; ++i)
		for (j = 0; j < 2; ++j)
			for (k = 0; k < 2; ++k)
				result[i][j] += modN(m1[i][k] * m2[k][j]);
}

void SmultM(int scalar, int m[2][2], int result[2][2]) {
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			result[i][j] = modN(scalar * m[i][j]);
}

void sumM(int m1[2][2], int m2[2][2], int result[2][2]) {
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			result[i][j] = modN(m1[i][j] + m2[i][j]);
}

void VmulM(int vX[2], int m[2][2], int vResult[2]) {
	int i, j;

	for (i = 0; i < 2; i++) {
		vResult[i] = 0;
		for (j = 0; j < 2; j++) {
			vResult[i] += vX[j] * m[j][i];
		}
		vResult[i] = modN(vResult[i]);
	}
}

void invertibleM(int M[2][2], int invM[2][2]) { //K^-1=|K|^-1*K^-1
	int mDet;

	mDet = invertibleDet(matrixDet(M));
	invM[0][0] = M[1][1];
	invM[0][1] = modN(-1 * M[0][1]);
	invM[1][0] = modN(-1 * M[1][0]);
	invM[1][1] = M[0][0];

	SmultM(mDet, invM, invM);
}

int matrixDet(int M[2][2]) {
	return modN(M[0][0] * M[1][1] - M[0][1] * M[1][0]);
}

int invertibleDet(int det) {
	int i;

	for (i = 0; i < N; i++) {
		if (modN(det * i) == 1)
			return i;
	}
	return 50; //if gcd(det,N) is not 1, error code 50
}

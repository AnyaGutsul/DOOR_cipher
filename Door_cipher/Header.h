#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26
#define PSIZE 21
#define KSIZE 5



void KeyToMatrix(int key[2][2], char* encryptionKey);
int charToInt(char c);
char intToChar(int number);
void printMatrix(int matrix[2][2]);
char* door_encryption(char* plaintext, int keyMatrix[2][2]);
void R3(int keyMatrix[2][2], int finalRes[2][2]);
int modN(int number);
void MmultM(int m1[2][2], int m2[2][2], int result[2][2]);
void SmultM(int scalar, int m[2][2], int result[2][2]);
void sumM(int m1[2][2], int m2[2][2], int result[2][2]);
void VmulM(int vX[2], int m[2][2], int vResult[2]);
char* door_decryption(char* ciphertext, int keyMatrix[2][2]);
void invertibleM(int keyMatrix[2][2], int invM[2][2]);
int matrixDet(int M[2][2]);
int invertibleDet(int det);
char* iterATT(char* cipherText, int key[2][2]);

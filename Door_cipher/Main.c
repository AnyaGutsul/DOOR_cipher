#include "Header.h"

int main() {

	char plaintext[PSIZE], encryptionKey[KSIZE];
	int  keyMatrix[2][2];
	char* ciphertext, * decryptedtext, * iterativeResult;
	int invDeterminant, Klength = 0;


	while (Klength != KSIZE - 1) {
		printf("\nEnter 4 letters encription key, please: ");
		scanf_s("%s", encryptionKey, KSIZE);
		_flushall();
		Klength = strlen(encryptionKey);

		KeyToMatrix(keyMatrix, encryptionKey);
		invDeterminant = invertibleDet(matrixDet(keyMatrix));

		if (invDeterminant == 50) {
			printf("\nThe key matrix determinant: %d is not invertible modulo %d (gcd is not 1).", matrixDet(keyMatrix), N);
			printf("\nChoose another key please.\n");
			Klength = 0;
		}
	}



	printf("Enter plaintext, please: ");
	scanf_s("%s", plaintext, PSIZE);
	_flushall();

	printf("\nThe key matrix is: \n");
	printMatrix(keyMatrix);


	//Encryption
	printf("\nEncryption:");
	ciphertext = door_encryption(plaintext, keyMatrix);
	printf("\nCiphertext is: %s\n", ciphertext);

	//Decryption
	printf("\nDecryption:");
	decryptedtext = door_decryption(ciphertext, keyMatrix);
	printf("\nDecrypted text is: %s\n", decryptedtext);

	//Iterative attack
	printf("\nIterative attack:");
	iterativeResult = iterATT(ciphertext, keyMatrix);
	printf("Text after iterative attack is: %s\n", iterativeResult);

	getch();
	return 0;
}
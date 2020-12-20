# DOOR_cipher
The symmetric block cipher Door implementation

The symmetric block cipher Door is given as follow: 
Plane space:		X = {0…25}
Cipher space:	Y = {0…25}
Key space values: 	The key is a m * m matrix A whose elements are integers in Z26.
The Encryption function defined by repeated encryption ER(x0) is given by the following way: 
x1 = x0 *A%N,
xR = (xR-1 *A+ xR-2)%N, for each R>=2.
Example: for R=1 the Encryption function is defined by: E1(x0) = x0 *A %N, 
                 for R=2: E2(x0) = (x1 *A+ x0) %N = (x0 * A2 + x0) %N=(x0 * (A2 + I)) %N,
where I is the identical matrix.

The function door_encryption(ptext, key)
is a procedure to encrypt a given plaintext by mean of the cipher Door for m=2 and R=3 with the input parameters: plaintext and encryption key, output: the ciphertext. 

Comment: a plaintext is a string of the length between 2 and 20 characters, a key is a string given by a matrix 2X2. For example: key = "road" = "r, o, a, d" =  17, 14, 0, 3; 
  K	=  	r  o	=	17   14
             a  d		 0     3 
  
The function door_decryption(ctext, key)
is a procedure to decrypt a cipher text for m=2 and R=3 with the input parameters: the ciphertext and encryption key matrix, output: the plaintext. 

The function iterative_attack
is a procedure performing the iterative attack against the algorithm Door with the parameters: m=2, R=3, and decrypting the message.

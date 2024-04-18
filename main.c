#include <stdio.h>
#include <stdlib.h>

#include "rijndael.h"

void print_128bit_block(unsigned char *block) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      unsigned char value = BLOCK_ACCESS(block, i, j);

      // Print spaces before small numbers to ensure that everything is aligned
      // and looks nice
      if (value < 10) printf(" ");

      if (value < 100) printf(" ");

      printf("%d", value);
    }
    printf("\n");
  }
}

int main() {
  	//Electronic Code Book (ECB) mode
	unsigned char message[(BLOCK_SIZE * 2) + 1] = { "I LOVE 2 ENCRYPT WORDS WITH AES" };
	unsigned char key[BLOCK_SIZE+1] = { "YELLOW SUBMARINE" };

  printf("############ ORIGINAL PLAINTEXT ###########\n");
	printf("This message will be encrypted using ECB mode: %s\n", message);

  printf("############ ENCRYPTION KEY ###########\n");
	printf("With this key: %s\n", key);
	aes_ecb_encrypt(message, key, 32);

  printf("############ ENCRYPTED CIPHERTEXT USING ECB ###########\n");
	printf("Here is the encrypted result: %s\n", message);
	aes_ecb_decrypt(message, key, 32);
  
  printf("############ DECRYPTION ###########\n");
	printf("Here is the decrypted message: %s\n\n", message);

	
	//Cipher Block Chaining (CBC) mode, Initilization Vector (IV) required
	memcpy(message, "I LOVE 2 ENCRYPT WORDS WITH CBC!", 32);
	memcpy(key, "HERE IS MY KEY!!", 16);
	unsigned char iv[BLOCK_SIZE+1] = { "HERE IS MY IV!!!" };

  printf("############ ORIGINAL PLAINTEXT ###########\n");
	printf("This message will be encrypted using CBC mode: %s\n", message);

  printf("############ ENCRYPTION KEY ###########\n");
	printf("With this key: %s and this IV: %s\n", key, iv);
	aes_cbc_encrypt(message, key, 32, iv);

  printf("############ ENCRYPTED CIPHERTEXT USING CBC ###########\n");
	printf("Here is the encrypted result: %s\n", message);
	aes_cbc_decrypt(message, key, 32, iv);
  printf("############ DECRYPTION ###########\n");
	printf("Here is the decrypted message: %s\n\n", message);

	return 0;
}

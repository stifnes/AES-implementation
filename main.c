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
  // unsigned char plaintext[16] = {1, 2,  3,  4,  5,  6,  7,  8,
  //                                9, 10, 11, 12, 13, 14, 15, 16};
  // unsigned char key[16] = {50, 20, 46, 86, 67, 9, 70, 27,
  //                          75, 17, 51, 17, 4,  8, 6,  99};

  // unsigned char *ciphertext = aes_ecb_encrypt(plaintext, key, 16);
  // unsigned char *recovered_plaintext = aes_decrypt_block(ciphertext, key);

  // printf("############ ORIGINAL PLAINTEXT ###########\n");
  // print_128bit_block(plaintext);

  // printf("\n\n################ CIPHERTEXT ###############\n");
  // print_128bit_block(ciphertext);

  // printf("\n\n########### RECOVERED PLAINTEXT ###########\n");
  // print_128bit_block(recovered_plaintext);

  // free(ciphertext);
  // free(recovered_plaintext);

  // return 0;

  	//Electronic Code Book (ECB) mode
	unsigned char message[(BLOCK_SIZE * 2) + 1] = { "I LOVE 2 ENCRYPT WORDS WITH AES" };
	unsigned char key[BLOCK_SIZE+1] = { "YELLOW SUBMARINE" };

	printf("This message will be encrypted using ECB mode: %s\n", message);
	printf("With this key: %s\n", key);
	aes_ecb_encrypt(message, key, 32);
	printf("Here is the encrypted result: %s\n", message);
	aes_ecb_decrypt(message, key, 32);
	printf("Here is the decrypted message: %s\n\n", message);

	
	//Cipher Block Chaining (CBC) mode, Initilization Vector (IV) required
	memcpy(message, "I LOVE 2 ENCRYPT WORDS WITH CBC!", 32);
	memcpy(key, "HERE IS MY KEY!!", 16);
	unsigned char iv[BLOCK_SIZE+1] = { "HERE IS MY IV!!!" };

	printf("This message will be encrypted using CBC mode: %s\n", message);
	printf("With this key: %s and this IV: %s\n", key, iv);
	aes_cbc_encrypt(message, key, 32, iv);
	printf("Here is the encrypted result: %s\n", message);
	aes_cbc_decrypt(message, key, 32, iv);
	printf("Here is the decrypted message: %s\n\n", message);

	return 0;
}

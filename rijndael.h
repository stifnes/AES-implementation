#ifndef RIJNDAEL_H
#define RIJNDAEL_H

#define BLOCK_ACCESS(block, row, col) (block[(row * 4) + col]);
#define BLOCK_SIZE 16
#define NUM_ROUNDS 10

/*
 * These should be the main encrypt/decrypt functions (i.e. the main
 * entry point to the library for programmes hoping to use it to
 * encrypt or decrypt data)
 */

//private functions, one block at a time
void AES_decrypt(unsigned char * plain_text, unsigned char * key);
void AES_encrypt(unsigned char * plain_text, unsigned char * key);

//public functions
unsigned char *aes_ecb_encrypt(unsigned char * plain_text, unsigned char* key, int text_length);
unsigned char *aes_ecb_decrypt(unsigned char * plain_text, unsigned char* key, int text_length);
unsigned char *aes_cbc_encrypt(unsigned char * plain_text, unsigned char* key, int text_length, unsigned char * iv);
unsigned char *aes_cbc_decrypt(unsigned char * plain_text, unsigned char* key, int text_length, unsigned char * iv);

#endif

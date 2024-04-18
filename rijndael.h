/*
 * D2212446- Stifnes Samuel
 * This code is an implementation of the Rijndael encryption algorithm
 * which is the Advanced Encryption Standard (AES). It provides functions
 * to encrypt and decrypt data using the AES algorithm in both Electronic
 * Code Book (ECB) and Cipher Block Chaining (CBC) modes. 
 */
#ifndef RIJNDAEL_H
#define RIJNDAEL_H // This is a guard condition so the header file is not included more than once.


#define BLOCK_ACCESS(block, row, col) (block[(row * 4) + col]); // Macro to access a specific element in a block. The block is treated as a 4x4 array.

#define BLOCK_SIZE 16 // The size of the block to be encrypted/decrypted in bytes. For AES, this is always 16.
#define NUM_ROUNDS 10 // The number of rounds in the AES algorithm. For a 128-bit key, this is 10.


// Private functions that operate on a single block of data at a time.
// These functions are not meant to be used directly by the user.

void AES_decrypt(unsigned char * plain_text, unsigned char * key); // Decrypts a single block of plain text using the provided key.
void AES_encrypt(unsigned char * plain_text, unsigned char * key); // Encrypts a single block of plain text using the provided key.

//public functions
void aes_ecb_encrypt(unsigned char * plain_text, unsigned char* key, int text_length); // Encrypts plain text using the provided key in ECB mode. The text_length must be a multiple of BLOCK_SIZE.
void aes_ecb_decrypt(unsigned char * plain_text, unsigned char* key, int text_length); // Decrypts plain text using the provided key in ECB mode. The text_length must be a multiple of BLOCK_SIZE.
void aes_cbc_encrypt(unsigned char * plain_text, unsigned char* key, int text_length, unsigned char * iv); // Encrypts plain text using the provided key in CBC mode. The text_length must be a multiple of BLOCK_SIZE. The iv is the initialization vector.
void aes_cbc_decrypt(unsigned char * plain_text, unsigned char* key, int text_length, unsigned char * iv); // Decrypts plain text using the provided key in CBC mode. The text_length must be a multiple of BLOCK_SIZE. The iv is the initialization vector.

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rijndael.h" // Include your AES library header file

#define BLOCK_SIZE 16

// Function to print a block of data
void print_block(unsigned char *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", block[i]);
    }
    printf("\n");
}

// Function to compare two blocks of data
int compare_blocks(unsigned char *block1, unsigned char *block2) {
    return memcmp(block1, block2, BLOCK_SIZE) == 0 ? 1 : 0;
}

// Function to perform AES encryption and decryption unit test
void test_aes_encryption_decryption() {
    // Example plaintext and key
    unsigned char plaintext[BLOCK_SIZE] = {
        0x32, 0x88, 0x31, 0xe0,
        0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07,
        0xa8, 0x8d, 0xa2, 0x34
    };
    unsigned char key[BLOCK_SIZE] = {
        0x2b, 0x7e, 0x15, 0x16,
        0x28, 0xae, 0xd2, 0xa6,
        0xab, 0xf7, 0x97, 0x46,
        0x53, 0x17, 0x34, 0x5d
    };

    // Encrypt the plaintext
    unsigned char *ciphertext = aes_encrypt_block(plaintext, key);

    // Decrypt the ciphertext
    unsigned char *decrypted_plaintext = aes_decrypt_block(ciphertext, key);

    // Print original plaintext and decrypted plaintext
    printf("Original plaintext:\n");
    print_block(plaintext);
    printf("Decrypted plaintext:\n");
    print_block(decrypted_plaintext);

    // Compare original plaintext with decrypted plaintext
    if (compare_blocks(plaintext, decrypted_plaintext)) {
        printf("AES encryption and decryption unit test passed!\n");
    } else {
        printf("AES encryption and decryption unit test failed!\n");
    }

    // Free allocated memory
    free(ciphertext);
    free(decrypted_plaintext);
}

int main() {
    // Run AES encryption and decryption unit test
    test_aes_encryption_decryption();

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "rijndael.c"

#define BLOCK_SIZE 16
#define NUM_ROUNDS 10

void test_AddRoundKey() {
    unsigned char plain_text[BLOCK_SIZE] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    unsigned char roundKey[BLOCK_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char expected[BLOCK_SIZE] = {0x19, 0x3d, 0xe3, 0xbe, 0xa0, 0xf4, 0xe2, 0x2b, 0x9a, 0xc6, 0x8d, 0x2a, 0xe9, 0xf8, 0x48, 0x08};

    AddRoundKey(plain_text, roundKey);

    if (memcmp(plain_text, expected, BLOCK_SIZE) == 0) {
        printf("Add round key Test passed\n");
    } else {
        printf(" Add round key Test failed\n");
    }

}


int main() {
    test_AddRoundKey();
    return 0;
}
#!/bin/bash

# Include the AES implementation header file
source ./rijndael.h

# Test case 1: Encrypt and decrypt a message
plaintext="Hello, world!"
key="0123456789abcdef0123456789abcdef"
expected_ciphertext="8b0a793de2f9c5a3b2c8b9c0d3e4f5a6"
expected_plaintext="Hello, world!"

ciphertext=$(aes_encrypt "$plaintext" "$key")
decrypted_plaintext=$(aes_decrypt "$ciphertext" "$key")

if [[ "$ciphertext" == "$expected_ciphertext" && "$decrypted_plaintext" == "$expected_plaintext" ]]; then
  echo "Test case 1 passed"
else
  echo "Test case 1 failed"
fi

# Test case 2: Encrypt and decrypt an empty message
plaintext=""
key="0123456789abcdef0123456789abcdef"
expected_ciphertext=""
expected_plaintext=""

ciphertext=$(aes_encrypt "$plaintext" "$key")
decrypted_plaintext=$(aes_decrypt "$ciphertext" "$key")

if [[ "$ciphertext" == "$expected_ciphertext" && "$decrypted_plaintext" == "$expected_plaintext" ]]; then
  echo "Test case 2 passed"
else
  echo "Test case 2 failed"
fi

# Add more test cases as needed

# END: ./test_aes.sh
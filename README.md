# AES-implementation

This project is an implementation of the Advanced Encryption Standard (AES) algorithm. 
It provides a secure and efficient way to encrypt and decrypt data.
It includes functions for encrypting and decrypting messages using
the Electronic Code Book (ECB) and Cipher Block Chaining (CBC) modes.
The code is split into three files: rijndael.h, rijndael.c, and main.c.
This contains the implementation of the encryption and decryption functions. main.c
and all the functions that will be used by the main encryption and decryption functions.

## Languages Used
The project is implemented using the following programming languages:
- Python (Submodule)
- C++

## Folder Structure

The project has the following folder structure:

```
AES-IMPLEMENTATION
│   README.md
│   Dockerfile.txt    
│   rijndael.c
│   rijndeal.h
│   tests.c    
│   unit_tests.c
│   run_tests.sh  // bash script for running unit tests and compilation test on git push 
│   main.c // main file for running the encryption and decryption code
│
└───aes // submodule added for python implementation of AES
│   
│   │  aes.py
│   │  tests.py
│   │  README.md
│
```

## HOW TO RUN 

```
// To test the code run the following code
gcc -o run_tests tests.c rijndael.c -std=c99
// And then the following command
./run_tests

// To only test the unit tests cases run the following code
gcc -o unit_test unit_tests.c
// And then the following command
./unit_test
```

## SUB-MODULES

Python implementation of [boppreh](https://github.com/boppreh/aes/) added as a submodule and used for inspiration.

## REFERENCES

The following book used as reference for the reduction polynomials of addition and multiplication and for mix columns and key expansion functions.

-- Understanding Cryptography: A Textbook for Students and Practitioners by Christof Paar and Jan Pelzl

> [!WARNING]
> This library is for educational usage only. Please, do not use this library to encrypt sensitive data.

-- Developed by Stifnes Samuel
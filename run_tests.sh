# Compile the C test case
gcc -o run_tests tests.c rijndael.c -std=c99
gcc -o unit_test unit_tests.c

# Execute the compiled binary
./unit_test
./run_tests

# Compile the C test case
gcc -o run_tests tests.c rijndael.c -std=c99

# Execute the compiled binary
./run_tests
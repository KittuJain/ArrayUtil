#!bin/bash

file=$1
gcc -c ${file}.c && gcc ${file}.o -o ${file}.exe


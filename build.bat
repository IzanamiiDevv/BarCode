@echo off
gcc -o build/barcode main.c source/*.c -w
cd build
barcode -s Test.bar
cd ./../
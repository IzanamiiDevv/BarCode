@echo off
gcc -o build/barcode main.c -w
cd build
barcode -s Test.bar
cd ./../
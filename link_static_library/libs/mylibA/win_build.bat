@echo off

echo Compiling MyLib A ...
g++ -c mylibA.cpp -o mylibA.o
ar rcs libmylibA.a mylibA.o

echo Compilation and linking successful!
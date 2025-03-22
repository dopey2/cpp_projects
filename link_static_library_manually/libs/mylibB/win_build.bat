@echo off

echo Compiling MyLib B ...
g++ -c mylibB.cpp -o mylibB.o
ar rcs libmylibB.a mylibB.o

echo Compilation and linking successful!
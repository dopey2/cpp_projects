@echo off

echo Compiling main.cpp ...

g++ main.cpp -o main.exe^
  -I../libs/mylibA^
  -I../libs/mylibB^
  -L../libs/mylibA -l:libmylibA.a^
  -L../libs/mylibB -l:libmylibB.a

Rem The -I specify the headers directory
Rem The -L options link the actual library

echo Compilation and linking successful!


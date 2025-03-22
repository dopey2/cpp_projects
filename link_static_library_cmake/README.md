## FOR WINDOWS USERS

## Build using Cmake and MINGW

**1) Install MINGW https://www.mingw-w64.org/**

**2) Install Cmake https://cmake.org/download/**


**3) Generate a make file using the MINGW generator**
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" .. 
```

**4) Build everything**
```bash
mingw32-make
```

**5) Run the executable**
```bash
./build/bin/main.exe
```

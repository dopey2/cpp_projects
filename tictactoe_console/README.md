## FOR WINDOWS USERS



### A) Build using MINGW

**1) Install MINGW https://www.mingw-w64.org/**

**2) Compile the code using the g++ command** 
```bash
g++ src/main.cpp -o build/main
```

**3) Run the executable**
```bash
build/main.exe
```

___
> Repeat step 2 & 3 after code changes


### B) Build using CMake

**1) Make sure you have installed MINGW and that you can build the code using the gcc command as described in section A)**

**2) Install CMake https://cmake.org/download/**

**3) Run the following commands in the root directory**
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles"
```

The command `cmake -G "MinGW Makefiles"` tell cmake to generate a cmakefile for MinGW

**4) In your ./build folder run the following command to compile your code:**
```bash
mingw32-make
```

**5) Run the executable**
```bash
build/GameApp.exe
```

___
> Repeat step 4 & 5 after code changes
# WINDOWS USERS


## Build manualy using Mingw


### 1 - Create a static library from the lib source

**1.1 Create an object file (mylib.o)** 
```bash
g++ -c mylib.cpp -o mylib.o
```
**1.2) Create a static library from the object file**

```bash
ar rcs libmylib.a mylib.o
```

* The `ar` command is an archiver tool used to create static libs
* `libmylib.a` is the static library that should be included in your app.


### 2 - Compile your app

**2.1 Go in ./src**

**2.2 Compile your app. During this process link the lib (libmylib.a) and include the headers**

```bash
g++ main.cpp ../libs/libmylib.a -o main.exe -I../libs
```

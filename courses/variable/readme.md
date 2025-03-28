
## Pointers 

### 1. Initialised variable:
```c++
#include <iostream>

int main () {
    int a = 3;
    std::cout << a << std::endl;
}

// output:
// 3
```

### 2. Uninitialized variable:
```c++
#include <iostream>

int main () {
    int a;
    std::cout << a << std::endl;
}

// output:
// ?? <--- unexpected behaviour
```

>WARNING: Even if the output seem to be 0 sometime, we can't relly on this value. This may changes based on the compiler or the OS

### 3. Copy variable:
```c++
#include <iostream>

int main () {
    int a = 0;
    int b = a;
    a = 1;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

// output:
// 1 <--- a
// 0 <--- b
```



### 4. Pointer to variable:
```c++
#include <iostream>

int main () {
    int a = 0;
    int *b = &a;
    a = 1;
    std::cout << a << std::endl;
    std::cout << *b << std::endl;
}

// output:
// 1 <--- a
// 1 <--- b is a pointer to the memory adress of a
```



## Pointers 

### 1. Pointer initialized as nullptr:
```c++
#include <iostream>

int main () {
  int* ptr1;
  int* ptr2;
  std::string is1And2Equal = ptr1 == ptr2 ? "true": "false";
  std::cout << ptr1 << std::endl;
  std::cout << ptr2 << std::endl;
  std::cout << is1And2Equal << std::endl;
  return 0;
}

// output:
// 0x100000000    <--- unpredictable behaviour, may also depend and the OS
// 0x282525a1a00  <--- unpredictable behaviour, may also depend and the OS
// false
```

### 2 Pointer initialized as nullptr:
```c++
#include <iostream>

int main () {
  int* ptr1 = nullptr;
  int* ptr2 = nullptr;
  std::string is1And2Equal = ptr1 == ptr2 ? "true": "false";
  std::cout << ptr1 << std::endl;
  std::cout << ptr2 << std::endl;
  std::cout << is1And2Equal << std::endl;
  return 0;
}

// output:
// 0
// 0
// true
```
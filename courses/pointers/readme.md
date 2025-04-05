
## Pointers 

### 1. Init a pointer

```c++
#include <iostream>

int main () {
  int val = 3;
  int *ptr1 = &val;

  std::cout << ptr1 << std::endl;
  std::cout << *ptr1 << std::endl;
  return 0;
}

// output:
// 0x36d3dff934 <-- memory adress
// 3
```


### 2. Value reassignment of a pointer

```c++
#include <iostream>

int main () {
  int val = 3;
  int *ptr1 = &val;
  *ptr1 = 5;
  std::cout << ptr1 << std::endl;
  std::cout << *ptr1 << std::endl;
  std::cout << val << std::endl;
  return 0;
}

// output:
// 0xaa24dffc9c <-- memory adress
// 5
// 5

```

### 3. Value reassignment of a pointer of pointer

```c++
#include <iostream>

int main () {
  int val = 3;
  int *ptr1 = &val;
  int *ptr2 = ptr1;
  *ptr2 = 7;
  std::cout << ptr1 << std::endl;
  std::cout << *ptr1 << std::endl;
  std::cout << val << std::endl;
  return 0;
}

// output:
// 0xaa24dffc9c
// 7
// 7
```

### 4. Undefined pointer
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

### 5. Pointer initialized as nullptr:

This is better than having undefined pointers

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

### 6. Heap allocation / Dynamic allocation

> In this example the memory is allocated during the runtime. Heap allocation is slower than stack allocation.

```c++
int main () {
  int *ptr = (int*) malloc(sizeof(int));
  
  std::cout << ptr << std::endl; //  unpredictable memory adress
  std::cout << *ptr << std::endl; // unpredicatable value
  
  *ptr = 7;
  std::cout << *ptr << std::endl; // 7 
}
```
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
// 0xaa24dffc9c
// 5

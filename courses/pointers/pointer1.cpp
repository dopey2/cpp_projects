#include <iostream>

void foo(int *ptr) {
  std::cout << "foo A" << std::endl;
}

void foo(int val) {
  std::cout << "foo B" << std::endl;
}

int main () {
  if (nullptr == NULL && nullptr == 0) {
    std::cout << "Statement true" << std::endl;
  }

  int* ptr_a = nullptr; // better
  int* ptr_b = NULL;    // wrong

  int int_a = 1;
  int int_b = NULL;

  foo(ptr_a);
  foo(ptr_b);
  foo(int_a);
  foo(int_b);
  return 0;
}
#include <iostream>;

int main() {
  int age = 10;
  int* ptr;
  ptr = &age;

  std::cout << &age << std::endl;  // <-- memory address of age
  std::cout << ptr << std::endl;   // <-- memory address of the pointer ptr
  std::cout << *ptr << std::endl;  // <-- value of the pointer ptr
  std::cout << "______" << std::endl;

  *ptr = 20;                       // <-- change the value of the pointer ptr

  std::cout << age << std::endl;
  std::cout << ptr << std::endl;
  return 0;
}
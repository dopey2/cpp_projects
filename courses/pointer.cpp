#include <iostream>;

int main() {
  int age = 10;
  int* ptr;

  bool isPtr_nullptr = ptr == nullptr;
  bool isPtr_NULL = ptr == NULL;
  bool is_nullptr_equal_NULL = nullptr == NULL;


  std::cout << "is ptr nullptr ? " << isPtr_nullptr << std::endl;
  std::cout << "is ptr NULL ? " << isPtr_NULL << std::endl;
  std::cout << "is nullptr equal to NULL ? " << is_nullptr_equal_NULL << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;


  ptr = &age;
  isPtr_nullptr = ptr == nullptr;
  std::cout << "is ptr nullptr ? " << isPtr_nullptr << std::endl;

  std::cout << &age << std::endl;  // <-- memory address of age
  std::cout << ptr << std::endl;   // <-- memory address of the pointer ptr
  std::cout << *ptr << std::endl;  // <-- value of the pointer ptr
  std::cout << "______" << std::endl;

  *ptr = 20;                       // <-- change the value of the pointer ptr

  std::cout << age << std::endl;
  std::cout << ptr << std::endl;
  return 0;
}
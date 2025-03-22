#include <iostream>
#include "mylibA.h"
#include "mylibB.h"

int main() {
  MyLibA::sayHelloFromA();
  MyLibB::sayHelloFromB();
  std::cout << "Hello World!" << std::endl;
  return 0;
}
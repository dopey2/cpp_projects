#include <iostream>

class Base {
  public:
    int* _x; // equals nullptr

    Base() {
      int x = 1;
      this->_x = &x;
    }
};


int main() {
  Base* base = new Base();

  std::cout << *base->_x << std::endl;
  return 0;
}
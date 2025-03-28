#include <iostream>

class Base {
  public:
    virtual void foo() {
      std::cout << "Base::foo" << std::endl;
    }
};

class DerivedA : public Base {
  public:
    void foo() {
      std::cout << "Derived::fooA" << std::endl;
    }
};

class DerivedB : public Base {};



int main() {
  Base* derivedA = new DerivedA();
  Base* derivedB = new DerivedB();
  derivedA->foo();
  derivedB->foo();
  return 0;
}
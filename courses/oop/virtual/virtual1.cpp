#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }

    virtual Base(int x) {
        std::cout << "Base constructor" << std::endl;
    }

};

class Derived : public Base {
  public:
    Derived() {
      std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    std::cout << "A) ______________" << std::endl;
    Base* base = new Base();
    std::cout << "B) ______________" << std::endl;
    Derived* derived = new Derived();
    std::cout << "C) ______________" << std::endl;
    Base* base_derived = new Derived();
    std::cout << std::endl;

    return 0;
}
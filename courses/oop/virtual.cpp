#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }

    void foo() {
        std::cout << "Base.foo" << std::endl;
        this->foo2();
    }

    virtual void foo2() {
        std::cout << "Base.foo 2" << std::endl;
        this->foo3();
    }

    virtual void foo3() {
        std::cout << "Base.foo 3" << std::endl;
    }
};

class Derived : public Base {
  public:
    Derived() {
      std::cout << "Derived constructor" << std::endl;
    }

    void foo() {
        std::cout << "Derived.foo" << std::endl;
        this->foo2();
    }

    void foo2() {
        std::cout << "Derived.foo 2" << std::endl;
        this->foo3();
    }

    void foo3() override {
        std::cout << "Derived.foo 3" << std::endl;
    }
};

void test1() {
    std::cout << "###### test 1" << std::endl;
    std::cout << std::endl;
    Base* base = new Base();
    base->foo();
    std::cout << std::endl;
}

void test2() {
    std::cout << "###### test 2" << std::endl;
    std::cout << std::endl;
    Derived* derived = new Derived();
    derived->foo();
    std::cout << std::endl;
}

void test3() {
    std::cout << "###### test 3" << std::endl;
    std::cout << std::endl;
    Base* baseDerived = new Derived();
    baseDerived->foo();
    std::cout << std::endl;
}


int main() {
    test1();
    test2();
    test3();

    return 0;
}
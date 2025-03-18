#include <iostream>

class Object {
  std::string message;

  public:
    Object() {
         std::cout << "Constructor" << std::endl;
         this->message = "Hello World";
    }

    ~Object() {
        std::cout << "Destructor" << std::endl;
    }

    void foo(const std::string& str) {
        std::cout << "Calling foo with: " << str << std::endl;
    }

    void printMessage() {
        std::cout << this->message << std::endl;
    }

};


void test1() {
    std::cout << std::endl;
    std::cout << "____________ test1 ________________" << std::endl;
    std::cout << std::endl;
    Object object;
    object.foo("test 1");
    object.printMessage();

}

void test2() {
    std::cout << std::endl;
    std::cout << "____________ test2 ________________" << std::endl;
    std::cout << std::endl;
    Object* object;
    object->foo("test 2");

    // this code fails because object is not initialized
    // object->printMessage();
}

void test3() {
    std::cout << std::endl;
    std::cout << "____________ test3 ________________" << std::endl;
    std::cout << std::endl;
    Object* object = new Object();
    object->foo("test 3");
    object->printMessage();

    // must be destroyed manually
    delete object;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
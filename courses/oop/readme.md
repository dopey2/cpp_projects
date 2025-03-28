
## OOP

### 1. Constructor/Destructor

```c++
#include <iostream>

class MyClass {
  public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }
    ~Base() {
        std::cout << "MyClass destructor" << std::endl;
    }
};

int main() {
  MyClass* object = new MyClass();
  MyClass = nullptr;
  return 0;
}

// output:
// MyClass constructor
// MyClass destructor
```

### 2. Inheritance

```c++
#include <iostream>

class Base {
  public:
    void foo() {
      std::cout << "Base::foo" << std::endl;
    }
};


class DerivedDefault : Base {}; // private inheritance by default
class DerivedPrivate : private Base {};
class DerivedPublic : public Base {};


int main() {
  DerivedDefault* derived_default = new DerivedDefault();
  DerivedPrivate* derived_private = new DerivedPrivate();
  DerivedPublic* derived_public = new DerivedPublic();
  derived_default->foo(); // <-- error: does not have access to foo
  derived_private->foo(); // <-- error: does not have access to foo
  derived_public->foo(); //  <-- ok
  return 0;
}
```
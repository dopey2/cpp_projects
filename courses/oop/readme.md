
## OOP

### 1. Constructor/Destructor

```c++
#include <iostream>

class MyClass {
  public:
    MyClass() {
        std::cout << "MyClass constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructor" << std::endl;
    }
};

int main() {
  MyClass* object = new MyClass();
  delete object;  // <-- calls the destructor
  object = nullptr;
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

### 3. Inheritance - Pass arguments to base constructor

```c++
#include <iostream>

class Base {
public:
  Base(int x) {
    std::cout << "Base constructor " << x << std::endl;
  }
};

class Derived : Base {
public:
  Derived(int x) : Base(x) {
    std::cout << "Derived constructor " << x << std::endl;
  }
};



int main() {
  Derived* object = new Derived(3);
  return 0;
}
```

### 4. Inheritance / Overriding function

```c++
#include <iostream>

class Base {
public:
  void foo() {
    std::cout << "Base::foo" << std::endl;
  }
};


class Derived : public Base {
public:
  void foo() {
    std::cout << "Derived::foo" << std::endl;
  }
};


int main() {
  Derived* derived = new Derived();
  derived->foo();

  // liskov substitution example
  Base* base_derived = new Derived();
  base_derived->foo();
  return 0;
}

// output:
// Derived::foo
// Base::foo
```

### 5. Inheritance / Overriding functon and virtual keyword

```c++
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
  derivedA->foo(); // <-- Derived::fooA
  derivedB->foo(); // <-- Base::foo
  return 0;
}
```
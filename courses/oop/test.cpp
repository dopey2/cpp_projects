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
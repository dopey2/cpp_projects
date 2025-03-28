#include <iostream>

int main () {
    int a = 0;
    int *b = &a;
    a = 1;
    std::cout << a << std::endl;
    std::cout << *b << std::endl;
}

// output:
// ?? <--- unexpected behaviour
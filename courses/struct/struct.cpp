#include <iostream>

struct User {
    int id;
    char* name;
};

int main () {
    // the const keyword make the variable and the property deep readonly
    const User user1 = {1, "John"};
    const User user2 = {2, "Will"};

    // error, cannot be reassigned;
    user1.id = 2;
    // error, cannot be reassigned;
    user1.name = "Will";

    // error, cannot be reassigned;
    user1 = user2;
}
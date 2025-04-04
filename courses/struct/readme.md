## Structure

### 1. Defining structure

```c++
#include <iostream>

struct Person {
    int age;
    char* name;
};


int main () {
    Person person;
    person.age = 20;
    person.name = "Will";

    std::cout << "Age " << person.age  << std::endl;
    std::cout << "Name " << person.name  << std::endl;
}

// output
// Age 20
// Name Will

```

### 2. Aggregate initialization

```c++
#include <iostream>

struct Person {
    int age;
    char* name;
};


int main () {
    Person john = {30, "John"};
    std::cout << "Age " << john.age  << std::endl;
    std::cout << "Name " << john.name  << std::endl;
}

// output
// Age 30
// Name John
```

### 3. Aggregate initialization and named parameters

```c++
#include <iostream>

struct Person {
    int age;
    char* name;
};


int main () {
    // parameters order must reflect the declaration order
    Person emma = {.age = 23, .name = "Emma"}; // OK
    Person emma = {.name = "Emma", .age = 23}; // ERROR
}
```


### 4. Constructor initialization

```c++
#include <iostream>

struct Person {
    int age;
    char* name;
};


int main () {
    Person person = Person({20, "Will"});
}

```


### 5. Embed structure

```c++
#include <iostream>

struct Position {
    float x;
    float y;
};

struct Player {
    int life;
    int armor;
    Position position;
};

int main () {
    Player player = {100, 32, {14.7, 87.01}};

    std::cout << "Life " << player.life << std::endl;
    std::cout << "Armor " << player.armor << std::endl;
    std::cout << "X " << player.position.x << std::endl;
    std::cout << "Y " << player.position.y << std::endl;
}

// output
// Life 100
// Armor 32
// X 14.7
// Y 87.01
```

### 6. Structure with const properties

```c++
struct User {
    const int id;
    char* name;
};

int main () {
    User user1 = {1, "John"};
    user1.id = 2; // error, cannot be reassigned;
    user1.name = "Will"; // ok
}
```

### 7. Structure as const variable

```c++
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

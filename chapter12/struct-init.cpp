#include <iostream>

struct Employee {
    int id{};
    int age{};
    // don't add member in the middle of the struct.
    // otherwise, the order of initialization will be changed.
    double wage{};
};

int main() {
    // the order of initialization is the same as the order of declaration.
    Employee joe{1, 32, 60000.0};
    // id = 2, age = 28, wage = 0.0
    Employee max{2, 28};

    // C++20: designated initializers.
    // Braces around scalar initializer (fix available) [-Wbraced-scalar-init]
    // When doing designated initializers of single values using braces, Clang
    // improperly issues warning “braces around scalar initializer”.
    Employee frank{.id{3}, .wage = 50000.0};

    std::cout << "frank.id: " << frank.id << '\n';

    // update multiple members at once.
    joe = {joe.id, 33, joe.wage};
    frank = {.id = frank.id, .age = 30, .wage = frank.wage};

    std::cout << "joe.age: " << joe.age << '\n';
    std::cout << "frank.age: " << frank.age << '\n';
}

#include <iostream>

struct Department {
    int id{};
    int managerId{};
};

struct Employee {
    int id{};
    int age{};
    double wage{};
    Department department{10, 20};
};

int main() {
    Employee joe{14, 32, 24.15, {20, 40}};

    Employee* joePtr{&joe};
    std::cout << "Joe age: " << (*joePtr).age << '\n';  // 32
    // Prefer -> over (*). It's easier to read.
    std::cout << "Joe wage: " << joePtr->wage << '\n';  // 24.15

    std::cout << "Joe department id: " << joePtr->department.id << '\n';  // 20

    return 0;
}

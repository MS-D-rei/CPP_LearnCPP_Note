#include <iostream>

int five() { return 5; }

int main() {
    // constexpr is a way to ensure the variable is a compile-time constant
    // if not, the compiler will give you an error
    constexpr double earthGravity{9.8};

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge{
    //     age};  // Constexpr variable 'myAge' must be initialized by a constant
    //            // expression [constexpr_var_requires_const_init]
}

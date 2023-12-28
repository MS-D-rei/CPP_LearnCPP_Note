#include <iostream>

// type deduction for return type of a function
// It needs function definition before it is used

// Favor explicit return type over auto return type

auto foo();

int main() {
    std::cout << foo() << '\n';
    // => Function 'foo' with deduced return type cannot be used before it is
    // defined

    return 0;
}

auto foo() { return 42; }

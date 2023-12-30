#include <iostream>

// lvalue: an object that occupies some identifiable location in memory
// this is like a box that holds a value.
// rvalue: any object that is not a lvalue
// this is like a value inside the box.

int main() {
    int x{10};
    int y{x};

    std::cout << "x = " << x << '\n';
    std::cout << "x address = " << &x << '\n';  // x address = 0x7ff7b6c594bc
    std::cout << "y = " << y << '\n';
    std::cout << "y address = " << &y << '\n';  // y address = 0x7ff7b6c594b8

    return 0;
}

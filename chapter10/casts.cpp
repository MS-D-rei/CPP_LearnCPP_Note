#include <iostream>

int main() {
    int x{10};
    int y{4};

    double d1 = x / y;  // 2
    // C-style cast should be avoided
    // 1. risk for being misused
    // 2. not easy to find
    double d2{(double)x / y};  // 2.5
    double d3{double(x) / y};  // 2.5

    // C++ introduces static_cast
    // Main advantage is that it provides compile-time type checking
    double d4{static_cast<double>(x) / y};  // 2.5

    std::cout << d1 << '\n';
    std::cout << d2 << '\n';
    std::cout << d3 << '\n';
    std::cout << d4 << '\n';

    return 0;
}

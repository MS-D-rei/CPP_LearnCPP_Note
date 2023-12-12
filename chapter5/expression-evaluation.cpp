#include <iostream>

int getNumber() {
    std::cout << "Enter an integer: ";
    int number{};
    std::cin >> number;

    return number;
}

int main() {
    // The as-if rule says that the compiler can modify a program however it
    // likes in order to produce more optimized code, so long as those
    // modifications do not affect a program’s “observable behavior”.

    // constant expression is a way for compiler to modify a program
    // To be a constant expression,
    // the expression must be known at compile time.
    // and all operators and functions called must support
    // compile-time evaluation.

    int x{3 + 4};
    // if execute this code by n times, without constant expression,
    // the compiler will calculate 3 + 4 every single time
    // But with constant expression,
    // the compiler will replrace 3 + 4 with 7 after first calculation

    // this is a runtime expression
    // becuase our program can't output the value to console at compile time
    std::cout << x << '\n';

    // The ability for C++ to perform compile-time evaluation is one of the most
    // important and evolving areas of modern C++.

    // another optimization opportunity
    // now assign 7 to x and then output x
    // std::cout << 7 << '\n'; is better.
    // because it not waste memeory to store 7 in x
    // modern compiler may do this optimization for you
    // but it is better to do it yourself

    // compile-time constant and runtime constant
    // if initializer is a constant expression, => compile-time constant
    // otherwise, => runtime constant

    const int y{3 + 4};  // compile-time constant
    std::cout << y << '\n';
    // this will be std::cout << 7 << '\n';

    const int z{getNumber()};  // runtime constant
    std::cout << z << '\n';

    return 0;
}

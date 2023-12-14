#include <iostream>

// constexpr function is evaluated at compile time
// if the return value is used where a contant expression is required
// otherwise the compiler is free to evaluate it at compile time or run time

// In C++20, std::is_constant_evaluated() can be used to check if the function
// is evaluated at compile time or run time

#include <type_traits>
// for std::is_constant_evaluated()

// consteval function is evaluated at compile time
// otherwise the compiler will issue an error

// Constexpr/consteval functions are implicitly inline
// To evaluate a constexpr/consteval function at compile time,
// the compiler must be able to see the definition of the function
// at the point where it is called.
// Best practice:
// Constexpr/consteval functions used in a single source file (.cpp) 
// can be defined in the source file above where they are used.
// Constexpr/consteval functions used in multiple source files 
// should be defined in a header file so they can be included into each source file.


constexpr int greater(int a, int b) { return (a > b ? a : b); }

constexpr int greater2(int a, int b) {
    if (std::is_constant_evaluated()) {
        return (a > b ? a : b);
    } else {
        return 0;
    }
}

consteval int greater3(int a, int b) { return (a > b ? a : b); }

// helper function to force compile time evaluation
consteval auto compileTime(auto value) {
    return value;
}

int main() {
    // case1: evaluated at compile time.
    constexpr int g{greater(5, 6)};
    std::cout << g << '\n';

    int x{5};  // not constexpr variable.
    // case2: evaluated at run time.
    std::cout << greater(x, 6) << '\n';

    // case3: may be evaluated at compile time or run time.
    std::cout << greater(5, 6) << '\n';

    std::cout << greater2(6, 7) << '\n';

    std::cout << greater3(7, 8) << '\n';

    // will be evaluated at compile time.
    std::cout << compileTime( greater3(8, 9) ) << '\n';
}

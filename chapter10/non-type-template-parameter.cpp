#include <cassert>
#include <cmath>  // for std::sqrt()
#include <iostream>

// Normal function
// when it is called with a negative argument, it will assert() at runtime.
// it would be better if we could use static_assert() to check the argument at
// compile time.
// However, static_assert() can only be used with constant expressions.
// And function parameters can't be constexpr.
// double getSqrt(double d) {
//     assert(d >= 0.0 && "getSqrt() requires non-negative argument");
//
//     if (d >= 0.0) {
//         return std::sqrt(d);
//     }
//
//     return 0.0;
// }

// This method is not great because there are other ways to solve this problem.
// Template function
// requires C++20 for floating point non-type template parameters.
template <double D>
double getSqrt() {
    static_assert(D >= 0.0, "getSqrt() requires non-negative argument");

    if (D >= 0.0) {
        return std::sqrt(D);
    }

    return 0.0;
}

int main() {
    // std::cout << getSqrt(4.0) << '\n';
    // std::cout << getSqrt(-4.0) << '\n';

    std::cout << getSqrt<4.0>() << '\n';
    std::cout << getSqrt<-4.0>() << '\n';

    return 0;
}

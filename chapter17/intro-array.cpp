#include <array>
#include <iostream>

// why not use dynamic array for everything?
// 1. std::vector is slightly less performant than fixed array.
// 2. std::vector supports constexpr in very limited cases.

// Best Practice:
// Use std::array for constexpr array, std::vector for non-constexpr array.
// Define a array as constexpr whenever possible. if not, use std::vector.

namespace RGB {
enum Names { red, green, blue, max_colors };
}

int main() {
    // `std::array` size should be constexpr.
    // 1. literal type
    // 2. constexpr variable
    // 3. unscoped enumeration
    // `std::array` uses aggregate initialization.
    // it means that array doesn't have constructor.
    constexpr std::array<int, 8> primes{2, 3, 5, 7, 11, 13, 17, 19};

    // `std::array` has `size()` member function.
    // it returns constexpr std::size_t.
    constexpr int primesSize = primes.size();
    std::cout << "size: " << primesSize << '\n';

    std::array<int, RGB::max_colors> rgb{};
    rgb[RGB::red] = 255;
    rgb[RGB::green] = 160;
    rgb[RGB::blue] = 0;

    // `std::get` does complie-time bound check.
    std::cout << "red: " << std::get<RGB::red>(rgb) << '\n';
    std::cout << std::get<1>(primes) << '\n';
    // compile error
    // In template: static assertion failed due to requirement '9UL < 8UL':
    // Index out of bounds in std::get<> (const std::array)
    // [static_assert_requirement_failed]
    // std::cout << std::get<9>(primes) << '\n';

    return 0;
}

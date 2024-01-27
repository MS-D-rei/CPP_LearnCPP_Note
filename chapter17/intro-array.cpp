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
    std::cout << "size: " << primes.size() << '\n';

    std::array<int, RGB::max_colors> rgb{};
    rgb[RGB::red] = 255;
    rgb[RGB::green] = 160;
    rgb[RGB::blue] = 0;

    return 0;
}

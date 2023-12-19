#include <iostream>

#include "constants.h"

// global const internal variable
// are copied into every file that includes the header file.

// so, global const internal variable has 2 downsides:
// 1. Changing a single constant value would require recompiling every file that
// includes the constants header, which can lead to lengthy rebuild times for
// larger projects.
// 2. If the constants are large in size and can’t be optimized away, this can
// use a lot of memory.

// => refer to global const external

// As a conclusion, prefer global const INTERNAL variable than EXTERNAL.
// global const inline variable is the best.(C++17 and above)

int main() {
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2.0 * radius * Constants::pi
              << '\n';

    return 0;
}

#include <iostream>

#include "constants.h"

// global const external variables
// will be instantiated only once in constants.cpp.
// After any changes to constants.cpp, we need to recompile only constants.cpp.

// global const external variables downside:
// these constants are not compile-time constants in files which use the
// constants except for constants.cpp.
// 1. Outside of constants.cpp, these constants can not be used anywhere that
// requires a compile-time constant.
// 2. Due to not compile-time constants, the compiler can not optimize the code
// as much.

// As a conclusion, global const external variables should be used only when
// necessary.

int main() {
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2.0 * radius * Constants::pi
              << '\n';

    return 0;
}

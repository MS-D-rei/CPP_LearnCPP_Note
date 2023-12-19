#include <iostream>

#include "constants.h"

// Global const inline variables.
// This is a C++17 feature.
// This enable to avoid the downside of duplicated variables.
// This means that these variables are instantiated only once and
// shared across all translation units which use them.

// Warning:
// constexpr functions are implicitly inline.
// constexpr variables are NOT implicitly inline.

int main() {
    std::cout << "Enter a radius: ";
    double radius;
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * Constants::pi << '\n';

    return 0;
}

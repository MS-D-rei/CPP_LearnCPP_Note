#include <iostream>

// C++17
// constexpr if requires a constant expression as its condition.
// The condition is checked at compile time.
// And the entire if-else will be replaced by the true branch or the false
// branch.

int main() {
    constexpr double gravity{9.8};

    // The following code will be replaced by
    // std::cout << "gravity is 9.8\n";
    if constexpr (gravity == 9.8) {
        std::cout << "gravity is 9.8\n";
    } else {
        std::cout << "we are not on earth\n";
    }

    return 0;
}

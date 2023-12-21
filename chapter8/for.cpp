#include <cstdint>
#include <iostream>

std::int64_t calculatePower(std::int64_t base, std::int64_t exponent) {
    std::int64_t total{1};
    for (int i{0}; i < exponent; ++i) {
        total *= base;
    }
    return total;
}

int main() {
    std::cout << calculatePower(7, 4) << '\n';

    return 0;
}

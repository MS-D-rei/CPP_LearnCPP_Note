#include <cassert> // for assert()
#include <cmath>
#include <cstdint> // for std::int64_t
#include <iostream>

bool isOdd(int x) {
    // if we use remainder operator,
    // better to use against 0, not 1 or 2.
    // Because if first operand is negative, result is negative.
    return (x % 2) != 0;
}

constexpr std::int64_t powint(std::int64_t base, int exp) {
    assert(exp >= 0 && "powint: exp has negative number. it must be positive");

    // handle 0 case.
    if (base == 0) {
        return (exp == 0) ? 1 : 0;
    }

    std::int64_t result{1};
    while (exp > 0) {
        // if exp is odd number, multiply base to result.
        if (exp & 1) {
            result *= base;
        }
        exp /= 2;
        base *= base;
    }

    return result;
}

int main() {
    // Due to rounding errors in floating point numbers,
    // the results of pow() may not be precise.
    const double x{std::pow(7.0, 12.0)};
    std::cout << x << '\n';

    // if we want to use integer exponentiation,
    // use own function like powint().
    // In the vast majority of cases, integer exponentiation will overflow
    // the integral type.
    // This is likely why such a function wasn’t included in the standard
    // library in the first place.
    std::cout << powint(7, 12) << '\n';
}

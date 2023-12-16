#include <algorithm>  // for std::max()
#include <cmath>      // for std::abs()
#include <iostream>

template <typename T>
constexpr T constAbs(T x) {
    return (x < 0) ? -x : x;
}

// return true if the difference between a and b is within epsilon percent of
// the larger of a and b
// This function will not work if a and b are both (largest) close to zero.
bool approximatelyEqualRel(double a, double b, double relEpsilon) {
    // calculate the difference.
    double diff{std::abs(a - b)};
    // find the largest.
    double largest{std::max(std::abs(a), std::abs(b))};

    return diff <= (largest * relEpsilon);
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon,
                              double relEpsilon) {
    // check if the numbers are really close
    // -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon) {
        return true;
    }

    return approximatelyEqualRel(a, b, relEpsilon);
}

constexpr bool approximatelyEqualRelConstexpr(double a, double b,
                                              double relEpsilon) {
    double diff{constAbs(a - b)};
    double largest{std::max(constAbs(a), constAbs(b))};
    return diff <= (largest * relEpsilon);
}

constexpr bool approximatelyEqualAbsRelConstexpr(double a, double b,
                                                 double absEpsilon,
                                                 double relEpsilon) {
    if (constAbs(a - b) <= absEpsilon) {
        return true;
    }
    return approximatelyEqualRelConstexpr(a, b, relEpsilon);
}

int main() {
    // a is really close to 1.0, but has rounding errors
    constexpr double a{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 +
                       0.1};

    constexpr double relEpsilon{1e-8};   // or 0.00000001
    constexpr double absEpsilon{1e-12};  // or 0.000000000001

    // a is close enough to 1.0 that it should equal 1.0
    std::cout << approximatelyEqualRel(a, 1.0, relEpsilon) << '\n';  // return 1

    // a-1 is close enough to 0.0 that it should equal 0.0. But...return 0
    std::cout << approximatelyEqualRel(a - 1, 0.0, relEpsilon)
              << '\n';  // return 0

    std::cout << approximatelyEqualAbsRel(a, 1.0, absEpsilon, relEpsilon)
              << '\n';  // return 1
    std::cout << approximatelyEqualAbsRel(a - 1, 0.0, absEpsilon, relEpsilon)
              << '\n';  // return 1

    std::cout << approximatelyEqualRelConstexpr(a - 1, 0.0, relEpsilon)
              << '\n';  // return 0
    std::cout << approximatelyEqualAbsRelConstexpr(a - 1, 0.0, absEpsilon,
                                                   relEpsilon)
              << '\n';  // return 1
}

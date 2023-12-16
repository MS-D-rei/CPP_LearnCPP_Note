#include <iostream>

int main() {
    constexpr int x{7};
    constexpr int y{4};

    std::cout << "int/int = " << x / y << '\n';
    std::cout << "double/int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int/double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double/double = "
              << static_cast<double>(x) / static_cast<double>(y) << '\n';

    std::cout << "Enter x number which divide 12: ";
    double divideNumber{};
    std::cin >> divideNumber;
    std::cout << "12 / " << divideNumber << " = " << 12 / divideNumber << '\n';
    // divided by 0 => error.
    // divided by 0.0 => inf or Nan. depends on architecture.

    return 0;
}

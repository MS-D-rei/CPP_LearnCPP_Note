#include <iomanip>
#include <iostream>

int main() {
    // floating point literals needs at least one decimal place like 3.0

    // f suffix for float
    float f{3.14159f};
    // no suffix for double
    double d{3.14159};
    // l suffix for long double
    long double ld{3.14159l};

    std::cout << "float: " << f << "\n";
    std::cout << "double: " << d << "\n";
    std::cout << "long double: " << ld << "\n";

    // floating point precision

    // 6 decimal places is the default precision for floats
    // 6 - 9 digits of precision for floats
    // (only 6 shown below)
    std::cout << 9.87654321f << "\n";       // 9.87654
    std::cout << 987.654321f << "\n";       // 987.654
    std::cout << 987654.321f << "\n";       // 987654
    std::cout << 9876543.21f << "\n";       // 9.87654e+06
    std::cout << 0.0000987654321f << "\n";  // 9.87654e-05

    // 15 decimal places is the default precision for doubles
    // 15 - 18 digits of precision for doubles

    int precision{17};
    std::cout << std::setprecision(precision);
    std::cout << 3.33333333333333333333333333333333333333f
              << '\n';  // 3.3333332538604736
    std::cout << 3.33333333333333333333333333333333333333
              << '\n';                 // 3.3333333333333335
    std::cout << 9.87654321f << "\n";  // 9.8765430450439453
    std::cout << 9.87654321 << "\n";   // 9.8765432099999995

    // Rounding errors
    // 0.1 cannot be represented exactly in binary
    double d1{0.1};
    std::cout << d1 << '\n';  // 0.1 if not set precision 17
    // 0.1 cannot be represented exactly in binary
    // the value is stored as
    // 0.1000000000000000055511151231257827021181583404541015625
    double d5{0.5};
    std::cout << d5 << '\n';  // 0.5

    return 0;
}

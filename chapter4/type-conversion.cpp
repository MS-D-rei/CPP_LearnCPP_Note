#include <cstdint>
#include <iostream>

void print(int x) { std::cout << x << '\n'; }

int main() {
    // implicit conversion
    // print(5.5); // error: cannot convert ‘double’ to ‘int’ in argument.

    //  explicit conversion
    print(static_cast<int>(5.5));

    std::int8_t myint{65};
    std::cout << myint << '\n';  // prints 65 or A. It depends on system.
    std::cout << static_cast<int>(myint) << '\n';  // prints 65

    return 0;
}

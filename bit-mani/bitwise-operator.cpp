#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> x(0b0000'1100);

    std::cout << "x = " << x << '\n';
    std::cout << "x << 1 = " << (x << 1) << '\n';
    std::cout << "x >> 1 = " << (x >> 1) << '\n';

    // bitwise NOT
    std::cout << "~x = " << ~x << '\n';

    // bitwise OR
    std::bitset<8> y(0b0011'0110);
    std::cout << "y = " << y << '\n';
    std::cout << "x | y = " << (x | y) << '\n';

    // bitwise AND
    std::cout << "x & y = " << (x & y) << '\n';

    // bitwise XOR
    std::cout << "x ^ y = " << (x ^ y) << '\n';

    return 0;
}

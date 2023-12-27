#include <iostream>

// Integral promotion rules:
// 1. signed char or signed short can be converted to int.
// 2. unsigned char, char8_t, and unsigned short can be converted to int if int
// can hold the entire range of the type, or unsigned int otherwise.
// 3. If char is signed by default, it follows the signed char conversion
// rules above. If it is unsigned by default, it follows the unsigned
// char conversion rules above.
// 4. bool can be converted to int, with false becoming 0 and true becoming 1.

void printInt(int i) { std::cout << i << '\n'; }

int main() {
    printInt(2);

    short s{3};
    printInt(s);  // short is promoted to int

    printInt('a');   // char to int
    printInt(true);  // bool to int
}

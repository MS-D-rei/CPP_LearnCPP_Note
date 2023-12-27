#include <iostream>

void printDouble(double d) { std::cout << d << '\n'; }

int main() {
    printDouble(5.0);   // exact match
    printDouble(4.0f);  // numeric promotion of float to double
}

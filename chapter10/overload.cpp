#include <iostream>

// overload function
// 1. differentiation
//  - number of parameters
//  - type of parameters
//   const qualifier is not considered as a differentiation
// 2. resolution

int add(int a, int b) { return a + b; }

double add(double a, double b) { return a + b; }

int main() {
    std::cout << add(1, 2) << '\n';
    std::cout << add(1.2, 2.3) << '\n';
    std::cout << add('a', 'b') << '\n';  // numeric promotion

    return 0;
}

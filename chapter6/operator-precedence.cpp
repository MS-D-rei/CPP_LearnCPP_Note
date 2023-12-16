#include <iostream>

int getValue() {
    int x{};
    std::cin >> x;
    return x;
}

int main() {
    // the order of evaluation of the operands of an operator is unspecified
    // if input 1,2,3, the output is expected 7, but it is not guaranteed
    std::cout << getValue() + (getValue() * getValue()) << '\n';

    // to guarantee the order of evaluation, use separate statements
    int x{getValue()};
    int y{getValue()};
    int z{getValue()};
    std::cout << x + (y * z) << '\n';

    return 0;
}

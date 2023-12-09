#include <ios>
#include <iostream>

int main() {
    bool bFalse{0};
    bool bTrue{1};

    std::cout << "bFalse: " << bFalse << "\n"; // bFalse: 0
    std::cout << "bTrue: " << bTrue << "\n"; // bTrue: 1

    std::cout << std::boolalpha;

    std::cout << "bFalse: " << bFalse << "\n"; // bFalse: false
    std::cout << "bTrue: " << bTrue << "\n"; // bTrue: true

    return 0;
}

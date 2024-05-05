#include <iostream>

// generic lambda with static variable.
// global and static variables can cause problems easily.

int main() {
    // These static variable are not shared between generated lambdas.
    auto print{[](auto value) {
        static int callCount{0};
        std::cout << callCount++ << ": " << value << '\n';
    }};

    // string literal.
    print("apple");   // 0: apple
    print("banana");  // 1: banana

    // integer.
    print(42);  // 0: 42
    print(50);  // 1: 50

    print("walnut");  // 2: walnut

    return 0;
}

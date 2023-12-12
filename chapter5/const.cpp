#include <iostream>

// const function parameters
// make parameters const if you don't want to change them
// However, in modern C++, it is better not use const function parameters
// because parameters are just copies and they will be destroyed
// after the function call.
void showSum(const int x, const int y) {
    // x = 10; // error: assignment of read-only parameter 'x'
    std::cout << x + y << '\n';
}

const int getInt5() { return 5; }

int main() {
    // can put const before or after the type
    // const type is preferred
    const double gravity{9.8};

    int const x{5};
    // gravity = 10.0; // error: assignment of read-only variable 'gravity'
    std::cout << "Gravity is " << gravity << '\n';
    std::cout << "x is " << x << '\n';

    // naimg convention
    // from C language => all caps with underscores like EARTH_GRAVITY
    // However, because const variables act like normal variables.
    // So there is no reason to use special naming convention for them.
    // => use normal variable naming convention like earthGravity

    // const function parameters
    showSum(5, 6);

    // const return values
    // don't use const return values
    // because return values are just copies and they will be destroyed
    // after the function call.
    std::cout << getInt5() << '\n';

    return 0;
}

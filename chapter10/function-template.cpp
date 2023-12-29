#include <iostream>

// function template
// function template is only instantiated when it is called
// in each translation unit.

template <typename T>
T max(T x, T y) {
    return (x < y) ? y : x;
}

int main() {
    // max<int> is instantiated providing int as actual type.
    std::cout << max<int>(1, 4) << '\n';
    // template argument deduction.
    std::cout << max(1, 2) << '\n';
    std::cout << max(1.2, 2.3) << '\n';

    // The difference between angle brackets and no angle brackets.
    // - max<> will consider only max<int> as function overloads.
    // - max will consider max<int> and max non-template function as function
    // overloads.
    std::cout << max<>(1, 2) << '\n';

    // In most cases, favor the no angle brackets version.
    // 1. If we do have a matching non-template function and a matching function
    // template, we will usually prefer the non-template function to be called.
    // 2. more concise
    // 3. It's rare that both a matching non-template function and function
    // template.

    return 0;
}

#include <functional>
#include <iostream>

// Best practice:
// If C++20 is capable, use `auto` as a parameter type.
// Otherwise, use function template or std::function.

// Case 1: std::function as a parameter.
// Good: parameters and return type are clear.
// can separate the declaration and definition.
// Bad: requires the lambda to be implicity converted whenever it is called.
void repeat1(int repetitions, const std::function<void(int)>& fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
    std::cout << '\n';
}

// Case 2: Function template with a type template parameter.
// Good: T matches the actual type of the lambda.
// Bad: parameters and return type are not clear.
template <typename T>
void repeat2(int repetitions, const T& fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
    std::cout << '\n';
}

// Case 3: Abbreviated function template.(C++20)
// Same as case 2, but with auto.
void repeat3(int repetitions, const auto& fn) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
    std::cout << '\n';
}

// Case 4: Function pointer as a parameter.
// Only works with no captures.
// Lambda with no captures is implicitly converted to a function pointer.
void repeat4(int repetitions, void (*fn)(int)) {
    for (int i{0}; i < repetitions; ++i) {
        fn(i);
    }
    std::cout << '\n';
}

int main() {
    auto lambda{[](int i) { std::cout << i; }};

    repeat1(3, lambda);
    repeat2(3, lambda);
    repeat3(3, lambda);
    repeat4(3, lambda);

    return 0;
}

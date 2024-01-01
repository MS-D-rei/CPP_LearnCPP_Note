#include <iostream>
#include <string>

// Pass by reference when you can, pass by address when you must

template <typename T>
void printByValue(T value) {
    std::cout << "printByValue: " << value << '\n';
}

template <typename T>
void printByReference(const T& ref) {
    std::cout << "printByReference: " << ref << '\n';
}

template <typename T>
void printByPointer(const T* ptr) {
    std::cout << "printByPointer: " << *ptr << '\n';
}

int main() {
    std::string str{"Hello, World!"};
    printByValue(str);      // make a copy
    printByReference(str);  // no copy
    printByPointer(&str);   // no copy

    const int x{5};
    printByValue(x);      // make a copy
    printByReference(x);  // no copy
    printByPointer(&x);   // no copy

    return 0;
}

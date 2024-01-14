#include <iostream>
#include <string>

// Pass by reference when you can, pass by address when you must

template <typename T>
void printByValue(T value) {
    std::cout << "printByValue: " << value << '\n';
}

template <typename T>
void printByReference(T& ref) {
    std::cout << "printByReference: " << ref << '\n';
}

template <typename T>
void printByConstReference(const T& ref) {
    std::cout << "printByReference: " << ref << '\n';
}

template <typename T>
void printByConstPointer(const T* ptr) {
    std::cout << "printByPointer: " << *ptr << '\n';
}

void nullifyPtr(int* ptr) { ptr = nullptr; }

void nullifyPtrRef(int*& ptr) { ptr = nullptr; }

int main() {
    std::string str{"Hello, World!"};
    printByValue(str);           // make a copy
    printByConstReference(str);  // no copy
    printByConstPointer(&str);   // no copy

    const int x{5};
    printByValue(x);           // make a copy
    printByConstReference(x);  // no copy
    printByConstPointer(&x);   // no copy

    int y{7};
    int* ptr{&y};
    nullifyPtr(ptr);
    std::cout << "ptr = " << ptr
              << '\n';  // still points to y. because received a copy of ptr.
    nullifyPtrRef(ptr);
    std::cout << "ptr = " << ptr << '\n';  // now points to nullptr.

    // printByReference(5);  // error: cannot bind non-const lvalue reference of
    //                       // type ‘int&’ to an rvalue of type ‘int’
    printByConstReference(5);  // ok

    return 0;
}

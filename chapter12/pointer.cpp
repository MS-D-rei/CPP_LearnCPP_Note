#include <iostream>

int main() {
    int x{5};
    std::cout << "x = " << x << '\n';
    std::cout << "&x = " << &x << '\n';
    std::cout << "*&x = " << *(&x) << '\n';  // parentheses are optional

    int* ptr{&x};
    std::cout << "ptr = " << ptr << '\n';
    // dereferencing a pointer to get the value it points to
    std::cout << "*ptr = " << *ptr << '\n';

    int y{7};
    ptr = &y;
    std::cout << "ptr = " << ptr << '\n';
    *ptr = 8;
    std::cout << "y = " << y << '\n';

    // the type & returns is a pointer
    std::cout << "typeid(&x).name() = " << typeid(&x).name() << '\n';    // "Pi"
    std::cout << "typeid(ptr).name() = " << typeid(ptr).name() << '\n';  // "Pi"

    std::cout << "sizeof(&x) = " << sizeof(&x) << '\n';    // 8.
    std::cout << "sizeof(ptr) = " << sizeof(ptr) << '\n';  // 8.

    // null pointer.
    int* ptrNull{nullptr};
    std::cout << "ptrNull = " << ptrNull << '\n';  // 0.

    // pointer to const value.
    const int cx{12};
    const int* ptrConst{&cx};
    std::cout << "ptrConst = " << ptrConst << '\n';
    std::cout << "*ptrConst = " << *ptrConst << '\n';
    ptrConst = &y;  // const pointer can be reassigned.
    // can't change the value through a const pointer.
    // *ptrConst = 14; // error: assignment of read-only location '* ptrConst'.
    ptrConst = &cx;

    // const pointer.
    int* const constPtr{&x};
    *constPtr = 6;  // can change the value through a const pointer.
    // can't reassign a const pointer.
    // constPtr = &y; // error: assignment of read-only variable 'constPtr'.

    // const pointer to const value.
    [[maybe_unused]] const int* const constPtrConst{&cx};
    // can't change the value through a const pointer to const value.
    // can't reassign a const pointer to const value.

    return 0;
}

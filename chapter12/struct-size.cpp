#include <iostream>

// padding
// The CPU in modern computer hardware performs reads and writes to memory most
// efficiently when the data is naturally aligned, which generally means that
// the data's memory address is a multiple of the data size.
// In the Foo below, the compiler will add 2 bytes of padding after the first
// short to ensure that the int is aligned on a 4-byte boundary.

struct Foo {
    short a{0};  // add 2 bytes of padding to treat as 4 bytes
    int b{0};    // 4
    short c{0};  // add 2 bytes of padding to treat as 4 bytes
};

struct Bar {
    int a{0};    // 4
    short b{0};  // 2
    short c{0};  // 2
};

int main() {
    std::cout << "sizeof(Foo) = " << sizeof(Foo) << '\n';  // 12
    std::cout << "sizeof(Bar) = " << sizeof(Bar) << '\n';  // 8

    return 0;
}

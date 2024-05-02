// Best practice:
// Should use constexpr std::string_view
// instead of C-style string symbolic constants.

#include <iostream>

int main() {
    // These 2 C-style string end up with same result,
    // but C++ deals with the memory allocation for these
    // slightly differently.

    // case 1:
    // "Alex" is put into (probably read-only) memory somewhere.
    // And the program allocate memory for this array of length 5
    // to `name`. Because `name` is const.
    // As a result, we will get 2 copies of "Alex" like std::string.
    const char name[]{"Alex"};

    // case 2:
    // "Orange" is put into (probably read-only) memory somewhere.
    // And then initialize the pointer.
    // As a result, we will get 1 string and 1 pointer.
    // Memory efficient like std::string_view.
    const char* const color{"Orange"};

    std::cout << name << " " << color << '\n';

    return 0;
}

#include <iostream>

int g_x{12};  // global variable

int main() {
    int x{10};
    // reference: an alias to modifiable lvalue
    int& ref1{x};

    const int cx{20};
    // const reference: an alias to non-modifiable(const) lvalue
    const int& ref2{cx};

    const int& ref3{x};
    // ref3 = 100;  // error: can't modify x through const reference

    // constexpr lvlaue reference.
    // Constexpr references have a particular limitation: they can only be bound
    // to objects with static duration (either globals or static locals)
    // This is because the compiler knows where static objects will be
    // instantiated in memory, so it can treat that address as a compile-time
    // constant.

    [[maybe_unused]] constexpr int& ref4{g_x};

    static int s_x{30};
    [[maybe_unused]] constexpr int& ref5{s_x};

    // complie error: constexpr reference to non-static object 'x'
    // [[maybe_unused]] constexpr int& ref6{x};

    // constexpr reference to const static variable.
    // need to apply both constexpr and const to the variable.
    static const int s_cx{40};
    [[maybe_unused]] constexpr const int& ref7{s_cx};
}

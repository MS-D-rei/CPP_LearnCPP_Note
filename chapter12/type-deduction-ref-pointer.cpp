#include <iostream>

const int& getConstIntRef() {
    static int num{10};
    return num;
}

int main() {
    // auto drops the reference, and then const.

    // in this case, auto will be int.
    auto ref1{getConstIntRef()};
    std::cout << "ref1 = " << ref1 << '\n';
    std::cout << "ref1 type = " << typeid(ref1).name() << '\n';

    // in this case, auto drops reference, then const.
    // after that, reapply const.
    // auto will be const int.
    const auto ref2{getConstIntRef()};
    std::cout << "ref2 = " << ref2 << '\n';
    std::cout << "ref2 type = " << typeid(ref2).name() << '\n';

    // in this case, auto drops reference.
    // reapply reference before dropping const.
    // auto will be const int&.
    auto& ref3{getConstIntRef()};
    std::cout << "ref3 = " << ref3 << '\n';
    std::cout << "ref3 type = " << typeid(ref3).name() << '\n';

    // in this case auto drops reference.
    // reapply reference before dropping const.
    // so, reapplying const is not necessary.
    // However, it makes the code more clear.
    // auto will be const int&.
    const auto& ref4{getConstIntRef()};
    std::cout << "ref4 = " << ref4 << '\n';
    std::cout << "ref4 type = " << typeid(ref4).name() << '\n';

    // auto for pointer.

    std::string str{"Hello"};
    const std::string* const ptr{&str};

    auto ptr1{ptr};   // const std::string*.
    auto* ptr2{ptr};  // const std::string*.

    auto const ptr3{ptr};  // const std::string* const.
    const auto ptr4{ptr};  // const std::string* const.

    auto* const ptr5{ptr};  // const std::string* const.
    const auto* ptr6{ptr};  // const std::string*.

    const auto const ptr7{ptr};   // Warning: duplicate 'const' declaration
                                  // specifier [-Wduplicate-decl-specifier]
    const auto* const ptr8{ptr};  // const std::string* const.

    return 0;
}

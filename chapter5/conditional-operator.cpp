#include <iostream>

int main() {
    constexpr bool isBigClassroom{true};
    constexpr int classSize{isBigClassroom ? 30 : 20};

    // The following code will not compile:
    // because the value in if statement will be destroyed
    // after the if statement
    // if (isBigClassroom) {
    //     constexpr int classSize{30};
    // } else {
    //     constexpr int classSize{20};
    // }

    std::cout << "classSize: " << classSize << '\n';

    // To comply with C++’s type checking rules,
    // one of the following must be true:
    // 1. The type of the second and third operand must match.
    // 2. The compiler must be able to find a way to convert one or both of the
    // second and third operands to matching types.

    constexpr int x{10};
    // Incompatible operand types ('const char *' and 'int')
    // [typecheck_cond_incompatible_operands] std::cout << ( x == 10 ? "x is 10"
    // : x ) << '\n';
}

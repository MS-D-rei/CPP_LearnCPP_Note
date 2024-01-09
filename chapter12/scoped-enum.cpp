#include <iostream>

// Favor scoped enumerations over unscoped enumerations unless there’s a
// compelling reason to do otherwise.

namespace Color {
enum nonscopedColor { red, yellow, green };
}  // namespace Color.

enum class scopedColor { red, yellow, green };

namespace Fruit {
enum nonscopedFruit { apple, orange, pear };
}  // namespace Fruit.

enum class scopedFruit { apple, orange, pear };

int main() {
    // nonscoped enum can be compared with other nonscoped enum.
    Color::nonscopedColor nsColor{Color::nonscopedColor::red};
    Fruit::nonscopedFruit nsFruit{Fruit::nonscopedFruit::apple};

    // Warning:
    // Comparison of different enumeration types ('Color::nonscopedColor' and
    // 'Fruit::nonscopedFruit') [-Wenum-compare].
    if (nsColor == nsFruit) {
        std::cout
            << "nsColor and nsFruit are equal but semantically meaningless"
            << '\n';
    } else {
        std::cout << "nsColor and nsFruit are not equal" << '\n';
    }

    // scoped enum cannot be compared with other scoped enum.
    // scoped enum has 2 differences from nonscoped enum:
    // 1. has no implicit conversion to integral type.
    // 2. has own scope.
    // => reduce global namespace pollution and avoid name confliction.
    scopedColor sColor{scopedColor::red};
    scopedFruit sFruit{scopedFruit::apple};

    // Error:
    // Invalid operands to binary expression ('Color::scopedColor' and
    // 'Fruit::scopedFruit') [typecheck_invalid_operands].
    // if (sColor == sFruit) {
    //     std::cout << "sColor and sFruit are not comparable" << '\n';
    // } else {
    //     std::cout << "sColor and sFruit are not comparable" << '\n';
    // }

    std::cout << "Pick a color (0: red, 1: yellow, 2: green): ";
    int inputColor{};
    std::cin >> inputColor;

    scopedColor sInputColor{static_cast<scopedColor>(inputColor)};
    std::cout << "sInputColor: " << static_cast<int>(sInputColor) << '\n';

    return 0;
}

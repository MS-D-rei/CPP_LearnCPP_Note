#include <array>
#include <iostream>
#include <istream>
#include <iterator>
#include <string>
#include <string_view>

// Using constexpr arrays for better enumeration input and output
// 1. To easily output the name of enumerators as a string.
// 2. To look up the name of enumerators as a string.

namespace Colors {
enum Type { red, green, blue, max_colors };

// For `sv` suffix.
using namespace std::string_view_literals;
// CTAD. <std::array<std::string_view, 3>>.
constexpr std::array colorNames{"red"sv, "green"sv, "blue"sv};
static_assert(std::size(colorNames) == max_colors);

// contains all the enumerators.
constexpr std::array types{red, green, blue};
static_assert(std::size(types) == max_colors);
}  // namespace Colors

// Get the color name as string_view.
constexpr std::string_view getColorName(Colors::Type color) {
    return Colors::colorNames[color];
}

// std::ostream is a type of std::cout.
// print the color name as string_view.
std::ostream& operator<<(std::ostream& out, Colors::Type color) {
    return out << getColorName(color);
}

// we pass color by non-const reference to modify it.
std::istream& operator>>(std::istream& in, Colors::Type& color) {
    std::string input{};
    std::getline(in >> std::ws, input);

    for (std::size_t index{0}; index < Colors::colorNames.size(); index++) {
        if (input == Colors::colorNames[index]) {
            color = static_cast<Colors::Type>(index);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}

int main() {
    auto shirtColor{Colors::red};
    std::cout << "Your current shirt color: " << shirtColor << '\n';

    std::cout << "Available colors: ";

    // Cannot use range-based for loop on enumerators.
    // for (const auto& color : Colors::Type) { ... }
    // Here we prepare a array(Colors::types) containing all the enumerators.
    for (const auto& color : Colors::types) {
        std::cout << getColorName(color) << ' ';
    }

    std::cout << '\n';

    std::cout << "Pick a color: ";
    std::cin >> shirtColor;
    if (!std::cin) {
        std::cout << "Invalid color\n";
    } else {
        std::cout << "Your shirt color is now: " << shirtColor << '\n';
    }

    return 0;
}

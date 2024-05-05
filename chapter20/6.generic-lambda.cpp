#include <algorithm>
#include <array>
#include <iostream>

// Since C++14, we can use `auto` as a parameter type in a lambda.
// (C++20, regular functions can also use `auto` as a parameter type.)
// lambda which has one or more `auto` parameters is called a generic lambda.

int main() {
    constexpr std::array<const char*, 12> months{
        "January", "February", "March",     "April",   "May",      "June",
        "July",    "August",   "September", "October", "November", "December"};

    // generic lambda
    auto findSameFirstLetter{[](const auto& lhs, const auto& rhs) -> bool {
        return lhs[0] == rhs[0];
    }};

    const auto sameLetter{
        std::adjacent_find(months.begin(), months.end(), findSameFirstLetter)};

    if (sameLetter != months.end()) {
        std::cout << *sameLetter << " and " << *(sameLetter + 1)
                  << " have the same first letter.\n";
    }

    // However, `auto` is not always the best choice.

    // To treat data as a string, we have to use `std::string_view` as a
    // parameter type.
    // Otherwise `auto` infer the type as `const char*`.
    auto findFiveLetterMonth{
        [](std::string_view str) -> bool { return str.length() == 5; }};

    // About std::count_if:
    // https://en.cppreference.com/w/cpp/algorithm/count
    // support `constexpr` since C++20.
    // return type: number of elements that satisfy the condition.
    const auto fiveLetterMonth{
        std::count_if(months.begin(), months.end(), findFiveLetterMonth)};

    if (fiveLetterMonth > 0) {
        std::cout << "There are " << fiveLetterMonth
                  << " months with 5 letters.\n";
    }

    return 0;
}

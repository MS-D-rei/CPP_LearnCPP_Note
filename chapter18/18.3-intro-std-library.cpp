// use standard library instead of function we make ourself
//
// The functionality provided in the algorithms library
// generally fall into one of three categories:
// 1. Inspectors -- Used to view (but not modify) data in a container.
// Examples include searching and counting.
// 2. Mutators -- Used to modify data in a container.
// Examples include sorting and shuffling.
// 3. Facilitators -- Used to generate a result based on values of the data
// members. Examples include objects that multiply values, or objects that
// determine what order pairs of elements should be sorted in.

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string_view>

bool containsWord(std::string_view str) {
    // std::string_view::find returns std::string_view::npos if not found
    return (str.find("nut") != std::string_view::npos);
}

// Greater is so common. So we can use std::greater<int>() instead
bool greater(int a, int b) { return a > b; }

void doubleNumber(int& i) { i *= 2; };

int main() {
    std::array<int, 6> array{0, 1, 2, 3, 4, 5};

    // std::find(int* first, int* last, const int& value) => iterator(int*) or
    // int* last if not found
    auto found{std::find(std::begin(array), std::end(array), 3)};

    if (found != std::end(array)) {
        std::cout << "Found: " << *found << '\n';
    } else {
        std::cout << "Not found\n";
    }

    std::array<std::string_view, 5> strings{"apple", "banana", "walnut",
                                            "lemon", "peach"};

    auto foundStr{
        std::find_if(std::begin(strings), std::end(strings), containsWord)};

    if (foundStr != std::end(strings)) {
        std::cout << "Found nut: " << *foundStr << '\n';
    } else {
        std::cout << "No nuts\n";
    }

    // Custom sort (descending order)
    // std::sort(std::begin(array), array.end(), greater);
    std::sort(std::begin(array), std::end(array), std::greater<int>());

    for (const auto& i : array) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // For each
    std::for_each(std::begin(array), std::end(array), doubleNumber);

    for (const auto& i : array) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

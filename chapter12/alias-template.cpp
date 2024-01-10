#include <iostream>

template <typename T, typename U>
struct Pair {
    T first{};
    U second{};
};

// alias template.
// alias templates must be defined in the global scope (as all templates must).
template <typename T, typename U>
using Coord = Pair<T, U>;

template <typename T, typename U>
void printCoord(Coord<T, U> const& coord) {
    std::cout << "coord.first: " << coord.first << '\n';
    std::cout << "coord.second: " << coord.second << '\n';
}

int main() {
    Coord<int, int> coordInt{1, 2};
    Coord coordInt2{10.2, 20.5};  // C++20, can use alias template deduction.

    printCoord(coordInt);
    printCoord(coordInt2);

    return 0;
}

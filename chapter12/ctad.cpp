#include <iostream>
#include <utility>

// CTAD: class template argument deduction

template <typename T = int, typename U = int>
struct Pair {
    T first{};
    U second{};
};

// CTAD guide only needed for C++17
// C++20 will automatically generate this guide
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main() {
    std::pair<int, int> pairInt{1, 2};  // explicit types C++11
    std::pair pairInt2{1, 2};           // CTAD used to deduce types from C++17
    // error. CTAD does not work with std::pair<>.
    // std::pair<> pairInt3{1, 2};

    Pair pairInt4{1, 2};  // CTAD will use deduction guide.

    std::cout << "pairInt.first: " << pairInt.first << '\n';    // 1
    std::cout << "pairInt4.first: " << pairInt4.first << '\n';  // 1

    return 0;
}

#include <array>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t Row, std::size_t Col>
using Array2D = std::array<std::array<T, Row>, Col>;

template <typename T, std::size_t Row, std::size_t Col>
void printArray(const std::array<std::array<T, Row>, Col>& arr) {
    for (const auto& row : arr) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    // verbose way
    std::array<std::array<int, 4>, 3> arr1{
        std::array<int, 4>{1, 2, 3, 4},
        std::array<int, 4>{5, 6, 7, 8},
        std::array<int, 4>{9, 10, 11, 12},
    };

    // use double braces
    std::array<std::array<int, 4>, 3> arr2{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    }};

    printArray(arr1);  // 1 2 3 4 5 6 7 8 9 10 11 12

    // using type alias
    Array2D<int, 4, 3> arr3{{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    }};

    return 0;
}

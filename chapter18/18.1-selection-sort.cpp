// Sorting
//
// Sorting an array can make searching an array more efficient.
// The downside is that sorting an array is comparatively expensive,
// and it often isn't worth sorting an array in order to make searching fast
//
// Selection sort.
// - easy to understand, one of the slowest sorts.
// 1. Starting at index 0, search the entire array to find the smallest value.
// 2. Swap the smallest value with the value at index 0.
// 3. Move to index 1 and repeat the process.

#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

int main() {
    std::array<int, 5> array{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};

    for (int startIndex{0}; startIndex < length - 1; ++startIndex) {
        int smallestIndex{startIndex};
        for (int currentIndex{startIndex + 1}; currentIndex < length;
             ++currentIndex) {
            if (array[static_cast<std::size_t>(currentIndex)] <
                array[static_cast<std::size_t>(smallestIndex)]) {
                smallestIndex = currentIndex;
            }
        }

        std::swap(array[static_cast<std::size_t>(startIndex)],
                  array[static_cast<std::size_t>(smallestIndex)]);
    }

    for (const auto& element : array) {
        std::cout << element << ' ';
    }

    std::cout << '\n';

    return 0;
}

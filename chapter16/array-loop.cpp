#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
T calculateAverage(const std::vector<T>& vec) {
    T sum{};
    // for (const T& element : vec) {
    //     sum += element;
    // }
    // Prefer to use signed type for index.
    // Pre C++20, we can use static_cast<int>(vec.size()) to convert.
    // From C++20, we can use std::ssize(vec) to get signed size.
    int vecLength{static_cast<int>(vec.size())};
    for (int index{0}; index < vecLength; ++index) {
        sum += vec[static_cast<std::size_t>(index)];
    }
    return sum / static_cast<T>(vec.size());
}

int main() {
    std::vector classScore1{80, 90, 100, 95, 85};

    std::cout << "Average score for class 1 is "
              << calculateAverage(classScore1) << '\n';

    std::vector classScore2{50, 60, 70, 80, 90};

    std::cout << "Average score for class 2 is "
              << calculateAverage(classScore2) << '\n';

    return 0;
}

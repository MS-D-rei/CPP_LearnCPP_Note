#include <array>
#include <cstddef>
#include <iostream>
#include <limits>

// Pass array as (const) reference to avoid copy.

// When return array, there are 3 options:
// 1. return array by value.
// 2. return std::vector instead of array.
// 3. not return array at all. Passing array as non-const reference,
//   and modify it in-place.

template <typename T, std::size_t N>
void showFirstElement(const std::array<T, N>& arr) {
    std::cout << std::get<0>(arr) << '\n';
}

// Passing array as non-const reference, and modify it in-place.
// Downsides:
// 1. This method of returning data is non-conventional, and it is not easy to
// tell that the function is modifying the argument.
// 2. We can only use this method to assign values to the array, not initialize it.
// 3. Such a function cannot be used to produce temporary objects.
template <typename T, std::size_t N>
void inputArray(std::array<T, N>& arr) {
    std::size_t index{0};
    while (index < N) {
        std::cout << "Enter value for element #" << index << ": ";
        std::cin >> arr[index];

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        index++;
    }
}

int main() {
    constexpr std::array<int, 8> primes{2, 3, 5, 7, 11, 13, 17, 19};
    showFirstElement(primes);

    std::array<int, 5> arr{};
    inputArray(arr);
    showFirstElement(arr);

    return 0;
}

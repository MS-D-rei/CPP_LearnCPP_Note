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

// Return array by value.
// Pros:
// 1. It uses the most conventional way to return data to the caller.
// 2. It’s obvious that the function is returning a value.
// 3. We can define an array and use the function to initialize it in a single
// statement.
// Cons:
// 1. The function returns a copy of the array and all its elements, which isn’t
// cheap.
// 2. When we call the function, we must explicitly supply the template
// arguments since there is no parameter to deduce them from.
template <typename T, std::size_t N>
std::array<T, N> createInputArray() {
    std::array<T, N> arr{};
    std::size_t index{0};
    while (index < N) {
        std::cout << "Enter value fr element #" << index << ": ";
        std::cin >> arr[index];

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        index++;
    }
    return arr;
}

// Return array via out parameter.
// Passing array as non-const reference, and modify it in-place.
// Downsides:
// 1. This method of returning data is non-conventional, and it is not easy to
// tell that the function is modifying the argument.
// 2. We can only use this method to assign values to the array, not initialize
// it.
// 3. Such a function cannot be used to produce temporary objects.
template <typename T, std::size_t N>
void injectInputToArray(std::array<T, N>& arr) {
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

    std::array<int, 5> arr1{createInputArray<int, 5>()};
    showFirstElement(arr1);

    std::array<int, 5> arr2{};
    injectInputToArray(arr2);
    showFirstElement(arr2);

    return 0;
}

// C-style array is natively supported in C++.
// The standard library array container types(e.g., std::array, std::vector)
// are typically implemented using C-style array.

#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
constexpr std::size_t length(const T (&)[N]) noexcept {
    return N;
}

#include <iostream>
int main() {
    [[maybe_unused]] int primes1[5]{
        2, 3, 5, 7, 11,
    };

    [[maybe_unused]] int array1[5];
    [[maybe_unused]] int
        array2[5]{};  // preferred. All elements are initialized to 0.
    [[maybe_unused]] int array3[4]{
        1, 2};  // array3[2] and array3[3] are initialized to 0.

    // Prefer omitting the length of a C-style array
    // when explicitly initializing every array element with a value.
    int primes2[]{2, 3, 5, 7, 11};  // array size is automatically deduced.

    std::cout << "sizeof(primes2): " << sizeof(primes2) << "\n";  // 20
    // C++11 or C++14, use function, create length function to get the size of
    // an array.
    std::cout << "length(primes2): " << length(primes2) << "\n";  // 5
    // From C++17, std::size() can be used to get the size of an array.
    std::cout << "std::size(primes2): " << std::size(primes2) << "\n";  // 5

    return 0;
}

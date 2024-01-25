#include <cstddef>
#include <iostream>
#include <vector>

struct Foo {
    // create a vector with 10 elements
    // but this can not be used to initialize a vector as a member
    // std::vector<int> v1(10);

    // this creates a vector with capacity of 10 elements and
    // uses it as a member initializer
    std::vector<int> v2{std::vector<int>(10)};
};

int main() {
    // List constructor
    // It allows us to initialize a vector with a list of values
    // It does 3 things:
    // 1. Ensures the container has enough storage to hold all the
    // initialization values (if needed).
    // 2. Sets the length of the container to the number of elements in the
    // initializer list (if needed).
    // 3. Initializes the elements to the values in the initializer list (in
    // sequential order).
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

    // Can use const.
    // One of the biggest downsides of vector is that it is not possible to
    // create with constexpr.
    // If need it, use std::array instead.
    const std::vector vowels{'a', 'e', 'i', 'o', 'u'};

    // Subscript operator (operator[])
    std::cout << "First prime: " << primes[0] << '\n';

    std::cout << "primes: ";
    for (auto prime : primes) {
        std::cout << prime << " ";
    }

    std::cout << '\n';

    // Array are not bounds-checked
    // primes[100] will not throw an exception and
    // will do undefined behavior.
    // std::cout << primes[100] << '\n';

    // Array are contiguous in memory
    for (std::size_t i{0}; i < primes.size(); ++i) {
        std::cout << "The memory address of primes[" << i << "] is "
                  << &primes[i] << '\n';
    }

    return 0;
}

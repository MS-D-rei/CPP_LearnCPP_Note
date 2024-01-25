#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

    // vector::size() returns the number of elements in the vector
    // as a value of type std::size_t
    [[maybe_unused]] std::size_t primes_size{primes.size()};

    // std::size() is a C++17 feature
    // return the number of elements in the vector
    // as a value of type std::size_t
    [[maybe_unused]] std::size_t primes_size2{std::size(primes)};

    // std::ssize() is a C++20 feature
    // returns the length as a large signed integral type
    // (usually std::ptrdiff_t)
    auto primes_size3{std::ssize(primes)};

    int primes_length(static_cast<int>(primes_size3));

    std::cout << "primes_size: " << primes_size3 << '\n';

    std::cout << "primes_length: " << primes_length << '\n';

    // at() is bounds-checked
    // if the index is out of range, it throws std::out_of_range exception
    // at runtime.
    std::cout << "First prime: " << primes.at(0) << '\n';
    std::cout << "Last prime: " << primes.at(primes.size() - 1) << '\n';
    // std::cout << primes.at(100) << '\n'; // throws std::out_of_range

    constexpr int constexprPrimeIndex1{1};
    int primeIndex1{1};

    // subscript operator narrow conversion issue.
    // constexpr int will be impiicitly converted to std::size_t.
    std::cout << "constexprPrimeIndex1: " << primes[constexprPrimeIndex1]
              << '\n';
    // -Wsign-conversion: int will be impiicitly narrowing converted to
    // std::size_t.
    std::cout << "primeIndex1: " << primes[primeIndex1] << '\n';

    return 0;
}

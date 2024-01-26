#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printEachElement(const std::vector<T>& vec) {
    // to avoid expensive copying to the element,
    // use const reference.
    // The performance penalty of accessing elements through a reference instead
    // of by value is likely to be small.
    for (const auto& element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main() {
    using namespace std::literals;

    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

    printEachElement(primes);

    std::vector words{"one"s, "two"s, "three"s, "four"s, "five"s};

    printEachElement(words);

    return 0;
}

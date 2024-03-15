#include <array>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::array<int, 7> array{0, 1, 2, 3, 4, 5, 6};

    // Pointers as an iterator

    // auto begin{&array[0]};
    // auto end{begin + std::size(array)};

    auto begin{std::begin(array)};
    auto end{std::end(array)};

    for (auto ptr{begin}; ptr != end; ++ptr) {
        std::cout << *ptr << ' ';
    }

    std::cout << '\n';

    // Range-based for loop calls begin() and end() functions.
    for (const auto& i : array) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    std::vector<int> vec{1, 2, 3, 4, 5};

    auto it{vec.begin()};
    ++it;
    std::cout << *it << '\n';

    // erase() removes argument and returns an iterator to the next element.
    it = vec.erase(it);

    std::cout << *it << '\n';

    return 0;
}

#include <functional>
#include <iostream>

int main() {
    int x{1};
    int y{2};
    int z{3};

    std::array<std::reference_wrapper<int>, 3> refArray{x, y, z};

    // The get() member function can be used to get a T&.
    // We must use get() to modify the value.
    refArray[0].get() = 10;

    // std::reference_wrapper<T> will implicitly convert to T&.
    std::cout << "x: " << refArray[0] << '\n';

    return 0;
}

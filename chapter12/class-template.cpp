#include <iostream>

template <typename T, typename U>
struct Pair {
    T first{};
    U second{};
};

template <typename T, typename U>
// use value parameters because Pair is small and cheap to copy
constexpr auto max(Pair<T, U> const p) {
    return p.first < p.second ? p.second : p.first;
}

int main() {
    Pair<int, int> pairInt{1, 2};  // instantiate Pair for type int
    std::cout << "pairInt.first: " << pairInt.first << '\n';  // 1

    Pair<double, double> pairDouble{3.14,
                                    2.71};  // instantiate Pair for type double
    std::cout << "pairDouble.second: " << pairDouble.second << '\n';  // 2.71

    Pair<double, double> pairDouble2{3.14,
                                     2.71};  // use prior Pair for type double
    std::cout << "pairDouble2.first: " << pairDouble2.first << '\n';  // 3.14

    Pair<int, double> pairIntDouble{
        1, 2.71};  // instantiate Pair for type int and double
    std::cout << "pairIntDouble.second: " << pairIntDouble.second
              << '\n';  // 2.71

    std::cout << "max(pairInt): " << max(pairInt) << '\n';              // 2
    std::cout << "max(pairDouble): " << max(pairDouble) << '\n';        // 3.14
    std::cout << "max(pairIntDouble): " << max(pairIntDouble) << '\n';  // 2.71

    return 0;
}

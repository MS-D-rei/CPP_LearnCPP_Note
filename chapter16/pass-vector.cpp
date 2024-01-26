#include <iostream>
#include <vector>

// CTAD (class template argument deduction) cannot be used for function
// parameters.
// This is great place to make use of function templates.
// Pass by reference to avoid expensive copying the vector.
template <typename T>
void getFirstElement(const std::vector<T>& vec) {
    if (vec.empty()) {
        // throw an exception
        std::cout << "Vector is empty" << '\n';
    } else {
        std::cout << "First element is " << vec[0] << '\n';
    }
}

int main() {
    // From C++17, we can use class template argument deduction
    std::vector primes{2, 3, 5, 7, 11, 13, 17, 19};
    std::vector dbls{3.14, 2.718, 1.414, 0.577};

    getFirstElement(primes);
    getFirstElement(dbls);

    return 0;
}

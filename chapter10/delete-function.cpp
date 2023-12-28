#include <iostream>

void printInt(int x) { std::cout << "int: " << x << '\n'; }

// = delete means, forbid the use of this function,
// not it does not exist.
template <typename T>
void printInt(T x) = delete;

int main() {
    printInt(42);
    printInt(4.2);  // error: use of deleted function 'void printInt(T) [with T
                    // = double]'
}

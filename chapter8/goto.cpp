#include <cmath>
#include <iostream>

// Avoid goto statements.
// unless the alternatives are significantly worse.

void printCats(bool execute) {
    if (!execute) {
        goto end;
    }

    std::cout << "Cats\n";
end:;
}

int main() {
    double x{};
tryAgain:
    std::cout << "Enter a non-negative number: ";
    std::cin >> x;

    if (x < 0.0) {
        goto tryAgain;
    }

    std::cout << "The square root of " << x << " is " << sqrt(x) << "\n";

    printCats(false);
    printCats(true);

    return 0;
}

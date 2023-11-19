#include <iostream>

int main() {
    // assume 4 byte integers

    int x{2'147'483'647}; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    ++x; // integer overflow, undefined behavior
    std::cout << x << '\n';

    return 0;
}

/* the output of this program is:
 * 2147483647
 * -2147483648
 * However, because the second output is the result of undefined behavior, 
 * the value output may vary on your machine.
*/

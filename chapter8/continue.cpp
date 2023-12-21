#include <iostream>

// break and continue can help make loops more readable
// by keeping the number of nested blocks down and reducing
// the need for complicated looping logic.

// The continue statement is most effectively used at the top of a for-loop
// to skip loop iterations when some condition is met.
// This can allow us to avoid a nested block.

// can use like guard clause

int main() {
    // for (int count{0}; count < 10; ++count) {
    //     if ((count % 4) != 0) {
    //         std::cout << count << '\n';
    //     }
    // }

    for (int count{0}; count < 10; ++count) {
        if ((count % 4) == 0) {
            continue;
        }
        std::cout << count << '\n';
    }

    return 0;
}

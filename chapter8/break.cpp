#include <iostream>

// break and continue can help make loops more readable
// by keeping the number of nested blocks down and reducing
// the need for complicated looping logic.

int main() {
    // int count{0};
    // bool keepLooping{true};
    // while (keepLooping) {
    //     std::cout << "Enter 'q' to quit: ";
    //     char ch{};
    //     std::cin >> ch;
    //
    //     if (ch == 'q') {
    //         keepLooping = false;
    //     } else {
    //         ++count;
    //         std::cout << "You've iterated " << count << " times.\n";
    //     }
    // }

    // The above example can be simplified with a break statement:
    int count{0};
    while (true) {
        std::cout << "Enter 'q' to quit: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'q') {
            break;
        }

        ++count;
        std::cout << "You've iterated " << count << " times.\n";
    }

    return 0;
}

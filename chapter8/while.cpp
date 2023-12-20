#include <iostream>

int main() {
    int count{1};
    while (count <= 50) {
        if (count < 10) {
            std::cout << "0";
        }

        std::cout << count << " ";

        if (count % 10 == 0) {
            std::cout << "\n";
        }

        ++count;
    }

    int outer{1};
    while (outer <= 5) {
        int inner{1};
        while (inner <= outer) {
            std::cout << inner << ' ';
            ++inner;
        }

        std::cout << "\n";
        ++outer;
    }

    int outer2{5};
    while (outer2 >= 1) {
        int inner{outer2};
        while (inner >= 1) {
            std::cout << inner << ' ';
            --inner;
        }

        std::cout << "\n";
        --outer2;
    }

    return 0;
}

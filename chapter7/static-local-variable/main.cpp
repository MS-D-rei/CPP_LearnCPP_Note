#include <iostream>

// static local variables
// One of the most common uses for static duration local variables is for unique
// ID generators.

// Avoid static local variables unless the variable never needs to be reset.

int generateID() {
    // static duration via static keyword
    // this initialization is only performed once
    static int s_id{0};
    return s_id++;
}

void incrementAndPrint() {
    // automatic duration by default
    int value{0};
    // static duration via static keyword
    // this initialization is only performed once
    static int s_value{0};
    ++value;
    ++s_value;
    std::cout << "automatic duration value: " << value << '\n';
    std::cout << "static duration s_value: " << s_value << '\n';
}

int main() {
    for (int count{0}; count < 5; ++count) {
        incrementAndPrint();
        const int id{generateID()};
        std::cout << "id: " << id << '\n';
    }
    return 0;
}

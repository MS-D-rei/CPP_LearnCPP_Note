#include <iostream>

int main() {
    std::cout << "Enter a positive integer: ";
    std::size_t length{};
    std::cin >> length;

    // Note that length does not need to be constant!
    int* array{new int[length]{}};

    std::cout << "I just allocated an array of integers of length " << length
              << '\n';

    array[0] = 5;

    // We have to use array version of delete, delete[].
    // new[] keeps track of how much memory was allocated,
    // So delete[] knows how much to deallocate.
    // This length is not accessible to us.
    delete[] array;
    // We don't need to set array to nullptr/0 here because it's going to go out
    // of scope immediately after this anyway.
    array = nullptr;

    // Resizing dynamically allocated array is not recommended.
    // => Use std::vector instead.

    return 0;
}

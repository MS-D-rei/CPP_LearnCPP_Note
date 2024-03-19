#include <iostream>

// Recommend not to use pointers to pointers
// unless no other option is available.

int main() {
    // Pointer to pointer (few use cases, but it's good to know about it)

    int value{5};
    int* ptr{&value};
    std::cout << "Value: " << value << '\n';                // 5
    std::cout << "Pointer: " << ptr << '\n';                // 0x7ffebc3f3bfc
    std::cout << "Dereferenced pointer: " << *ptr << '\n';  // 5

    int** ptrToPtr{&ptr};
    std::cout << "Pointer to pointer: " << ptrToPtr << '\n';  // 0x7ffebc3f3bf0
    // Dereferencing ptrToPtr gives us ptr
    std::cout << "Dereferenced pointer to pointer: " << *ptrToPtr
              << '\n';  // 0x7ffebc3f3bfc
    // Dereferencing ptrToPtr twice gives us value
    std::cout << "Dereferenced twice: " << **ptrToPtr << '\n';  // 5

    // Arrays of pointers

    // int** array contains the pointer to point the first pointer of the array
    int** array{new int* [5] {}};

    for (int count{0}; count < 5; ++count) {
        array[count] = new int(count + 1);
    }

    for (int count{0}; count < 5; ++count) {
        std::cout << *array[count] << ' ';
    }
    std::cout << '\n';

    delete[] array;
    array = nullptr;

    return 0;
}

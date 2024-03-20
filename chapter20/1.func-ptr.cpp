#include <functional>
#include <iostream>
#include <utility>

int foo(int x) { return x; }

bool ascending(int x, int y) { return x > y; }
bool descending(int x, int y) { return x < y; }

// type alias is helpful for readability.
using CompareFunction = bool (*)(int, int);
// std::function is another way to define a function pointer.
using CompareFunctionStd = std::function<bool(int, int)>;

// Function pointer as a parameter.
// Now caller can select how to sort.
// ascending is the default parameter.
// void selectionSort(int* array, int size, bool (*compare)(int, int) =
// ascending) {
//     for (int startIndex{0}; startIndex < size - 1; ++startIndex) {
//         int smallestIndex{startIndex};
//         for (int currentIndex{startIndex + 1}; currentIndex < size;
//              ++currentIndex) {
//             if (compare(array[smallestIndex], array[currentIndex])) {
//                 smallestIndex = currentIndex;
//             }
//         }
//         std::swap(array[startIndex], array[smallestIndex]);
//     }
// }
void selectionSort(int* array, int size,
                   CompareFunctionStd compare = ascending) {
    for (int startIndex{0}; startIndex < size - 1; ++startIndex) {
        int smallestIndex{startIndex};
        for (int currentIndex{startIndex + 1}; currentIndex < size;
             ++currentIndex) {
            if (compare(array[smallestIndex], array[currentIndex])) {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

void printArray(int* array, int size) {
    for (int index{0}; index < size; ++index) {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';
}

int main() {
    // Function pointer is a pointer that points to a function.
    // It can be used to call the function that it points to.
    int (*pFoo)(int){foo};

    // Default parameter does not work with function pointer.
    // Default parameter is resolved at compile time,
    // but function pointer is resolved at runtime.

    if (pFoo != nullptr) {
        // explicit dereferencing
        std::cout << (*pFoo)(5) << '\n';
        // implicit dereferencing
        std::cout << pFoo(5) << '\n';
    }

    // One of the most common use of function pointer is to pass a function
    // as a parameter to another function.
    // (callback function, event handler, etc.)

    int array[10]{3, 7, 9, 5, 6, 1, 8, 2, 4, 0};

    selectionSort(array, 10, ascending);
    printArray(array, 10);

    selectionSort(array, 10, descending);
    printArray(array, 10);

    return 0;
}

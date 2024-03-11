#include <iostream>
#include <vector>

// Vector Length and Capacity
// - Length: the number of elements in the vector.
// - Capacity: the number of elements that the vector can hold without
// reallocation.

// Vector resize
// Resizing makes vector special.
// However, when it changes the capacity, it is called reallocation.
// Reallocation is a very expensive operation.
// 1. std::vector acquires new memory with capacity for the desired
// number of elements.
// 2. std::vector copies the elements from the old memory to the new memory.
// and returns the old memory to the system.
// 3. The length and capacity of the vector are updated.

template <typename T>
void printVectorElement(const std::vector<T>& vector) {
    for (const auto& elem : vector) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void printVectorLengthAndCapacity(const std::vector<T>& vector) {
    std::cout << "Length: " << vector.size() << '\n';
    std::cout << "Capacity: " << vector.capacity() << '\n';
}

int main() {
    std::vector<int> vector1{0, 1, 2};
    printVectorLengthAndCapacity(vector1);
    printVectorElement(vector1);
    std::cout << '\n';

    vector1.resize(5);  // change the length to 5
    printVectorLengthAndCapacity(vector1);
    printVectorElement(vector1);
    std::cout << '\n';

    vector1.resize(2);  // change the length to 2
    printVectorLengthAndCapacity(vector1);
    printVectorElement(vector1);
    std::cout << '\n';

    vector1.shrink_to_fit();  // change the capacity to the length
    printVectorLengthAndCapacity(vector1);
    printVectorElement(vector1);
    std::cout << '\n';

    return 0;
}

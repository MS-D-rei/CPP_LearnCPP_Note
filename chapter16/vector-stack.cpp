#include <iostream>
#include <vector>

// Best Practices:
// - Prefer emplace_back() when creating a new temporary object to add to the
// container, or when you need to access an explicit constructor.
// - Prefer push_back() otherwise.

template <typename T>
void printStack(const std::vector<T>& stack) {
    if (stack.empty()) {
        std::cout << "stack is empty\n";
    }

    for (const auto& elem : stack) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    std::cout << "Length: " << stack.size() << '\n';
    std::cout << "Capacity: " << stack.capacity() << '\n';
    std::cout << '\n';
}

int main() {
    std::vector<int> stack{};
    printStack(stack);

    // reserve() changes the capacity of the vector.
    // It does not change the length of the vector.
    // resize() changes the length of the vector.
    stack.reserve(6);
    printStack(stack);

    // push_back() adds an element to the end of the vector.
    stack.push_back(1);
    printStack(stack);

    stack.push_back(2);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    std::cout << "top: " << stack.back() << '\n';
    std::cout << '\n';

    // pop_back() removes the last element of the vector.
    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    return 0;
}

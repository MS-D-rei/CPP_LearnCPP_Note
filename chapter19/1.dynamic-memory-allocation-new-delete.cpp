// C++ supports the basic types of memory allocation.
// 1. Static memory allocation
// => for static and global variables
// 2. Automatic memory allocation
// => for local variables, function arguments
// 3. Dynamic memory allocation

// When dealing with external user or file input,
// we don't know the size of the data in advance.
// If we use static or automatic memory allocation,
// it will be poor solution due to the reasons below.

// 1. If the size of the data is too small,
// it will be a waste of memory.
// 2. If the size of the data is too large,
// it will be a waste of memory and the program will crash,
// or we have to throw an error.
// 3. the limitation of the `stack` size.

// Dynamic memory allocation is the way for running programs
// to request memory from the operating system when needed.
// It is allocated on the `heap`, which is a much larger pool
// of memory managed by the operating system.

// heap-allocated objects is generally slower than stack-allocated objects.
// Because compiler knows the address of the stack-allocated objects,
// it can go directly to the address to get the value.
// Heap allocated objects are typically accessed via pointer.
// This requires 2 steps: 1. get the address of the object, 2. get the value.

#include <iostream>
#include <new>

int main() {
    // The `new` operator is used to allocate memory at runtime.
    int* ptr1{new int(5)};
    int* ptr2{new int{6}};

    // The `delete` operator is used to deallocate memory at runtime.
    // `delete` operator does not actually delete anything.
    // It simply returns the memory to the operating system.
    // After `delete` is called, the pointer still points to the same memory
    // location. To avoid dangling pointers, set the pointer to `nullptr` after
    // deleting it.
    // Deleting a null pointer is okay. It does nothing.
    delete ptr1;
    ptr1 = nullptr;  // Always set the pointer to `nullptr` after deleting it.

    // `new` can fail if the system is out of memory.
    // If `new` fails, it throws an exception of type `std::bad_alloc`. And the
    // program crashes.
    // To avoid crashing, we can use `std::nothrow` to return a `nullptr` if the
    // allocation fails.
    int* ptr3{new (std::nothrow) int(7)};
    if (ptr3 == nullptr) {
        // handle the error
        std::cerr << "Memory allocation failed" << '\n';
    }

    // Memory leak
    // When program lost the reference to the memory location without freeing
    // it, the program and the operating system can't use the memory anymore.
    // This is called `memory leak`.
    // To avoid memory leak, always free the memory after using it.
    // There are 2 patterns the memory leak can occur.
    // 1. forget to delete the memory
    // 2. reassign the pointer without deleting the memory
    // int value {5};
    // int* ptr4 {new int{}};
    // ptr4 = &value;  // memory leak. now lost the address of ptr4
    // On;y after the program ends, the memory will be freed by the operating
    // system.

    return 0;
}

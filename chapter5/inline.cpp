#include <iostream>

// why functions are good?
// 1. they allow us to reuse code
// 2. they allow us to give names to blocks of code
// 3. they allow us to abstract away details of implementation
// 4. they allow us to test our code in isolation
// 5. they allow us to change the implementation without changing the interface

// However one downside is that they can be slow. This is because the compiler 
// has to jump to the function, execute it, and then jump back to where it was
// in the code. This is called a function call overhead.
// For small function like min() below, the overhead is greater than the time
// it takes to execute the function itself. This is where inline functions come
// in. 
// Inline functions are functions that are expanded in place, rather than
// being called. This eliminates the function call overhead.

// Benefits of inline functions vs the size of the function
// Inline functions makes the function body larger,
// which can cause the program to run slower due to not fitting in memory caches.

// So do we consider whether use inline or not?
// No. Modern compilers are smart enough to decide whether to inline or not.
// We should not use inline keyword.

int min(int x, int y) { return x < y ? x : y; }

int main() {
    // Inline expansion
    // The compiler will replace the function call with the function body
    // This is done at compile time, so there is no function call overhead
    std::cout << "min(5, 6): " << min(5, 6) << '\n';
    std::cout << "min(3, 2): " << min(3, 2) << '\n';
    // std::cout << "min(5, 6): " << (5 < 6 ? 5 : 6) << '\n';
    // std::cout << "min(3, 2): " << (3 < 2 ? 3 : 2) << '\n';
    // Inline functions helps compiler to optimize the code
    // std::cout << "min(5, 6): " << 5 << '\n';
    // std::cout << "min(3, 2): " << 2 << '\n';

    return 0;
}

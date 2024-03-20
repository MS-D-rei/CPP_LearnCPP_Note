// The memory that a program uses is divided into few areas, called segments.
// 1. Code segment: where the program's instructions are stored.
// 2. Bss segment(also called uninitialized data segment):
// zero-initialized global and static variables are stored.
// 3. Data segment(also called initialized data segment):
// initialized global and static variables are stored.
// 4. Heap: dynamic memory allocation.
// 5. Call stack: local variables, function parameters, return addresses, etc.

// Heap segment:
// - The heap is a large pool of memory that can be used dynamically.
// - Allocating memory on the heap is comparatively slower than on the stack.
// - Allocated memory stays allocated untill it is deallocated
// or the program terminates.
// - Dynamically allocated memory must be accessed through a pointer.

// Call stack:

// ellipsis are rarely used in C++,
// potentially dangerous and avoiding them is recommended.

// Downside of ellipsis:
// - Type checking is suspended.
// It means that compiler will no longer be able to warn us if we pass
// the wrong type of argument.
// - No way to know how many arguments are passed.

#include <cstdarg>
#include <iostream>  //va_list, va_start, va_arg, va_end

double findAverage(int count, ...) {
    int sum{0};

    // va_list is like a pointer.
    std::va_list list;

    // list points to the first parameter in the ellipsis.
    // Can call va_start to reset the pointer to the first parameter.
    va_start(list, count);

    for (int arg{0}; arg < count; ++arg) {
        // va_arg(list, type_info) return the current value of the va_list
        // and moves the va_list to the next argument.
        sum += va_arg(list, int);
    }

    // Clean up the va_list when we're done.
    va_end(list);

    return static_cast<double>(sum) / count;
}

int main() {
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
    std::cout << findAverage(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << '\n';

    return 0;
}

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool containsNut(std::string_view str) {
    // https://en.cppreference.com/w/cpp/string/basic_string_view/find
    // std::string_view::find returns std::string_view::npos if the substring
    // is not found.
    // Otherwise, it returns the index of the first character of the substring.
    return str.find("nut") != std::string_view::npos;
}

int main() {
    constexpr std::array<std::string_view, 4> array1{"apple", "banana",
                                                     "walnut", "lemon"};

    auto found{std::find_if(array1.begin(), array1.end(), containsNut)};

    if (found == array1.end()) {
        std::cout << "No nuts" << '\n';
    } else {
        std::cout << "Found " << *found << '\n';
    }

    // Abobe code could be improved using lambda

    // the code is passing `containsNut` function pointer to `std::find_if`.
    // `containsNut` is short, and called only once.
    // It is better not to put it in global scope, and name it.

    // lambda expression(also called a lambda or closure) allows us to define
    // an anonymous function inside another function.
    // This nesting is important, because it allows us both to avoid namespace
    // pollution, and to define the function as close to the place where it is
    // used as possible.

    // The syntax of a lambda expression is:
    // [captureClause](parameters) -> return_type { body }
    // - captureClause: specifies which variables from the enclosing scope are
    //  available inside the lambda.
    //  - []: no variables are captured.
    //  - [=]: all variables are captured by value.
    //  - [&]: all variables are captured by reference.
    //  - [var1, var2]: only var1 and var2 are captured.
    //  - [this]: captures the `this` pointer.
    // - parameters: the parameters of the lambda.
    // - return_type: the return type of the lambda. optional.

    // Rewrite with lambda

    auto found2{std::find_if(
        array1.begin(), array1.end(), [](std::string_view str) -> bool {
            return str.find("nut") != std::string_view::npos;
        })};

    // But, this lambda is little bit not readable.
    // Can name lambda, and this makes the lambda reusable.

    auto containsNutLambda{[](std::string_view str) -> bool {
        return str.find("nut") != std::string_view::npos;
    }};

    auto found3{std::find_if(array1.begin(), array1.end(), containsNutLambda)};

    // what is the type of `containsNutLambda`?
    // => compiler will generate a unique type just for the lambda
    // we can't explicitly use.

    if (found2 == array1.end()) {
        std::cout << "No nuts" << '\n';
    } else {
        std::cout << "Found " << *found2 << '\n';
    }

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <limits>

// general text error types.
// 1. input extraction succeeded, but the input value is not expected.
// => use a while loop to keep asking for input until the user enters a valid
// 2. input extraction succeeded, but the user enters more input than expected.
// 3. input extraction failed.
// 4. input extraction succeeded, but the user overflows a numeric value.

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble() {
    while (true) {
        std::cout << "Enter a decimal value: ";
        double value{};
        std::cin >> value;

        // 3. input extraction failed.
        // example: input 'a'.
        if (std::cin.fail()) {
            // On Unix systems, if the user enters Ctrl+D,
            // end-of-file(EOF) character will be generated.
            // and it closes the input stream.
            // std::cin.clear() can't fix this.
            if (std::cin.eof()) {
                exit(0);
            }

            std::cin.clear();  // reset any error flags.
            ignoreLine();      // ignore any inputs in the input buffer.

            std::cout << "Oops, that input is invalid. Please try again.\n";
        } else {
            // 2. input extraction succeeded,
            // but the user enters more input than expected.
            // for example, if enter 5*7, the *7 will be left in the input
            // buffer.
            // => use std::cin.ignore() to discard the remaining characters in
            // the input buffer.
            ignoreLine();
            return value;
        }
    }
}

char getOperator() {
    // std::cout << "Enter one of the following: +, -, *, or /: ";
    // char operation{};
    // std::cin >> operation;
    // return operation;

    while (true) {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char operation{};
        std::cin >> operation;

        // 3. input extraction failed.
        if (std::cin.fail()) {
            if (std::cin.eof()) {
                exit(0);
            }

            std::cin.clear();  // go back to normal mode.
        }

        // 2. input extraction succeeded, but the user enters more input than
        // expected.
        ignoreLine();  // ignore any inputs in the input buffer.

        // 1. input extraction succeeded, but the input value is not expected.
        switch (operation) {
            case '+':
            case '-':
            case '*':
            case '/':
                return operation;
            default:
                std::cout << "Invalid input. Try again.\n";
        }
    }
}

void printResult(double x, char op, double y) {
    switch (op) {
        case '+':
            std::cout << x << " + " << y << " is " << x + y << '\n';
            break;
        case '-':
            std::cout << x << " - " << y << " is " << x - y << '\n';
            break;
        case '*':
            std::cout << x << " * " << y << " is " << x * y << '\n';
            break;
        case '/':
            std::cout << x << " / " << y << " is " << x / y << '\n';
            break;
        default:
            std::cout << "Something went wrong: printResult() got an invalid "
                         "operator.\n";
    }
}

int main() {
    double x{getDouble()};
    char op{getOperator()};
    double y{getDouble()};

    printResult(x, op, y);

    return 0;
}

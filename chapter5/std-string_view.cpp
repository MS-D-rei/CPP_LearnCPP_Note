#include <iostream>
#include <string>
#include <string_view>

// std::string_view
// 1. read-only access to a string
// 2. does not make a copy of the string
// 3. its parameters are implicitly converted to std::string_view
// 4. this is like a watcher of the original string

void printString(std::string str) {
    // str makes a copy of its initializer
    std::cout << str << '\n';
}

void printStringView(std::string_view str) {
    // str does not make a copy of its initializer
    // str provides a read-only access to the original string
    std::cout << str << '\n';
}

int main() {
    // greeting makes a copy of its initializer
    std::string greeting{"Hello, world!"};
    printString(greeting);

    // greetingView does not make a copy of its initializer
    std::string_view greetingView{greeting};
    printStringView(greeting);

    // string_view is like a watcher.
    std::string name{"Alex"};
    std::string_view nameView{name};
    std::cout << nameView << '\n';  // Alex

    nameView = "John";
    std::cout << nameView << '\n';  // John
    std::cout << name << '\n';      // Alex

    constexpr std::string_view supported{
        "std::string_view has full support for constexpr"};
    std::cout << supported << '\n';

    return 0;
}

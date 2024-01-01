#include <iostream>
#include <string>

// Pass by reference when you can, pass by address when you must

// Return by reference.
// needs the variable to outlive the function.
// Otherwise, the reference will be dangling.
const std::string& getName() {
    static std::string name{"Alex"};
    return name;
}

// It is okay to return by const reference with an rvalue passed by const
// reference.

// rvalue is passed by const reference.
// return by const reference.
const std::string& foo(const std::string& str) { return str; }

// return rvalue.
std::string getHello() { return std::string{"Hello"}; }

int main() {
    std::cout << "name = " << getName() << '\n';

    const std::string str{foo(getHello())};
    std::cout << "str = " << str << '\n';

    return 0;
}

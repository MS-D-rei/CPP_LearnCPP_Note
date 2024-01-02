#include <iostream>
#include <string>

// Return by reference returns a reference
// that is bound to the object that is returned.
// This avoids making a copy of the object.

// Prefer return by ref over return by address.
// Because return by ref is safer.
// Return by address has to take care of nullptr before dereferencing.

// Return by reference.
// needs the variable to outlive the function.
// Otherwise, the reference will be dangling.
const std::string& getName() {
    static std::string name{"Alex"};
    return name;
}

// rvalue is passed by const reference.
// return by const reference.
const std::string& foo(const std::string& str) { return str; }

// return rvalue.
std::string getHello() { return std::string{"Hello"}; }

int main() {
    std::cout << "name = " << getName() << '\n';

    // It is okay to return by const reference with an rvalue passed by const
    // reference.
    const std::string str{foo(getHello())};
    std::cout << "str = " << str << '\n';

    return 0;
}

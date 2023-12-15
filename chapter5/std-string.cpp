#include <iostream>
#include <string>

// std::literals::string_literals
using namespace std::string_literals; // for "s" suffix

int main() {
    std::string name{"Alex"};
    name = "John";
    name += " Doe";

    std::cout << name << '\n';

    std::cout
        << "Enter your full name: ";  // suppose the user enters "John Doe"
    std::string myName{};
    std::cin >> myName;

    std::cout << "Your name is " << myName
              << '\n';  // only "John" was stored in myName

    std::cout << "Enter your age: ";  // do not show the prompt
    std::string age{};
    std::cin >> age;

    std::cout << "You are " << age
              << " years old\n";  // only "Doe" was stored in age

    std::cout
        << "Enter your full name: ";  // suppose the user enters "John Doe"
    std::string myName2{};
    std::getline(std::cin >> std::ws, myName2);

    std::cout << "Your name is " << myName2
              << '\n';  // "John Doe" was stored in myName2

    // std::string::length() returns type size_t, which is an unsigned integer
    // type. This means that if we try to store the result of length() in an
    // int, we will get a warning. To avoid this warning, we can use a static
    // cast to convert the result of length() to an int:
    int myName2Length(static_cast<int>(myName2.length()));
    std::cout << myName2 << " has " << myName2Length << " characters\n";
    // std::ssize() is a C++20 feature that returns the size of a container as
    // a signed integer type. This means that if we try to store the result of
    // ssize() in an int, we will not get a warning:
    std::cout << myName2 << " has " << std::ssize(myName2) << " characters\n";

    std::cout << "Enter your age: ";  // show prompt and input 35
    std::string age2{};
    std::getline(std::cin >> std::ws, age2);

    std::cout << "You are " << age2
              << " years old\n";  // "35" was stored in age2

    std::cout << "Pick 1 or 2: ";  // enter 1<enter>. this means 1\n
    int choice{};
    std::cin >> choice;  // store 1 in choice

    std::cout << "Now enter your name: ";
    std::string name2{};
    std::getline(std::cin,
                 name2);  // getline reads '\n' from the previous input

    std::cout << "Hello, " << name2 << ", you picked " << choice << '\n';

    std::cout << "\"foo\\n\"\n";  // C-style string literal
    std::cout << "goo\n"s;        // std::string literal

    return 0;
}

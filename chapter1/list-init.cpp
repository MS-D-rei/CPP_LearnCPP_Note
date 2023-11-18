// List initialization is preferred over other forms of initialization in almost all cases.

#include <iostream>

int main()
{
    // implicit conversion from double to int
    // can be compiled
    // int x = 5.5;
    // List initialization is a way to initialize variables introduced in C++11.
    // List initialization has an added benefit: it disallows “narrowing conversions”.
    // Narrowing conversions are those that lose information, such as int to char.
    // This means that if you try to brace initialize a variable using a value 
    // that the variable can not safely hold, the compiler will produce an error
    // int y { 5.5 };
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;

    // zero initialization to value 0
    int z {};
    std::cout << z << "\n"; // 0

    // should initialize with a value
    const char* a = "a"; 
    std::cout << a << "\n";
    return 0;
}

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    
    int enteredInteger{};
    std::cin >> enteredInteger;

    std::cout << "Double " << enteredInteger << " is: " << enteredInteger * 2 << '\n';

    return 0;
}

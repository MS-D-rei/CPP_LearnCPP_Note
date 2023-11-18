#include <iostream>

int main()
{
    // Using std::endl can be a bit inefficient, as it actually does two jobs:
    // it inserts a newline character into the stream, and it flushes the buffer(stream).
    // Flushing the buffer means that the buffer is forcibly written to output device,
    // whether it is full or not.
    // This is useful in situations where you need to ensure that the user has the most up-to-date information,
    // even if the program crashes or hangs.
    // However, flushing the buffer can significantly slow down output.
    // If you don’t need to ensure that the user has the most up-to-date information,
    // you can use the newline character \n instead of std::endl.
    // The newline character \n is a special character that tells the stream to start a new line.
    // It does not flush the buffer.
    int x { 5 };
    std::cout << "x = " << x << std::endl;

    int y { 3 };
    std::cout << "y = " << y << "\n";

    int z {};
    std::cout << "Enter an integer:";
    std::cin >> z;
    std::cout << "z = " << z << "\n";
    
    return 0;
}

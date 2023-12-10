#include <iostream>

int main() {
    // assume the user enters "abcd" (without quotes)
    std::cout << "Input a keyboard character: ";

    char ch{};
    std::cin >> ch;  // ch = 'a', "bcd" is left queued
    std::cout << "You entered: " << ch << '\n';  // will print "You entered: a"

    // Note: The following cin doesn't ask the user for input,
    // it grabs queued input!
    std::cin >> ch;  // ch = 'b', "cd" is left queued
    std::cout << "You entered: " << ch << '\n';  // will print "You entered: b"

    // Excape sequences examples
    // \n  newline
    // \t  tab
    // \'  single quote'
    // \"  double quote"
    // \\  backslash\

    // symbol literals
    // 'a'  character literal
    // "a"  string literal (array of characters)
    // 1    integer literal
    // 1.0  floating point literal
    // true boolean literal
    // false boolean literal
    // nullptr  null pointer literal
    // 0x7c0 hexadecimal literal
    // 0b11111000000 binary literal
    // 1'000'000'000'000'000'000  digit separator
    // 1.0e-6  floating point literal
    // 1.0E6   floating point literal
    // 1.0e+6  floating point literal
    // 1.0e6   floating point literal

    // stand alone chars in single quotes
    // 'a', not "a"
    // '\n', not "\n"
    // This helps the compiler to distinguish between a character and a string

    // avoid multi-byte characters
    // char ch1{ 'a' }; // fine
    // char ch2{ 'ab' }; // error: too many characters in character constant
    // they are not portable across compilers 
    // because they are not part of the C++ standard

    // unicode and char8_t, char16_t, char32_t
    // char16_t and char32_t are added in C++11
    // char8_t is added in C++20
    // they have thez same size as std::uint_leastx_t

    return 0;
}

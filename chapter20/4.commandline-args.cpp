#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    // show comand line arguments
    // argv[0] is the program itself
    std::cout << "There are " << argc << " arguments:\n";
    for (int count{0}; count < argc; ++count) {
        std::cout << count << ": " << argv[count] << '\n';
    }

    if (argc <= 1) {
        if (argv[0]) {
            std::cout << "Usage: " << argv[0] << "<number>" << '\n';
        } else {
            std::cout << "Usage: <program name> <number>" << '\n';
        }
        return 1;
    }

    // istream <- iostream <- stringstream
    std::stringstream convertFirstArg{argv[1]};

    int myInt{};
    // https://cplusplus.com/reference/istream/basic_istream/operator%3E%3E/
    // basic_istream& operator>> (int& val);
    // convert.>>(myInt) is equivalent to convert >> myInt
    // If fails to extract an integer, internal state flags are set.
    // In the case of no characters being extracted, or the characters extracted
    // could not be interpreted as a valid value of the requested type,
    // the failbit flag is set.
    // (chatgpt says) std::basic_istream class has an implicit conversion
    // operator to void* which is used in the condition of the if statement.
    // This conversion operator returns a `nullptr` if the stream is in a fail
    // state.
    if (!(convertFirstArg >> myInt)) {
        myInt = 0;
    }

    std::cout << "Got integer: " << myInt << '\n';
    return 0;
}

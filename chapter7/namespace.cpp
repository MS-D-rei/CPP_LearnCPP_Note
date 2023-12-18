#include <iostream>

#include "add.h"
#include "subtract.h"

// int doSomething(int x, int y);

// There are 2 namespaces with the same function name.
// if not specified, the linker will complain about the ambiguity like below:
// ld: Undefined symbols:
//  __Z11doSomethingii, referenced from:
//       _main in ccX1VYcw.o
// collect2: error: ld returned 1 exit status

int main() {
    // std::cout << doSomething(4, 3) << '\n';
    std::cout << Add::doSomething(4, 3) << '\n';
    std::cout << Subtract::doSomething(4, 3) << '\n';
    return 0;
}

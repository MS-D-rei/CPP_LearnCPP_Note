#include "add.h" // this uses the add.h header file to declare the add() function
#include <iostream>

#define PRINT_JOE

// int add(int x, int y); // forward declaration of add() (using a function prototype)

void doSomething();

int main()
{
	std::cout << "3 + 4 is: " << add(3, 4) << '\n';
	doSomething();

	return 0;
};

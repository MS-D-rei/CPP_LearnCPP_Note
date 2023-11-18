#include <iostream>

// proprocessor directives

void doSomething()
{
	#ifdef PRINT_JOE
		std::cout << "Printing" << "\n";
	#endif
	#ifndef PRINT_JOE
		std::cout << "Not printing" << "\n";
	#endif
}

#include <iostream>

void noReturn(int x)
{
	std::cout << "The value of x is " << x << "\n";	
}

int main()
{
	noReturn(5);
	return 0;
}

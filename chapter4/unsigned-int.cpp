/* 
 * Many developers (and some large development houses, such as Google) believe that 
 * developers should generally avoid unsigned integers.
 * 
 * 1. First, with signed values, it takes a little work to accidentally overflow 
 * the top or bottom of the range because those values are far from 0. 
 * With unsigned numbers, it is much easier to overflow the bottom of the range, 
 * because the bottom of the range is 0, which is close to where the majority of our values are.
 *
 * 2. Second, and more insidiously, unexpected behavior can result 
 * when you mix signed and unsigned integers. 
 * In C++, if a mathematical operation (e.g. arithmetic or comparison) 
 * has one signed integer and one unsigned integer, 
 * the signed integer will usually be converted to an unsigned integer. 
 * And the result will thus be unsigned. 
 *
 * */
#include <iostream>

int main()
{
    // first example
    // accidentally overflowed the bottom of the range
    unsigned int x{ 2 };
    unsigned int y{ 3 };
    std::cout << "x - y is " << x - y << "\n"; // will print 4294967295

    // second example
    // signed int will be converted to unsigned int
    unsigned int a{ 2 };
    signed int b{ 3 };
    std::cout << "a - b is " << a - b << "\n"; // will print 4294967295
    return 0;
}

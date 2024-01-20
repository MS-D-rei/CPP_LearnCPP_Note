#include "date.h"

#include <iostream>

// the compiler typically needs to see the full definition of a class (or any
// program-defined type) in order for the type to be used.
// This is because the compiler needs to understand how members are declared in
// order to ensure they are used properly, and it needs to be able to calculate
// how large objects of that type are in order to instantiate them.

// multi line member function =>
// put the function declaration in the header file.
// put the function definition in the source file.
// single line member function =>
// put the function declaration and definition in the header file.

// why don't we put the function definition in the header file?
// => 1. it makes the class not easy to read.
// 2. separate the interface from the implementation. member function
// declaration is the interface, member function definition is the
// implementation. If we put the definition in the header file and we change
// header file, we have to recompile all the source files that include the
// header file. If we put the definition in the source file, we only need to
// recompile the source file that includes the header file.

Date::Date(int year, int month, int day)
    : m_year{year}, m_month{month}, m_day{day} {}

void Date::print() const {
    std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
}

void Date::setDate(int year, int month, int day) {
    m_year = year;
    m_month = month;
    m_day = day;
}

int main() {
    Date today{2024, 1, 24};
    today.print();
    today.setDate(2024, 1, 25);
    today.print();
    return 0;
}

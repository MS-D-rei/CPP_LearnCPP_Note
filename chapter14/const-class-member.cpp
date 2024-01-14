#include <iostream>

// const member function
// A member function that does not (and will not ever) modify the state of the
// object should be made const, so that it can be called on both const and
// non-const objects.

struct Date {
    int year{};
    int month{};
    int day{};

    // void print() { std::cout << year << '/' << month << '/' << day << '\n'; }
    void print() const {
        std::cout << year << '/' << month << '/' << day << '\n';
    }

    // Cannot assign to non-static data member within const member function
    // 'incrementDay' [typecheck_assign_const]
    // => const member function cannot modify non-static data member
    // void incrementDay() const { ++day; }
};

void printDate(const Date& date) { date.print(); }

int main() {
    const Date oneDay{2019, 2, 13};
    // 'this' argument to member function 'print' has type 'const Date', but
    // function is not marked const [member_function_call_bad_cvr]
    // => const object can only call const member function
    // oneDay.print();
    oneDay.print();

    // oneDay.incrementDay();

    Date anotherDay{2019, 2, 14};
    // const member function can be called by non-const object
    oneDay.print();

    printDate(oneDay);
    printDate(anotherDay);

    return 0;
}

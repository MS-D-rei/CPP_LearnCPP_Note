#include <iostream>
#include <string>
#include <string_view>

// In C++, it is a common convention to name private data members starting with
// an “m_” prefix.
// This is done for a couple of important reasons.
// 1. This helps make it clear that this function is changing the state of the
// class. And that is important because when we change the value of a data
// member, it persists beyond the scope of the member function (whereas changes
// to function parameters or local variables typically do not).
// 2. This helps avoid naming conflicts between data members and function
// parameters or local variables.

class Date {
   public:
    void print() const {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

   private:
    int m_year{2024};
    int m_month{1};
    int m_day{14};
};

class Person {
   private:
    std::string m_name{};

   public:
    void setName(const std::string_view name) { m_name = name; }
    void greet(const Person& other) const {
        std::cout << "Hi " << other.m_name << "! My name is " << m_name
                  << ".\n";
    }
};

int main() {
    // can't use aggregate initialization
    // an aggregate can have only public data members.
    // Our Date class has private data members (because the members of classes
    // are private by default), so our Date class does not qualify as an
    // aggregate.
    // const Date date{2024, 2, 14};
    const Date oneDay{};
    oneDay.print();

    Person alex{};
    alex.setName("Alex");

    Person bob{};
    bob.setName("Bob");

    // class access level works on class level, not object level
    // that's why alex can access private member of bob
    alex.greet(bob);

    return 0;
}

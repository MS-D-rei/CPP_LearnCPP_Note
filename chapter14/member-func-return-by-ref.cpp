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

// Don't return a non-const reference to a private data member.
// This allows the caller to modify the private data member, which is
// undesirable.

class Employee {
   private:
    std::string m_name{};

   public:
    // a member function returning a ref should return the same type of the
    // data member being returned.
    // in this case, m_name is a std::string, so we should return a
    // std::string, not a std::string_view.
    // if we return a std::string_view, a temporary std::string_view will be
    // created every time the function is called. inefficient.
    // `auto` is a useful way not to occur conversion, but it's not recommended
    // because it's not clear what type is returned.
    const std::string& getName() const { return m_name; }
    void setName(const std::string_view name) { m_name = name; }
};

// returns an Employee by value, it means the returned value is a rvalue.
Employee createEmployee(const std::string_view name) {
    Employee employee{};
    employee.setName(name);
    return employee;
}

int main() {
    Employee alex{};
    alex.setName("Alex");

    std::cout << alex.getName() << '\n';

    // Best practice:
    // prefer to use rvalue class object immediately, or create a local
    // variable to store the rvalue class object.

    // case 1: use rvalue class object immediately.
    // okay: use rvalue class object in the same full expression.
    std::cout << createEmployee("Frank").getName() << '\n';

    // case 2: create a reference for use later.
    // bad: after createEmployee() ends, the returned rvalue object is
    // destroyed. the reference is now dangling.
    const std::string& ref{createEmployee("Max").getName()};
    std::cout << ref << '\n';

    // case 3: use rvalue class object to initialize a local variable,
    // not a reference.
    // okay: rvalue class object is copied to local variable, so when
    // rvalue object is destroyed, the local variable is still alive.
    std::string str{createEmployee("John").getName()};
    std::cout << str << '\n';

    return 0;
}

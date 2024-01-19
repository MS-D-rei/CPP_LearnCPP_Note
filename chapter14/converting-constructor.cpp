#include <iostream>
#include <string>
#include <string_view>

// Best Practice:
// Make any constructor that accepts a single argument explicit by default.
// If an implicit conversion between types is both semantically equivalent and
// performant, you can consider making the constructor non-explicit.

class Employee {
   private:
    std::string m_name{};

   public:
    // prevent implicit conversion from std::string_view to Employee
    explicit Employee(std::string_view name) : m_name{name} {}

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee employee) {
    std::cout << employee.getName() << '\n';
}

int main() {
    // implicit conversion can do only one conversion.
    // this cannot be compiled because this needs 2 conversions.
    // c-style string -> std::string_view -> Employee
    // printEmployee("John Doe");

    // this works because this needs only one conversion.
    printEmployee(Employee{"John Doe"});

    // this does not work because Employee constructor is explicit.
    // printEmployee(std::string_view{"Jane Doe"});
    return 0;
}

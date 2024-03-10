#include <iostream>
#include <string>
#include <string_view>

// If you have multiple constructors, consider whether you can use delegating
// constructors to reduce duplicate code.

class Employee {
   private:
    std::string m_name{};
    int m_id{};

   public:
    // delegating constructor
    // a constructor that delegates to another constructor is not allowed to do
    // any member initialization itself.
    Employee(std::string_view name) : Employee{name, 0} {}
    // It is common to have the constructor with fewer parameters delegate to
    // the constructor with more parameters.
    Employee(std::string_view name, int id) : m_name{name}, m_id{id} {
        std::cout << "Employee " << m_name << " created.\n";
    }
};

class Employee2 {
   private:
    std::string m_name{};
    int m_id{};

   public:
    // Reducing constructor using default parameters.
    Employee2(std::string_view name, int id = 0) : m_name(name), m_id(id) {
        std::cout << "Employee " << m_name << " created.\n";
    }
};

int main() {
    Employee alex{"Alex"};
    Employee joe{"Joe", 42};

    return 0;
}

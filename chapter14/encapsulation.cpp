#include <iostream>
#include <string>
#include <string_view>

class Employee {
   private:
    std::string m_name{};
    char m_firstInitial{};

   public:
    void setName(std::string_view name) {
        m_name = name;
        m_firstInitial = name.front();
    }

    void printName() { std::cout << "Employee: " << m_name << '\n'; }

    void printFirstInitial() {
        std::cout << "First initial: " << m_firstInitial << '\n';
    }
};

int main() {
    Employee employee{};
    employee.setName("John Doe");
    employee.printName();
    employee.printFirstInitial();
    return 0;
}

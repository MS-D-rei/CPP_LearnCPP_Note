#include <iostream>

class Department {
   private:
    int m_id{};
    int m_managerId{};

   public:
    Department(int id, int managerId) : m_id{id}, m_managerId{managerId} {}

    int getId() const { return m_id; }
    int getManagerId() const { return m_managerId; }

    // can use this->m_id instead of m_id but it's not recommended.
    void setId(int id) { this->m_id = id; }
    void setManagerId(int managerId) { this->m_managerId = managerId; }
};

void printDepartment(const Department& department) {
    std::cout << "Department id: " << department.getId() << '\n';
    std::cout << "Department manager id: " << department.getManagerId() << '\n';
}

class Calc {
   private:
    int m_value{};

   public:
    Calc(int value) : m_value{value} {}

    Calc& add(int value) {
        m_value += value;
        return *this;
    }

    Calc& sub(int value) {
        m_value -= value;
        return *this;
    }

    Calc& mult(int value) {
        m_value *= value;
        return *this;
    }

    Calc& div(int value) {
        m_value /= value;
        return *this;
    }

    int getValue() const { return m_value; }
};

void printCalc(const Calc& calc) {
    std::cout << "Calc value: " << calc.getValue() << '\n';
}

int main() {
    Department accountDept{10, 20};

    accountDept.setId(20);
    accountDept.setManagerId(40);

    printDepartment(accountDept);

    Calc calc{10};
    // each method return *this so we can chain them.
    calc.add(10).sub(1).mult(2);

    printCalc(calc);

    return 0;
}

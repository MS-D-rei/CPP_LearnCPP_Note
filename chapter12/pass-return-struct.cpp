#include <iostream>

struct Employee {
    int id;
    int age;
    double wage;
};

void printEmployeeInfo(const Employee& employee) {
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct Point3d {
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

Point3d getZeroPoint() {
    return {};  // equivalent to Point3d{0.0, 0.0, 0.0
}

int main() {
    Employee joe{14, 32, 24.15};
    Employee frank{15, 28, 18.27};

    printEmployeeInfo(joe);

    std::cout << '\n';

    printEmployeeInfo(frank);

    std::cout << '\n';

    Point3d zeroCoordinate{getZeroPoint()};
    std::cout << "The zero point is: " << zeroCoordinate.x << ", "
              << zeroCoordinate.y << ", " << zeroCoordinate.z << '\n';

    return 0;
}

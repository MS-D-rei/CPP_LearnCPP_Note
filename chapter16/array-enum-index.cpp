#include <iostream>
#include <vector>

namespace Students {
enum Names {
    kenny,
    kyle,
    stan,
    cartman,
    max_students
};
}

// scoped enum cannot be used as array index.
// Because scoped enum has no implicit conversion to integral type.
enum class Students2 {
    kenny,
    kyle,
    stan,
    cartman,
    max_students
};

int main() {
    // Create an array to store the number of students in each class.
    std::vector<int> testScores(Students::max_students);
    std::cout << "This class has " << testScores.size() << " students\n";

    testScores[Students::kenny] = 76;

    std::cout << "Kenny scored " << testScores[Students::kenny] << '\n';

    return 0;
}

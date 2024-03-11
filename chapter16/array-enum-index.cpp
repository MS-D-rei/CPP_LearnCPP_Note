#include <iostream>
#include <type_traits>
#include <vector>

// Enum helps to indicates the meaning of the index.
// 1. In terms of scope, scoped enum is better than unscoped enum.
// 2. But scoped enum has no implicit conversion to integral type.
// 3. static_cast will convert but it also clutters the code.
// 4. Helper function helps to make the code cleaner.
// 5. If there are many enums, it's probably better to use unscoped enum with
// namespace.

namespace Students {
enum Names { kenny, kyle, stan, cartman, max_students };
}

// scoped enum cannot be used as array index.
// Because scoped enum has no implicit conversion to integral type.
// To address this, use static_cast to convert the enumerator to an integer.
enum class Students2 { kenny, kyle, stan, cartman, max_students };

// helper function to convert the enumerator to an integer.
constexpr auto operator+(Students2 e) {
    return static_cast<std::underlying_type_t<Students2>>(e);
}

int main() {
    // Create an array to store the number of students in each class.
    std::vector<int> testScores(Students::max_students);
    std::cout << "1st class has " << testScores.size() << " students\n";
    testScores[Students::kenny] = 76;
    std::cout << "Kenny in 1st class scored " << testScores[Students::kenny]
              << '\n';

    // Complie error: no conversion from Students2 to
    // std::size_t(std::vector<int>::size_type) std::vector<int>
    // testScores2(Students2::max_students);
    std::vector<int> testScores2(static_cast<int>(Students2::max_students));
    testScores2[static_cast<int>(Students2::kyle)] = 90;
    std::cout << "Kyle in 2nd class scored "
              << testScores2[static_cast<int>(Students2::kyle)] << '\n';

    // static_cast clutters the code.
    // Better option is to use a helper function to convert the enumerator to an
    // integer.
    // => constexpr auto operator+(Students2 e)
    std::vector<int> testScores3(+Students2::max_students);
    testScores3[+Students2::stan] = 88;
    std::cout << "Stan in 3rd class scored " << testScores3[+Students2::stan]
              << '\n';

    return 0;
}

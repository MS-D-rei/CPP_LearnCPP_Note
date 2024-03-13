#include <array>
#include <iostream>
#include <string_view>

struct House {
    int number;
    int stories;
    int roomsPerStory;
};

struct Student {
    int id;
    std::string_view name;
};

// Only length of array is template parameter.
template <std::size_t N>
const Student* findStudentById(const std::array<Student, N>& students, int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            return &student;
        }
    }
    return nullptr;
}

int main() {
    // constexpr std::array<House, 3> houses{House{1, 2, 4}, House{2, 3, 5},
    //                                       House{3, 1, 3}};
    // Extra set of braces is required to initialize C-style array member inside
    // std::array.
    constexpr std::array<House, 3> houses{{{1, 2, 4}, {2, 3, 5}, {3, 1, 3}}};

    for (const auto& house : houses) {
        std::cout << "House #" << house.number << " has " << house.stories
                  << " stories and " << house.roomsPerStory
                  << " rooms per story.\n";
    }

    constexpr std::array<Student, 3> students{
        {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}}};

    const Student* student1{findStudentById(students, 1)};
    std::cout << "Student 1: " << (student1 ? student1->name : "not found")
              << '\n';

    const Student* student4{findStudentById(students, 4)};
    std::cout << "Student 4: " << (student4 ? student4->name : "not found")
              << '\n';

    return 0;
}

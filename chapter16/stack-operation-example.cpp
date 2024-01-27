#include <iostream>
#include <limits>
#include <vector>

int main() {
    std::vector<int> scoreList{};

    while (true) {
        std::cout << "Enter a score (-1 to quit): ";
        int score{};
        std::cin >> score;

        if (!std::cin) {
            std::cout << "Invalid score. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (score == -1) {
            break;
        }

        scoreList.push_back(score);
    }

    std::cout << "The scores are:\n";

    for (const auto& score : scoreList) {
        std::cout << score << ' ';
    }

    std::cout << '\n';

    return 0;
}

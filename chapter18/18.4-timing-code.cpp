#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <numeric>  // std::iota
#include <utility>

const int g_arrayElements{10000};

class Timer {
   public:
    void reset() { m_begin = SteadyClock::now(); }
    // in seconds
    double elapsed() const {
        return std::chrono::duration_cast<Second>(SteadyClock::now() - m_begin)
            .count();
    }

   private:
    using SteadyClock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<SteadyClock> m_begin{SteadyClock::now()};
};

void sortArray(std::array<int, g_arrayElements>& array) {
    for (std::size_t startIndex{0}; startIndex < (g_arrayElements - 1);
         ++startIndex) {
        std::size_t smallestIndex{startIndex};
        for (std::size_t currentIndex{startIndex + 1};
             currentIndex < g_arrayElements; ++currentIndex) {
            if (array[currentIndex] < array[smallestIndex]) {
                smallestIndex = currentIndex;
            }
        }
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

int main() {
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1);

    Timer timer;

    sortArray(array);

    std::cout << "Time taken: " << timer.elapsed() << " seconds" << '\n';

    return 0;
}

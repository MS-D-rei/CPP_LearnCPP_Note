#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <numeric>
#include <ratio>

const int g_arrayElements{10000};

class Timer {
   public:
    void reset() { m_begin = SteadyClock::now(); };
    double elapsed() const {
        return std::chrono::duration_cast<Second>(SteadyClock::now() - m_begin)
            .count();
    };

   private:
    using SteadyClock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<SteadyClock> m_begin{SteadyClock::now()};
};

int main() {
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1);

    Timer timer;

    // Since C++20
    // std::ranges::sort(array);

    std::sort(array.begin(), array.end());

    std::cout << "Time taken: " << timer.elapsed() << " seconds" << '\n';

    return 0;
}

#include <chrono>
#include <iostream>
#include <random>

int main() {
    // Same seed makes same sequence of random numbers
    // std::mt19937 mt{};

    // Seed out Mersenne Twister using steady_clock
    // std::mt19937 mt{static_cast<std::mt19937::result_type>(
    //     std::chrono::steady_clock::now().time_since_epoch().count())};
    // Downside: If we run the program multiple times in the same second, we
    // will get the same sequence of random numbers. It can impact the quality.

    // random_device is an implementation-defined random number generator.
    // Normally, we avoid implementation-defined behavior, but random_device
    // is one of the exceptions.
    // std::random_device will ask the OS for a random number.
    // How it does depends on the OS.
    // std::random_device rd{}; => rd.operator()
    // Mersenne Twister is 624 bytes in size. and random_device is 4 bytes.
    // So this is significantly underseeding.
    // std::mt19937 mt{std::random_device{}()};

    std::random_device rd{};
    // get 8 intergers from random_device
    // remaining numbers (624 - 4 * 8 = 592) are generated by seed_seq
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{seed};

    // Create a reusable random number generator that generates uniform numbers
    std::uniform_int_distribution die6{1, 6};

    for (int count{1}; count <= 40; ++count) {
        // mt() is a concise syntax for mt.operator()
        std::cout << die6(mt) << '\t';

        if (count % 10 == 0) {
            std::cout << '\n';
        }
    }

    return 0;
}

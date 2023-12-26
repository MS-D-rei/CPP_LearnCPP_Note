#include <iostream>
#include <random>

// Peudo-random number generator
// The numbers generated PRNG is not random at all.
// It is deterministic, meaning that given the same seed, it will produce the
// same sequence of numbers every time.

// the length of the sequence before a PRNG repeats itself is called period.
// All PRNGs have a period.

// Many PRNGs are now considered relatively poor by modern standards.

// What makes a good PRNG?
// 1. Distribution uniformity
// 2. The length of the period
// 3. Predictability

// Linear congruential generator (LCG)
// https://en.wikipedia.org/wiki/Linear_congruential_generator#Parameters_in_common_use

// Mersenne Twister
// This is fine in terms of performance and quality.
// However, this is a bit outdated.
// Because the result can be predicted after seeing 624 consecutive numbers.

// for illustrative purposes only.
unsigned int LCG16() {
    static unsigned int s_state{5323};  // 4 bytes
    // std::cout << "s_state size: " << sizeof(s_state) << '\n';

    s_state = 8253729 * s_state + 2396403;
    return s_state % 32768;
}

int main() {
    // for (int count{1}; count <= 100; ++count) {
    //     std::cout << LCG16() << '\t';
    //
    //     if (count % 10 == 0) {
    //         std::cout << '\n';
    //     }
    // }

    // for (int count{1}; count <= 100; ++count) {
    //     std::cout << std::mt19937() << '\t';
    //
    //     if (count % 10 == 0) {
    //         std::cout << '\n';
    //     }
    // }

    std::cout << std::mt19937() << '\n';

    return 0;
}

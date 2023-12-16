#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> me{0b000'0101};
    std::cout << me << '\n';  // 00000101

    me.set(3);    // set bit position 3 to 1 (on)
    me.flip(4);   // flip bit position 4 (from 0 to 1, or from 1 to 0)
    me.reset(4);  // set bit position 4 to 0 (off)

    std::cout << me << '\n';                                 // 00001101
    std::cout << "bit 3 has value: " << me.test(3) << '\n';  // 1
    std::cout << "bit 4 has value: " << me.test(4) << '\n';  // 0

    [[maybe_unused]] constexpr int isHungry{0};
    [[maybe_unused]] constexpr int isSad{1};
    [[maybe_unused]] constexpr int isMad{2};
    [[maybe_unused]] constexpr int isHappy{3};
    [[maybe_unused]] constexpr int isLaughing{4};
    [[maybe_unused]] constexpr int isAsleep{5};
    [[maybe_unused]] constexpr int isDead{6};
    [[maybe_unused]] constexpr int isCrying{7};

    std::bitset<8> me2{0b0000'0000};
    me2.set(isHappy);
    me2.flip(isLaughing);
    me2.reset(isLaughing);

    std::cout << me2 << '\n';                                        // 00001000
    std::cout << "I am happy? " << me2.test(isHappy) << '\n';        // 1
    std::cout << "I am laughing? " << me2.test(isLaughing) << '\n';  // 0

    // std::bitset is optimized for speed, not memory savings.
    std::cout << sizeof(me2) << '\n';  // 8 (8 bytes = 64 bits)

    std::cout << me2.count()
              << " bits are set to true\n";  // 1 (count how many bits are on)
    std::cout << me2.size()
              << " bits are in the bitset\n";  // 8 (count how many bits there
                                               // are in total)
    std::cout << me2.flip() << '\n';           // 11110111 (flip every bit)
    std::cout << me2.flip()
              << '\n';  // 00001000 (flip every bit back to original state)

    return 0;
}

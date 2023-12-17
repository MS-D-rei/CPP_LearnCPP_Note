#include <bitset>
#include <cstdint>
#include <iostream>

// when bitmask is useful
// 1. when you want to store multiple boolean values in a single variable
// and make it easy to read and write to those values
// for example, function below has 32 boolean parameters. It's hard to read
// void someFunction(bool option1, bool option2, bool option3, bool option4,
// bool option5, bool option6, bool option7, bool option8, bool option9, bool
// option10, bool option11, bool option12, bool option13, bool option14, bool
// option15, bool option16, bool option17, bool option18, bool option19, bool
// option20, bool option21, bool option22, bool option23, bool option24, bool
// option25, bool option26, bool option27, bool option28, bool option29, bool
// option30, bool option31, bool option32);
// bitwise flags makes it easier to read and write like this:
// void someFunction(std::uint32_t options);
// someFunction(isHungry | isHappy | isLaughing); // turn on bits 0, 3, and 4
// 2. performance
// 3. when you want to store a set of values that might overlap
// for example, here are 100 people and they have 8 different statuses.
// it takes 800 bytes to store all the statuses. (if we use uint8_t)
// But if we use bitmasks, it only takes 100 + 8 bytes to store all the
// statuses.

int main() {
    [[maybe_unused]] constexpr std::uint8_t isHungry{0b0000'0001};    // 1
    [[maybe_unused]] constexpr std::uint8_t isSad{0b0000'0010};       // 2
    [[maybe_unused]] constexpr std::uint8_t isMad{0b0000'0100};       // 4
    [[maybe_unused]] constexpr std::uint8_t isHappy{0b0000'1000};     // 8
    [[maybe_unused]] constexpr std::uint8_t isLaughing{0b0001'0000};  // 16
    [[maybe_unused]] constexpr std::uint8_t isAsleep{0b0010'0000};    // 32
    [[maybe_unused]] constexpr std::uint8_t isDead{0b0100'0000};      // 64
    [[maybe_unused]] constexpr std::uint8_t isCrying{0b1000'0000};    // 128

    // hexadecimal way
    // [[maybe_unused]]constexpr std::uint8_t mask0_hex{ 0x01 }; // 1
    // [[maybe_unused]]constexpr std::uint8_t mask1_hex{ 0x02 }; // 2
    // [[maybe_unused]]constexpr std::uint8_t mask2_hex{ 0x04 }; // 4
    // [[maybe_unused]]constexpr std::uint8_t mask3_hex{ 0x08 }; // 8
    // [[maybe_unused]]constexpr std::uint8_t mask4_hex{ 0x10 }; // 16
    // [[maybe_unused]]constexpr std::uint8_t mask5_hex{ 0x20 }; // 32
    // [[maybe_unused]]constexpr std::uint8_t mask6_hex{ 0x40 }; // 64
    // [[maybe_unused]]constexpr std::uint8_t mask7_hex{ 0x80 }; // 128

    // easier way
    // [[maybe_unused]]constexpr std::uint8_t mask0{ 1 << 0 }; // 1
    // [[maybe_unused]]constexpr std::uint8_t mask1{ 1 << 1 }; // 2
    // [[maybe_unused]]constexpr std::uint8_t mask2{ 1 << 2 }; // 4
    // [[maybe_unused]]constexpr std::uint8_t mask3{ 1 << 3 }; // 8
    // [[maybe_unused]]constexpr std::uint8_t mask4{ 1 << 4 }; // 16
    // [[maybe_unused]]constexpr std::uint8_t mask5{ 1 << 5 }; // 32
    // [[maybe_unused]]constexpr std::uint8_t mask6{ 1 << 6 }; // 64
    // [[maybe_unused]]constexpr std::uint8_t mask7{ 1 << 7 }; // 128

    std::uint8_t flags{0b0000'0101};
    std::cout << "init bits: " << std::bitset<8>{flags} << '\n';

    std::cout << "bit 0 is "
              << (static_cast<bool>(flags & isHungry) ? "on\n" : "off\n");
    std::cout << "bit 1 is "
              << (static_cast<bool>(flags & isSad) ? "on\n" : "off\n");

    // setting a bit
    flags |= isSad;  // turn on bit 1
    std::cout << "bit 1 is "
              << (static_cast<bool>(flags & isSad) ? "on\n" : "off\n");
    flags |= (isLaughing | isAsleep);  // turn on bits 4 and 5
    std::cout << "bit 4 is "
              << (static_cast<bool>(flags & isLaughing) ? "on\n" : "off\n");
    std::cout << "bit 5 is "
              << (static_cast<bool>(flags & isAsleep) ? "on\n" : "off\n");

    // flipping a bit
    flags ^= isAsleep;  // flip bit 5 from on to off
    std::cout << "bit 5 is "
              << (static_cast<bool>(flags & isAsleep) ? "on\n" : "off\n");

    std::cout << "all bits: " << std::bitset<8>{flags} << '\n';

    // bitset funtion changes one bit at a time
    // bitwise operators change mutiple bits at a time

    constexpr std::uint32_t redBits{0xFF000000};
    constexpr std::uint32_t greenBits{0x00FF0000};
    constexpr std::uint32_t blueBits{0x0000FF00};
    constexpr std::uint32_t alphaBits{0x000000FF};

    std::cout
        << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel;  // std::hex allows us to read in a hex value

    // use bitwise AND to isolate each color and contains it in uint8_t
    // by shifting it to the right
    std::uint8_t red{static_cast<std::uint8_t>((pixel & redBits) >> 24)};
    std::uint8_t green{static_cast<std::uint8_t>((pixel & greenBits) >> 16)};
    std::uint8_t blue{static_cast<std::uint8_t>((pixel & blueBits) >> 8)};
    std::uint8_t alpha(static_cast<std::uint8_t>((pixel & alphaBits) >> 0));

    std::cout << "Your color contains:\n";
    std::cout << std::hex;
    // std::uint8_t will be likely printed as a character
    // use static_cast<int> to print it as an integer for sure.
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    return 0;
}

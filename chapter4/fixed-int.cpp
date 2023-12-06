#include <cstdint>
#include <iostream>

// fixed-width integer types

// signed and unsigned
// std::int8_t, std::int16_t, std::int32_t, std::int64_t
// std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t

// least makes sure the type is at least size for the architecture
// std::int_least8_t, std::int_least16_t, std::int_least32_t, std::int_least64_t
// std::uint_least8_t, std::uint_least16_t, std::uint_least32_t, std::uint_least64_t

// fast makes sure the type is the fastest size for the architecture
// std::int_fast8_t, std::int_fast16_t, std::int_fast32_t, std::int_fast64_t
// std::uint_fast8_t, std::uint_fast16_t, std::uint_fast32_t, std::uint_fast64_t

int main()
{
    std::int16_t i{ 5 };
    std::cout << i << "\n";
    std::cout << sizeof(i) << " bytes\n";
}

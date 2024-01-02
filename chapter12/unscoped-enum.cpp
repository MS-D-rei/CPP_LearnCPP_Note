#include <bitset>
#include <iostream>
#include <string>

// An enumeration or enumerated type is the program-defined type itself.
// ex. State.
// An enumerator is a specific named value belonging to the enumeration.
// ex. isHungry, etc.

// Prefer putting your enumerations inside a named scope region (such as a
// namespace or class) so the enumerators don’t pollute the global namespace.

namespace Flags {
// Avoid assigning explicit values to enumerators unless you have a good reason.
enum State {
    isHungry,
    isSad,
    isMad,
    isHappy,
    isLaughing,
    isAsleep,
    isDead,
    isCrying,
};
}  // namespace Flags

constexpr std::string_view getState(Flags::State state) {
    switch (state) {
        case Flags::isHungry:
            return "isHungry";
        case Flags::isSad:
            return "isSad";
        case Flags::isMad:
            return "isMad";
        case Flags::isHappy:
            return "isHappy";
        case Flags::isLaughing:
            return "isLaughing";
        case Flags::isAsleep:
            return "isAsleep";
        case Flags::isDead:
            return "isDead";
        case Flags::isCrying:
            return "isCrying";
        default:
            return "Unknown";
    }
}

int main() {
    std::bitset<8> me{};
    me.set(Flags::isHappy);
    me.set(Flags::isLaughing);

    std::cout << std::boolalpha;

    std::cout << "I am happy? " << me.test(Flags::isHappy) << '\n';
    std::cout << "I am laughing? " << me.test(Flags::isLaughing) << '\n';

    std::cout << "me = " << me << '\n';
    std::cout << "Flags::isHappy = " << Flags::isHappy << '\n';
    std::cout << "State::isHappy = " << getState(Flags::isHappy) << '\n';

    std::cout << "Enter a state (0=Hungry, 1=Sad, 2=Mad, 3=Happy, 4=Laughing, "
                 "5=Asleep, 6=Dead, 7=Crying): ";
    int state{};
    std::cin >> state;
    std::cout << "You entered " << getState(static_cast<Flags::State>(state))
              << '\n';

    return 0;
}

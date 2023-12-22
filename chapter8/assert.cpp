#include <cassert>
#include <cmath>
#include <iostream>

// asserts vs error handling
// - The goal of an assertion is to catch programming errors by documenting
// something that should never happen. only debug build.
// - The goal of error handling is to handle user input or other situations that
// are expected to happen. both debug and release build.

// assert is also used for documenting like below.
// assert(moved && "Need to handle case where student was just moved to another
// classroom");

double calculateTimeUintilObjectHitsGround(double initialHeight,
                                           double gravity) {
    // assert(gravity > 0.0);
    // Assertion failed: (gravity > 0.0), function
    // calculateTimeUintilObjectHitsGround, file assert.cpp, line 7.

    // more descriptive trick
    assert(gravity > 0.0 && "Gravity must be a positive value.");
    // Assertion failed: (gravity > 0.0 && "Gravity must be a positive value."),
    // function calculateTimeUintilObjectHitsGround, file assert.cpp, line 12.

    if (initialHeight <= 0.0) {
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}

int main() {
    std::cout << "Took " << calculateTimeUintilObjectHitsGround(100.0, -9.8)
              << " seconds to hit the ground.\n";

    return 0;
}

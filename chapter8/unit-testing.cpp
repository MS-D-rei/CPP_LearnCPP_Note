#include <cassert>  // assert
#include <cstdlib>  // std::abort
#include <iostream>

bool isLowerVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int testVowel() {
#ifdef NDEBUG
    std::cerr << "Tests run with NDEBUG disabled\n";
    std::abort();
#endif
    assert(isLowerVowel('a'));
    assert(isLowerVowel('e'));
    assert(isLowerVowel('i'));
    assert(isLowerVowel('o'));
    assert(isLowerVowel('u'));
    assert(!isLowerVowel('b'));
    assert(!isLowerVowel('c'));
    assert(!isLowerVowel('d'));
    assert(!isLowerVowel('f'));
    assert(!isLowerVowel('g'));
    // assert(!isLowerVowel('a')); // This assertion will fail
    // Assertion failed: (!isLowerVowel('a')), function testVowel, file
    // unit-testing.cpp, line 33.

    return 0;
}

int main() {
    testVowel();
    std::cout << "All tests passed\n";
    return 0;
}

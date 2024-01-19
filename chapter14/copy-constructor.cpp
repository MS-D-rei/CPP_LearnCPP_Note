#include <iostream>

// Best practice:
// Copy constructors should have no side effects beyond copying.
// Prefer the implicit copy constructor, unless you have a specific reason to
// create your own.
// If you write your own copy constructor, the parameter should
// be a const lvalue reference.

class Fraction {
   private:
    int m_numerator{};
    int m_denominator{};

   public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator(numerator), m_denominator(denominator) {}

    // Explicit copy constructor
    // Fraction(const Fraction& fraction)
    //     : m_numerator(fraction.m_numerator),
    //       m_denominator(fraction.m_denominator) {
    //     std::cout << "Copy constructor called\n";
    // }

    void print() const {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

int main() {
    Fraction fiveThirds{5, 3};
    Fraction fCopy{fiveThirds};  // copy constructor called here
    fCopy.print();

    return 0;
}

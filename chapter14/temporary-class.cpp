#include <iostream>

class IntPair {
   private:
    int m_x{};
    int m_y{};

   public:
    IntPair(int x, int y) : m_x{x}, m_y{y} {}

    int x() const { return m_x; }
    int y() const { return m_y; }
};

void printIntPair(IntPair p) {
    std::cout << "Pair(" << p.x() << ", " << p.y() << ")\n";
}

int main() {
    IntPair pair1{3, 4};
    printIntPair(pair1);

    // Construct a temporary IntPair
    printIntPair(IntPair{5, 6});

    // Implicitly construct a temporary IntPair
    printIntPair({8, 9});

    return 0;
}

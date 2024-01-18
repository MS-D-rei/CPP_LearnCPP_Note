#include <iostream>
#include <string>
#include <string_view>

// Prefer non-member functions to member functions.
// 1. it makes the class interface smaller and easier to understand.
// 2. it must work through the public interface of the class. no direct access
// to private members.
// 3. it don't need to be considered when changing the implementation of the
// class.

class Yogurt {
   private:
    std::string m_flavor{"vanilla"};

   public:
    void setFlavor(std::string_view flavor) { m_flavor = flavor; }

    std::string_view getFlavor() const { return m_flavor; }

    // worst case: member function uses direct access to private members.
    // void print() const { std::cout << "Yogurt(" << m_flavor << ")\n"; }

    // not great case: member function uses public interface.
    // void print() const { std::cout << "Yogurt(" << getFlavor() << ")\n"; }
};

// best case: non-member function uses public interface.
void printYogurt(const Yogurt& yogurt) {
    std::cout << "Yogurt(" << yogurt.getFlavor() << ")\n";
}

int main() {
    Yogurt yogurt{};
    yogurt.setFlavor("strawberry");
    printYogurt(yogurt);
    return 0;
}

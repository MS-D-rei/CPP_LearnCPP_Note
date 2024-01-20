#include <iostream>

class Fruit {
   public:
    using IDType = int;  // IDType is a public type alias of int

    // Not enum class. because class itself is a scope.
    // Changing to an unscoped enum means we can access enumerators as
    // Fruit::apple rather than the longer Fruit::Type::apple we’d have to use
    // if the enumerator were scoped.
    // Define any nested types at the top of the class.
    // Nested types must be fully defined before they can be used.
    enum Type { apple, orange, banana };

   private:
    IDType m_id{};
    Type m_type{};
    int m_percentageEaten{};

   public:
    Fruit(int id, Type type) : m_id{id}, m_type{type} {}

    IDType getID() const { return m_id; }
    Type getType() const { return m_type; }
    int getPercentageEaten() const { return m_percentageEaten; }
};

int main() {
    Fruit apple{1, Fruit::apple};
    Fruit orange{2, Fruit::orange};
    Fruit banana{3, Fruit::banana};

    std::cout << "Apple is " << apple.getType() << '\n';
    std::cout << "Orange is " << orange.getType() << '\n';
    std::cout << "Banana is " << banana.getType() << '\n';

    return 0;
}

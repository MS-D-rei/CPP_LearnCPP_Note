#include <iostream>
#include <string>
#include <string_view>

class Yogurt {
   public:
    // constructor
    // 1. same name as the class.
    // 2. constructor dont't make any object.
    // compiler will make an object before the constructor is called.
    // and then the constructor is called on the uninitialized object.
    // 3. constructor should not be const.
    Yogurt(std::string_view flavor)
        // Member variables in a member initializer list should be listed in
        // order that they are defined in the class.
        : m_flavor{flavor}  // member initializer list
    {}

    void setFlavor(std::string_view flavor) { m_flavor = flavor; }

    std::string_view getFlavor() const { return m_flavor; }

   private:
    std::string m_flavor{};
};

void printYogurt(const Yogurt& yogurt) {
    std::cout << "Yogurt(" << yogurt.getFlavor() << ")\n";
}

int main() {
    Yogurt yogurt1{"strawberry"};
    printYogurt(yogurt1);

    const Yogurt vanillaYogurt{"vanilla"};
    printYogurt(vanillaYogurt);

    return 0;
}

#include <iostream>

// In general, it is better not to use void pointers.

int main() {
    // `void pointer` is a special type of pointer that can be
    // pointed at objects of any data type.

    int nValue{};
    float fValue{};

    struct Something {
        int n;
        float f;
    };

    Something something{19, 3.14f};

    // We have to keep track of the type of the object
    // that the void pointer is pointing to.
    void* ptr{};
    ptr = &nValue;     // valid
    ptr = &fValue;     // valid
    ptr = &something;  // valid

    // void pointer does not know the type of the object.
    // We need to cast it to the correct type before using it.

    std::cout << "Void pointer points to: " << ptr << '\n';
    std::cout << "cast void pointer: " << static_cast<Something*>(ptr)->n
              << '\n';

    Something* pSomething{static_cast<Something*>(ptr)};
    std::cout << "De-referencing casted void pointer: " << (*pSomething).n
              << '\n';

    return 0;
}

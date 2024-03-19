#include <cassert>
#include <cstddef>
#include <iostream>

class IntArray {
   public:
    IntArray(int length) : m_length{length} {
        assert(length > 0 && "IntArray length should be a positive integer");

        m_array = new int[static_cast<std::size_t>(length)];
    }
    ~IntArray() { delete[] m_array; }

    void setValue(int index, int value) { m_array[index] = value; }
    int getValue(int index) { return m_array[index]; }
    int getLength() { return m_length; }

   private:
    int* m_array{};
    int m_length{};
};

int main() {
    IntArray array(10);
    for (int count{0}; count < array.getLength(); ++count) {
        array.setValue(count, count + 1);
    }

    std::cout << "The value of element 5 is: " << array.getValue(5) << '\n';

    return 0;
}

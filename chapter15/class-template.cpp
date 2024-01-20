#include <ios>
#include <iostream>

template <typename T, typename U>
class Pair {
   private:
    T m_first{};
    U m_second{};

   public:
    Pair(const T& first, const U& second) : m_first{first}, m_second{second} {}

    bool isEqual(const Pair<T, U>& pair);
};

// when we define a member function outside of the class,
// we need to specify the template parameter list again.
template <typename T, typename U>
bool Pair<T, U>::isEqual(const Pair<T, U>& pair) {
    return (this->m_first == pair.m_first && this->m_second == pair.m_second);
}

int main() {
    Pair pair1{1, 2};
    std::cout << std::boolalpha << pair1.isEqual(Pair{1, 2}) << '\n';

    return 0;
}

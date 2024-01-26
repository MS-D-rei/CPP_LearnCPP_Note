#ifndef SIGNEDARRAYVIEW_H
#define SIGNEDARRAYVIEW_H

#include <cstddef>
template <typename T>
class SignedArrayView {
   private:
    T& m_array;

   public:
    using Index = std::ptrdiff_t;

    SignedArrayView(T& array) : m_array{array} {}

    constexpr auto& operator[](Index index) {
        return m_array[static_cast<typename T::type_size>(index)];
    }
    constexpr const auto& operator[](Index index) const {
        return m_array[static_cast<typename T::type_size>(index)];
    }

    constexpr auto ssize() const { return static_cast<Index>(m_array.size()); }
};

#endif  // SIGNEDARRAYVIEW_H

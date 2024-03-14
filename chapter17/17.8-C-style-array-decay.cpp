// Best Practice:
// - Avoid using C-style arrays in C++ code.
// - Prefer std::string_view for read-only access to a string.
// - Prefer std::string for modifiable strings.
// - Prefer std::array for non-global, constexpr arrays.
// - Prefer std::vector for non-constexpr arrays.

// What is array decay?
// => When a C-style array is evaluated, it will be converted
// to a pointer to its first element.
//
// What is the problem of array decay?
// => The size of the array is lost when it decays to a pointer.

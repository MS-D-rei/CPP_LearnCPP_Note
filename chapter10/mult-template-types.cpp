#include <iostream>

// template <typename T, typename U>
// T max(T x, U y) {
//     return (x < y) ? y : x;
// }
// warning: conversion from 'double' to 'int' may change value
// [-Wfloat-conversion]

// `auto` is a good use for an return type.

template <typename T, typename U>
auto max(T x, U y) {
    return (x < y) ? y : x;
}

// C++20 introduced abbreviated function templates.
// abbreviated function templates is preffered if C++20 is available.
// auto max(auto x, auto y) {
//     return (x < y) ? y : x;
// }

int main() {
    std::cout << max(1, 2.3) << '\n';

    return 0;
}

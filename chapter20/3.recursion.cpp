#include <iostream>
#include <vector>

// Best practice:
// Generally favor iteration over recursion.

// In general, recursion is a good choice when:
// - The recursive code is much simpler to implement than the iterative code.
// - The recursion depth is limited.
// - The iterative version of the algorithm requires managing a stack of data.
// - This is not a perfomance-critical part of the code.

void countDown(int count) {
    std::cout << "Push " << count << '\n';

    if (count > 1) {
        countDown(count - 1);
    }

    std::cout << "Pop " << count << '\n';
}

int sumTo(int sum) {
    if (sum <= 0) {
        return 0;
    }
    if (sum == 1) {
        return 1;
    }
    return sum + sumTo(sum - 1);  // 5, 4, ..., 1
}

// This fibonacci function is not very efficient.
// It calls 1205 times for 13 fibonacci numbers.
int fibonacci_1(int num, int& callCount) {
    callCount++;
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return fibonacci_1(num - 1, callCount) + fibonacci_1(num - 2, callCount);
}

// This fibonacci function is more efficient.
// It calls 35 times for 13 fibonacci numbers.
int fibonacci_2(std::size_t num, int& callCount) {
    static std::vector<int> memo{0, 1};

    callCount++;

    // if the number is already in the memo, return it
    if (num < std::size(memo)) {
        return memo[num];
    }

    memo.push_back(fibonacci_2(num - 1, callCount) +
                   fibonacci_2(num - 2, callCount));

    return memo[num];
}

int main() {
    // countDown(5);

    // std::cout << "Sum of 10: " << sumTo(10) << '\n';

    int callCount_1{0};

    for (int num{0}; num < 13; ++num) {
        std::cout << fibonacci_1(num, callCount_1) << ' ';
    }
    std::cout << '\n';

    std::cout << "fibonacci call count: " << callCount_1 << '\n';

    int callCount_2{0};

    for (int num{0}; num < 13; ++num) {
        std::cout << fibonacci_2(static_cast<std::size_t>(num), callCount_2)
                  << ' ';
    }
    std::cout << '\n';

    std::cout << "fibonacci call count with memorization: " << callCount_2
              << '\n';

    return 0;
}

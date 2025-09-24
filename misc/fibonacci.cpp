#include <cstdint>
#include <algorithm>
#include <iostream>
#include <bitset>

class FibonacciSequence {
public:
    FibonacciSequence() = default;

    constexpr uint64_t operator()() {
        if (reverse) {
            return current = std::exchange(previous, current - previous);
        } else {
            return previous = std::exchange(current, current + previous);
        }
    }

    constexpr FibonacciSequence& flip() {
        reverse ^= 1;
        return *this;
    }

private:
    bool reverse{};
    uint64_t current = 1;
    uint64_t previous = 1;
};

constexpr uint64_t convertToFibonacci(uint64_t n) {
    FibonacciSequence fib;

    uint64_t i = 0;
    while (fib() <= n && ++i);
    fib.flip();

    uint64_t result = 0;
    while (n) {
        uint64_t f = fib();
        if (f <= n) {
            result |= (1ull << i);
            n -= f;
        }
        i--;
    }

    return result;
}

constexpr uint64_t convertFromFibonacci(uint64_t n) {
    uint64_t result = 0;

    FibonacciSequence fib;
    while (n) {
        uint64_t f = fib();
        if (n & 1) {
            result += f;
        }
        n >>= 1;
    }

    return result;
}

template <uint64_t n>
void test() {
    constexpr uint64_t fib = convertToFibonacci(n);
    constexpr uint64_t r = convertFromFibonacci(fib);

    if constexpr (r != n) {
        std::cerr << "wrong result: " << n << " -> " << fib << " -> " << r << std::endl;
    }

    test<n + 1>();
}

template <>
void test<1024>() {
}

int main() {
    test<1>();

    while (true) {
        uint64_t x;
        std::cin >> x;
        uint64_t f = convertToFibonacci(x);

        std::string bin = std::bitset<64>(f).to_string();
        bin.erase(0, bin.find_first_not_of('0'));
        if (bin.empty()) {
            bin = "0";
        }

        std::cout << bin << " | " << f << " | " << (x == convertFromFibonacci(f) ? "V" : "X") << std::endl;
    }

    return 0;
}
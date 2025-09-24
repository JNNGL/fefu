#include <iostream>

int main() {
    uint32_t x;
    std::cin >> x;

    if (!(x % 3)) {
        std::cout << "Fizz";
    }
    if (!(x % 5)) {
        std::cout << "Buzz";
    }
    std::cout << std::endl;
}

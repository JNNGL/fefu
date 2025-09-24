#include <iostream>

int main() {
    uint32_t M, N;
    std::cin >> M;
    std::cin >> N;
    std::cout << (static_cast<double>(M) / N) << std::endl;
}

#include <iostream>
#include <string>

int main() {
    std::string parts[3];
    for (size_t i = 0; i < std::size(parts); i++) {
        std::cin >> parts[i];
    }

    std::cout << parts[0] << "." << parts[1] << "@" << parts[2] << ".dvfu.ru" << std::endl;
}

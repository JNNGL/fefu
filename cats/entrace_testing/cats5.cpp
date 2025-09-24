#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> candidates(3);
    for (auto& candidate : candidates) {
        std::cin >> candidate;
    }

    std::sort(candidates.begin(), candidates.end());

    std::cout << candidates[0] << std::endl;
}

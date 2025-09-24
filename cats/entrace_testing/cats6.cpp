#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int64_t A, B, t;
    input >> A >> B >> t;

    uint32_t index = 0;
    while (t >= A) {
        t -= A;
        std::swap(A, B);
        index = (index + 1) & 3;
    }

    output << "SENW"[index];
}




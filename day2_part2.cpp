#include <fstream>
#include <iostream>
#include <string>

int main() {
    int score{};

    std::ifstream input("input.txt");
    std::string data;
    std::getline(input, data);
    
    if (input.is_open()) {
        while (input) {
            if (data[2] == 'X') {
                if (data[0] == 'A') {
                    score += 3;
                } else if (data[0] == 'B') {
                    score += 1;
                } else if (data[0] == 'C') {
                    score += 2;
                }
            } else if (data[2] == 'Y') {
                score += 3;
                if (data[0] == 'A') {
                    score += 1;
                } else if (data[0] == 'B') {
                    score += 2;
                } else if (data[0] == 'C') {
                    score += 3;
                }
            } else if (data[2] == 'Z') {
                score += 6;
                if (data[0] == 'A') {
                    score += 2;
                } else if (data[0] == 'B') {
                    score += 3;
                } else if (data[0] == 'C') {
                    score += 1;
                }
            }
            std::getline(input, data);
        }
    }

    std::cout << score;
    return 0;
}

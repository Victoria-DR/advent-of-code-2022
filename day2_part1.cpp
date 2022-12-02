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
                score += 1;
                if (data[0] == 'A') {
                    score += 3;
                } else if (data[0] == 'C') {
                    score += 6;
                }
            } else if (data[2] == 'Y') {
                score += 2;
                if (data[0] == 'B') {
                    score += 3;
                } else if (data[0] == 'A') {
                    score += 6;
                }
            } else if (data[2] == 'Z') {
                score += 3;
                if (data[0] == 'C') {
                    score += 3;
                } else if (data[0] == 'B') {
                    score += 6;
                }
            }
            std::getline(input, data);
        }
    }

    std::cout << score;
    return 0;
}

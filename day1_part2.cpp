#include <fstream>
#include <iostream>
#include <string>

int main() {
    int max_calories1{};
    int max_calories2{};
    int max_calories3{};
    int calories{};

    std::ifstream input("input.txt");
    std::string data;

    if (input.is_open()) {
        while (input) {
            std::getline(input, data);
            if (data == "") {
                if (max_calories1 == 0) {
                    max_calories1 = calories;
                } else if (max_calories2 == 0) {
                    max_calories2 = calories;
                } else if (max_calories3 == 0) {
                    max_calories3 = calories;
                } else if (calories >= max_calories1) {
                    max_calories3 = max_calories2;
                    max_calories2 = max_calories1;
                    max_calories1 = calories;
                } else if (calories >= max_calories2) {
                    max_calories3 = max_calories2;
                    max_calories2 = calories;
                } else if (calories > max_calories3) {
                    max_calories3 = calories;
                }
                calories = 0;
            } else {
                calories += std::stoi(data);
            }
        }
    }

    std::cout << max_calories1 + max_calories2 + max_calories3;
    return 0;
}

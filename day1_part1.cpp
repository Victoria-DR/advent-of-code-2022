#include <fstream>
#include <iostream>
#include <string>

int main() {
    int max_calories{};
    int calories{};

    std::ifstream input("input.txt");
    std::string data;

    if (input.is_open()) {
        while (input) {
            std::getline(input, data);
            if (data == "") {
                if (calories > max_calories) {
                    max_calories = calories;
                }
                calories = 0;
            } else {
                calories += std::stoi(data);
            }
        }
    }

    std::cout << max_calories;
    return 0;
}

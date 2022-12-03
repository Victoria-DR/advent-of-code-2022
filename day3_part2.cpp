#include <fstream>
#include <iostream>
#include <string>

int get_priority(char x) {
    int ascii = int(x);
    if (ascii > 96) {
        return ascii - 96;
    } else {
        return ascii - 64 + 26;
    }
}

int find_badge(std::string data1, std::string data2, std::string data3) {
    for (int i{0}; i < data1.length(); ++i) {
        for (int j{0}; j < data2.length(); ++j) {
            if (data1.at(i) == data2.at(j)) {
                for (int k{0}; k < data3.length(); ++k) {
                    if (data2.at(j) == data3.at(k)) {
                        return get_priority(data1.at(i));
                    }
                }
            }
        }
    }
}

int main() {
    int sum{};

    std::ifstream input("input.txt");
    std::string data1;
    std::string data2;
    std::string data3;

    if (input.is_open()) {
        while (input) {
            std::getline(input, data1);
            std::getline(input, data2);
            std::getline(input, data3);

            sum += find_badge(data1, data2, data3);
        }
    }

    std::cout << sum;
    return 0;
}

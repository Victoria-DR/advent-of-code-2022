#include <fstream>
#include <iostream>
#include <string>

int main() {
    int count{};

    std::ifstream input("input.txt");
    std::string data;

    if (input.is_open()) {
        while (input) {
            std::getline(input, data);
            int e1_start{};
            int e1_end{};
            int e2_start{};
            int e2_end{};

            e1_start = std::stoi(data.substr(0, data.find("-")));
            data = data.substr(data.find("-") + 1);
            e1_end = std::stoi(data.substr(0, data.find(",")));
            data = data.substr(data.find(",") + 1);
            e2_start = std::stoi(data.substr(0, data.find("-")));
            data = data.substr(data.find("-") + 1);
            e2_end = std::stoi(data);

            if ((e1_start <= e2_start) && (e1_end >= e2_end)) {
                ++count;
            } else if ((e2_start <= e1_start) && (e2_end >= e1_end)) {
                ++count;
            } else if ((e1_start >= e2_start) && (e1_start <= e2_end)) {
                ++count;
            } else if ((e1_end >= e2_start) && (e1_end <= e2_end)) {
                ++count;
            }
        }
    }

    std::cout << count - 1;
    return 0;
}

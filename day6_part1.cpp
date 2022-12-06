#include <fstream>
#include <iostream>
#include <string>

int main() {
    int count{4};
    char last_four[4]{};

    std::ifstream input("input.txt");
    std::string data;

    std::getline(input, data);
    last_four[0] = data.at(0);
    last_four[1] = data.at(1);
    last_four[2] = data.at(2);
    last_four[3] = data.at(3);

    for (int i{4}; i < data.length(); ++i) {
        if (last_four[0] != last_four[1] && last_four[0] != last_four[2] && last_four[0] != last_four[3] && last_four[1] != last_four[2] && last_four[1] != last_four[3] && last_four[2] != last_four[3]) {
            std::cout << count;
            break;
        }
        last_four[0] = last_four[1];
        last_four[1] = last_four[2];
        last_four[2] = last_four[3];
        last_four[3] = data.at(i);
        ++count;
    }

    return 0;
}

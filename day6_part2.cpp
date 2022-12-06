#include <fstream>
#include <iostream>
#include <string>

int main() {
    int count{14};
    std::string last_fourteen;

    std::ifstream input("input.txt");
    std::string data;

    std::getline(input, data);
    last_fourteen = data.substr(0, 14);

    for (int i{1}; i < data.length(); ++i) {
        bool found{false};

        for (int j{0}; j < 14; ++j) {
            if ((last_fourteen.substr(0, j).find(last_fourteen.substr(j, 1)) != -1) || (last_fourteen.substr(j + 1).find(last_fourteen.substr(j, 1)) != -1)) {
                break;
            } else if (j == 13) {
                std::cout << count;
                found = true;
                break;
            }
        }

        if (found) {
            break;
        }

        last_fourteen = data.substr(i, 14);
        ++count;
    }

    return 0;
}

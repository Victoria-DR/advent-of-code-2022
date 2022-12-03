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

int main() {
    int sum{};

    std::ifstream input("input.txt");
    std::string data;

    if (input.is_open()) {
        while (input) {
            std::getline(input, data);
            char half[data.length() / 2]{};
            for (int i{0}; i < (data.length() / 2); ++i) {
                half[i] = data.at(i);
            }

            char common[data.length() / 2]{};
            for (int j{0}; j < (data.length() / 2); ++j) {
                for (int k{0}; k < (data.length() / 2); ++k) {
                    if (data.at(j + (data.length() / 2)) == half[k]) {
                        common[j] = data.at(j + (data.length() / 2));
                        break;
                    }
                }
            }

            char common_stripped[data.length() / 2]{};
            for (int l{0}; l < (data.length() / 2); ++l) {
                if (common[l] == '\0') {
                    continue;
                }
                for (int m{0}; m < (data.length() / 2); ++m) {
                    if (common[l] == common_stripped[m]) {
                        break;
                    } else if (m == (data.length() / 2 - 1)) {
                        common_stripped[l] = common[l];
                    }
                }
            }

            for (int n{0}; n < (data.length() / 2); ++n) {
                if (common_stripped[n] == '\0') {
                    continue;
                }
                sum += get_priority(common_stripped[n]);
            }
        }
    }

    std::cout << sum;
    return 0;
}

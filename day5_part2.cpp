#include <fstream>
#include <iostream>
#include <string>

struct crate {
    char val;
    struct crate *next;

    crate(char i_val, crate *i_next):
    val{i_val},
    next{i_next} {
    }

    void print() {
        std::cout << val;
    }
} ;

struct stack {
    struct crate *top;

    stack():
    top{nullptr} {
    }

    void add(struct crate* new_crate) {
        new_crate -> next = top;
        top = new_crate;
    }

    struct crate* remove() {
        struct crate *temp{top};
        top = top -> next;
        return temp;
    }

    void print() {
        struct crate *current{top};

        while (current != nullptr) {
            current -> print();
            current = current -> next;
        }
        std::cout << std::endl;
    }
} ;

struct stack setup(char *crates, int length) {
    struct stack output{};
    for (int i{0}; i < length; ++i) {
        output.add(new crate(crates[i], nullptr));
    }
    return output;
}

int main() {
    std::ifstream input("input.txt");
    std::string data;

    struct stack stack1 = setup(new char[7]{'G', 'D', 'V', 'Z', 'J', 'S', 'B'}, 7);
    struct stack stack2 = setup(new char[6]{'Z', 'S', 'M', 'G', 'V', 'P'}, 6);
    struct stack stack3 = setup(new char[8]{'C', 'L', 'B', 'S', 'W', 'T', 'Q', 'F'}, 8);
    struct stack stack4 = setup(new char[8]{'H', 'J', 'G', 'W', 'M', 'R', 'V', 'Q'}, 8);
    struct stack stack5 = setup(new char[7]{'C', 'L', 'S', 'N', 'F', 'M', 'D'}, 7);
    struct stack stack6 = setup(new char[4]{'R', 'G', 'C', 'D'}, 4);
    struct stack stack7 = setup(new char[8]{'H', 'G', 'T', 'R', 'J', 'D', 'S', 'Q'}, 8);
    struct stack stack8 = setup(new char[3]{'P', 'F', 'V'}, 3);
    struct stack stack9 = setup(new char[5]{'D', 'R', 'S', 'T', 'J'}, 5);

    if (input.is_open()) {
        for (int i{0}; i < 10; ++i) {
            std::getline(input, data);
        }

        std::getline(input, data);

        while (input) {
            int crates_to_move = stoi(data.substr(5, data.find("from") - 6));
            data = data.substr(5 + data.find("from"));
            char from = data.at(0);
            char to = data.at(5);
            
            struct stack *from_stack{nullptr};
            struct stack *to_stack{nullptr};

            switch (from) {
                case '1':
                    from_stack = &stack1;
                    break;
                case '2':
                    from_stack = &stack2;
                    break;
                case '3':
                    from_stack = &stack3;
                    break;
                case '4':
                    from_stack = &stack4;
                    break;
                case '5':
                    from_stack = &stack5;
                    break;
                case '6':
                    from_stack = &stack6;
                    break;
                case '7':
                    from_stack = &stack7;
                    break;
                case '8':
                    from_stack = &stack8;
                    break;
                case '9':
                    from_stack = &stack9;
                    break;
            }

            switch (to) {
                case '1':
                    to_stack = &stack1;
                    break;
                case '2':
                    to_stack = &stack2;
                    break;
                case '3':
                    to_stack = &stack3;
                    break;
                case '4':
                    to_stack = &stack4;
                    break;
                case '5':
                    to_stack = &stack5;
                    break;
                case '6':
                    to_stack = &stack6;
                    break;
                case '7':
                    to_stack = &stack7;
                    break;
                case '8':
                    to_stack = &stack8;
                    break;
                case '9':
                    to_stack = &stack9;
                    break;
            }

            struct stack moved{};
            for (int j{0}; j < crates_to_move; ++j) {
                moved.add(from_stack -> remove());
            }
            for (int j{0}; j < crates_to_move; ++j) {
                to_stack -> add(moved.remove());
            }

            std::getline(input, data);
        }
    }

    stack1.top -> print();
    stack2.top -> print();
    stack3.top -> print();
    stack4.top -> print();
    stack5.top -> print();
    stack6.top -> print();
    stack7.top -> print();
    stack8.top -> print();
    stack9.top -> print();

    return 0;
}

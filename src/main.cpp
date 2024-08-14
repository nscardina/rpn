#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>


#include "Operation.hpp"

int main(int argc, char* argv[]) {
    std::stack<NumberType> numbers;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (std::all_of(arg.begin(), arg.end(), 
            [](unsigned char character){ return std::isdigit(character); })
        ) {
            numbers.emplace(std::stod(arg));
        }
        else {
            try {
                Operation::apply(numbers, arg);
            } catch (std::runtime_error error) {
                std::cerr << error.what();
                std::exit(-1);
            }
        }
    }

    if (numbers.size() == 1) {
        std::cout << numbers.top() << std::endl;
        std::exit(0);
    } else {
        std::cerr << "Error: " << numbers.size() << " unused arguments";
        while (numbers.size() > 0) {
            std::cerr << " '" << numbers.top() << "'";
            numbers.pop();
        }
    }
}
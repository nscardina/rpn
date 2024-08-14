#include "Operation.hpp"

#include <stdexcept>
#include <cmath>

namespace {
    void handle_add(std::stack<NumberType>& numbers) {
        // Binary operation - need 2 arguments
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top();
            numbers.pop();
            auto arg1 = numbers.top();
            numbers.pop();

            numbers.emplace(arg1 + arg2);
        } else {
            throw std::runtime_error(std::string("Too few arguments for addition; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_subtract(std::stack<NumberType>& numbers) {
        // Binary operation - need 2 arguments
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top();
            numbers.pop();
            auto arg1 = numbers.top();
            numbers.pop();

            numbers.emplace(arg1 - arg2);
        } else {
            throw std::runtime_error(std::string("Too few arguments for subtraction; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_multiply(std::stack<NumberType>& numbers) {
        // Binary operation - need 2 arguments
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top();
            numbers.pop();
            auto arg1 = numbers.top();
            numbers.pop();

            numbers.emplace(arg1 * arg2);
        } else {
            throw std::runtime_error(std::string("Too few arguments for multiplication; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_divide(std::stack<NumberType>& numbers) {
        // Binary operation - need 2 arguments
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top();
            numbers.pop();
            auto arg1 = numbers.top();
            numbers.pop();

            numbers.emplace(arg1 / arg2);
        } else {
            throw std::runtime_error(std::string("Too few arguments for division; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_pow(std::stack<NumberType>& numbers) {
        // Binary operation - need 2 arguments
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top(); // power
            numbers.pop();
            auto arg1 = numbers.top(); // base
            numbers.pop();

            numbers.emplace(std::pow(arg1, arg2));
        } else {
            throw std::runtime_error(std::string("Too few arguments for exponentiation; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_sqrt(std::stack<NumberType>& numbers) {
        // Unary operation - need 1 argument
        if (numbers.size() >= 1) {
            auto arg = numbers.top();
            numbers.pop();

            numbers.emplace(std::sqrt(arg));
        } else {
            throw std::runtime_error(std::string("Too few arguments for square root; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_cbrt(std::stack<NumberType>& numbers) {
        // Unary operation - need 1 argument
        if (numbers.size() >= 1) {
            auto arg = numbers.top();
            numbers.pop();

            numbers.emplace(std::cbrt(arg));
        } else {
            throw std::runtime_error(std::string("Too few arguments for cube root; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_root(std::stack<NumberType>& numbers) {
        // Unary operation - need 1 argument
        if (numbers.size() >= 2) {
            auto arg2 = numbers.top(); // power
            numbers.pop();
            auto arg1 = numbers.top(); // base
            numbers.pop();

            numbers.emplace(std::pow(arg1, 1.0 / arg2));
        } else {
            throw std::runtime_error(std::string("Too few arguments for cube root; found only ") + std::to_string(numbers.size()));
        }
    }

    void handle_percent(std::stack<NumberType>& numbers) {
        // Unary operation - need 1 argument
        if (numbers.size() >= 1) {
            auto arg = numbers.top();
            numbers.pop();

            numbers.emplace(arg / 100.0);
        } else {
            throw std::runtime_error(std::string("Too few arguments for percentage; found only ") + std::to_string(numbers.size()));
        }
    }
    
}

namespace Operation {

    void apply(std::stack<NumberType>& numbers, std::string& operation_name) {
        if (operation_name == "+" || operation_name == "add") {
            handle_add(numbers);
        }
        else if (operation_name == "-" || operation_name == "subtract") {
            handle_subtract(numbers);
        }
        else if (operation_name == "*" || operation_name == "multiply") {
            handle_multiply(numbers);
        }
        else if (operation_name == "/" || operation_name == "divide") {
            handle_divide(numbers);
        }
        else if (operation_name == "^" || operation_name == "pow") {
            handle_pow(numbers);
        }
        else if (operation_name == "sqrt") {
            handle_sqrt(numbers);
        }
        else if (operation_name == "cbrt") {
            handle_cbrt(numbers);
        }
        else if (operation_name == "root") {
            handle_root(numbers);
        }
        else if (operation_name == "%" || operation_name == "percent") {
            handle_percent(numbers);
        }


        else if (operation_name == "pi") {
            numbers.push(std::numbers::pi);
        }
        else if (operation_name == "e") {
            numbers.push(std::numbers::e);
        }
    }
};


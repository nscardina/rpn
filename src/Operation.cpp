#include "Operation.hpp"

#include <stdexcept>

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
    }
};


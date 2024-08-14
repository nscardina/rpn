#include "Operation.hpp"

#include <stdexcept>
#include <cmath>
#include <numbers>
#include <functional>
#include <initializer_list>

using namespace std::string_literals;

namespace {

    template<class T>
    inline T get_and_pop(std::stack<T>& stack) {
        T elem = stack.top();
        stack.pop();
        return elem;
    }

    void handle_unary_op(
        std::stack<NumberType>& numbers,
        std::function<NumberType(NumberType)> operation,
        std::string&& operation_name
    ) {
        if (numbers.size() >= 1) {
            numbers.emplace(operation(get_and_pop(numbers)));
        } else {
            throw std::runtime_error(
                "Too few arguments for "s
                + operation_name
                + "; found only "s
                + std::to_string(numbers.size())
            );
        }
    }

    void handle_binary_op(
        std::stack<NumberType>& numbers, 
        std::function<NumberType(NumberType, NumberType)> operation,
        std::string&& operation_name
    ) {
        if (numbers.size() >= 2) {
            auto arg2 = get_and_pop(numbers);
            auto arg1 = get_and_pop(numbers);
            numbers.emplace(operation(arg1, arg2));
        } else {
            throw std::runtime_error(
                "Too few arguments for "s
                + operation_name
                + "; found only "s
                + std::to_string(numbers.size())
            );
        }
    }

    void handle_add(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return a + b; },
            "addition"
        );
    }

    void handle_subtract(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return a - b; },
            "subtraction"
        );
    }

    void handle_multiply(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return a * b; },
            "multiplication"
        );
    }

    void handle_divide(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return a / b; },
            "division"
        );
    }

    void handle_pow(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return std::pow(a, b); },
            "exponentiation"
        );
    }

    void handle_sqrt(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::sqrt(x); },
            "square root"
        );
    }

    void handle_cbrt(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::cbrt(x); },
            "cube root"
        );
    }

    void handle_root(std::stack<NumberType>& numbers) {
        handle_binary_op(
            numbers,
            [](auto a, auto b) { return std::pow(a, 1 / b); },
            "root"
        );
    }

    void handle_percent(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return x / 100.0; },
            "percent"
        );
    }

    void handle_sin(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::sin(x); },
            "sine"
        );
    }

    void handle_cos(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::cos(x); },
            "cosine"
        );
    }

    void handle_tan(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::tan(x); },
            "tangent"
        );
    }

    void handle_arcsin(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::asin(x); },
            "arcsine"
        );
    }

    void handle_arccos(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::acos(x); },
            "arccosine"
        );
    }

    void handle_arctan(std::stack<NumberType>& numbers) {
        handle_unary_op(
            numbers,
            [](auto x) { return std::atan(x); },
            "arctangent"
        );
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
        else if (operation_name == "sin" || operation_name == "sine") {
            handle_sin(numbers);
        }
        else if (operation_name == "cos" || operation_name == "cosine") {
            handle_cos(numbers);
        }
        else if (operation_name == "tan" || operation_name == "tangent") {
            handle_tan(numbers);
        }
        else if (operation_name == "asin" || operation_name == "arcsin" || operation_name == "arcsine") {
            handle_arcsin(numbers);
        }
        else if (operation_name == "acos" || operation_name == "arccos" || operation_name == "arccosine") {
            handle_arccos(numbers);   
        }
        else if (operation_name == "atan" || operation_name == "arctan" || operation_name == "arctangent") {
            handle_arctan(numbers);
        }


        else if (operation_name == "pi") {
            numbers.push(std::numbers::pi);
        }
        else if (operation_name == "e") {
            numbers.push(std::numbers::e);
        }
    }
};


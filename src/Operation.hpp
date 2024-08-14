#ifndef OPERATION_H
#define OPERATION_H

#include <functional>
#include <stack>
#include <string>

typedef double NumberType;

namespace Operation {

    void apply(std::stack<NumberType>& numbers, std::string& operation_name);

};

#endif 
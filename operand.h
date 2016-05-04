#ifndef OPERAND_H
#define OPERAND_H

#include "expression.h"
#include <string>

class Operand: public Expression {
    public:
        explicit Operand(std::string s);
        bool get_bool();
};

#endif

#ifndef DIV_OPERAND_H
#define DIV_OPERAND_H

#include <stack>
#include <map>
#include <string>
#include "expression.h"
#include "operand.h"
#include "expression_container.h"

class DivOperand: public Operand {
    public:
        DivOperand();

        void execute(std::stack<Expression*>& exec,
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);
};

#endif

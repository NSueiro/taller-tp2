#ifndef LIST_OPERAND_H
#define LIST_OPERAND_H

#include <stack>
#include <map>
#include <string>
#include "expression.h"
#include "operand.h"
#include "expression_container.h"

class ListOperand: public Operand {
    public:
        ListOperand();

        void execute(std::stack<Expression*>& exec,
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);
};

#endif

#ifndef CAR_OPERAND_H
#define CAR_OPERAND_H

#include <stack>
#include <map>
#include <string>
#include "expression.h"
#include "operand.h"
#include "expression_container.h"

class CarOperand: public Operand {
    public:
        CarOperand();

        void execute(std::stack<Expression*>& exec,
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);
};

#endif

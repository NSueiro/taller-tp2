#ifndef NUM_EXPRESSION_H
#define NUM_EXPRESSION_H

#include <stack>
#include <map>
#include <string>
#include "expression.h"

class ExpressionContainer;
class Mutex;

class NumExpression: public Expression{
    public:
        explicit NumExpression(std::string s);
        void execute(std::stack<Expression*>& exec, 
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);
        
        bool can_print();

        void print();
};

#endif

#ifndef PARENTHESIS_EXPRESSION_H
#define PARENTHESIS_EXPRESSION_H

#include <stack>
#include <map>
#include <string>
#include "expression.h"
#include "expression_container.h"

class ParenthesisExpression: public Expression {
    public:
        explicit ParenthesisExpression(std::string s);

        void execute(std::stack<Expression*>& exec, 
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);

        bool car(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont);

        bool cdr(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont);

        bool is_delim();
};

#endif

#ifndef LIST_EXPRESSION_H
#define LIST_EXPRESSION_H

#include <stack>
#include <map>
#include <string>
#include <vector>
#include "expression.h"
#include "expression_container.h"

class ExpressionContainer;
class Mutex;

class ListExpression: public Expression{
    protected:
        std::vector<Expression*> list;

    public:
        explicit ListExpression(std::vector<Expression*> vec);

        void execute(std::stack<Expression*>& exec,
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m);

        bool car(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont);

        bool cdr(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont);

        bool get_bool();

        bool can_print();

        void print();
};

#endif

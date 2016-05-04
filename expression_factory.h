#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include <string>
#include <stack>

class ExpressionContainer;
class Expression;

class ExpressionFactory{
    public:
        static void create(ExpressionContainer&, std::stack<Expression*>&, 
                           const std::string&);
};

#endif

#ifndef EXPRESSION_CONTAINER_H
#define EXPRESSION_CONTAINER_H

#include <vector>

class Expression;

class ExpressionContainer{
    private:
        std::vector<Expression*> container;

    public:
        ExpressionContainer();

        void add(Expression* e);

        virtual ~ExpressionContainer();
};

#endif

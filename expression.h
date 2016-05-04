#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stack>
#include <string>
#include <map>

class ExpressionContainer;
class Mutex;

class Expression{
    protected:
        std::string symbol;
    public:
        explicit Expression(std::string s);

        virtual bool get_bool();

        virtual void execute(std::stack<Expression*>& exec, 
                             std::stack<Expression*>& args,
                             ExpressionContainer& exp_cont,
                             std::map<std::string, Expression*>& vars,
                             Mutex& m);
        virtual bool car(std::stack<Expression*>& exec,
                         ExpressionContainer& exp_cont);
        virtual bool cdr(std::stack<Expression*>& exec,
                         ExpressionContainer& exp_cont);
        virtual void print();
        virtual bool can_print();
        virtual bool is_delim();
        std::string get_symbol();
        virtual ~Expression(){}
};

#endif

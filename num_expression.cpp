#include "num_expression.h"
#include "expression.h"
#include <iostream>
#include <map>
#include <string>
#include <stack>
        
NumExpression::NumExpression(std::string s): Expression(s){}

void NumExpression::execute(std::stack<Expression*>& exec, 
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m){
    args.push(this);
}
        
bool NumExpression::can_print(){
    return true;
}

void NumExpression::print(){
    std::cout << this->symbol;
}

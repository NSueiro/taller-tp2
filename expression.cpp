#include "expression.h"
#include <map>
#include <string>
#include <stack>

Expression::Expression(std::string s){
    this->symbol = s;
}

bool Expression::get_bool(){
    return true;
}

std::string Expression::get_symbol(){
    return this->symbol;
}

void Expression::execute(std::stack<Expression*>& exec, 
                        std::stack<Expression*>& args,
                        ExpressionContainer& exp_cont,
                        std::map<std::string, Expression*>& vars,
                        Mutex &m){
    args.push(this);
}

bool Expression::car(std::stack<Expression*>& exec,
                     ExpressionContainer& exp_cont){
    return false;
}

bool Expression::cdr(std::stack<Expression*>& exec,
                     ExpressionContainer& exp_cont){
    return false;
}

void Expression::print(){
    (void)0;
}

bool Expression::can_print(){
    return false;
}

bool Expression::is_delim(){
    return false;
}

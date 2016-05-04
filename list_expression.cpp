#include "list_expression.h"
#include "constants.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

ListExpression::ListExpression(std::vector<Expression*> vec): 
                               Expression(LIST_SYM){
    this->list = vec;
}

void ListExpression::execute(std::stack<Expression*>& exec,
                             std::stack<Expression*>& args,
                             ExpressionContainer& exp_cont,
                             std::map<std::string, Expression*>& vars,
                             Mutex &m){
    args.push(this);
}

bool ListExpression::car(std::stack<Expression*>& exec,
                         ExpressionContainer& exp_cont){
    if (this->list.empty()){
    std::vector<Expression*> vec;
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
    } else {
    exec.push(this->list.front());
    }
    return true;
}

bool ListExpression::cdr(std::stack<Expression*>& exec,
                         ExpressionContainer& exp_cont){
    std::vector<Expression*> vec;
    if (!this->list.empty()){
        unsigned int i = 1;
        while (i < this->list.size()){
            vec.push_back(this->list[i]);
            ++i;
        }
    }
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
    return true;
}

bool ListExpression::get_bool(){
    return !this->list.empty();
}

bool ListExpression::can_print(){
    return true;
}

void ListExpression::print(){
    std::cout << PAR_OPEN_SYM;
    for (std::vector<Expression*>::iterator it = this->list.begin(); 
         it != this->list.end(); ++it){
        if (it != this->list.begin()) std::cout << " ";
        (*it)->print();
    }
    std::cout << PAR_CLOSE_SYM;
}

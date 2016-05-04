#include "print_operand.h"
#include "expression.h"
#include "constants.h"
#include "mutex.h"
#include <iostream>
#include <map>
#include <string>
#include <stack>

PrintOperand::PrintOperand(): Operand(PRINT_SYM){}
        
void PrintOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    bool first = true;
    while (!args.empty()){    
        Expression *current = args.top();
        std::map<std::string,Expression*>::iterator it = 
            vars.find(current->get_symbol());
        if (it != vars.end()){
           current = it->second;
        }
        args.pop();
        if (!current->can_print()) continue;
        m.lock();
        if (!first) std::cout << " ";
        first = false;
        current->print();
        m.unlock();
    }
    m.lock();
    std::cout << "\n";
    m.unlock();
}

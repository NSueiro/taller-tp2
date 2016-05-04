#include "car_operand.h"
#include "expression.h"
#include "constants.h"
#include <map>
#include <string>
#include <stack>

CarOperand::CarOperand(): Operand(CAR_SYM){}
        
void CarOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    Expression *current = args.top();
    std::map<std::string,Expression*>::iterator it = 
        vars.find(current->get_symbol());
    if (it != vars.end()){
       current = it->second;
    }
    // Popping the argument
    args.pop();
    // Popping the parenthesis after the arg
    args.pop();
    current->car(exec, exp_cont);
}

#include "if_operand.h"
#include "expression.h"
#include "constants.h"
#include <map>
#include <string>
#include <stack>

IfOperand::IfOperand(): Operand(IF_SYM){}
        
void IfOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    Expression *condition = args.top();
    std::map<std::string,Expression*>::iterator it = 
        vars.find(condition->get_symbol());
    if (it != vars.end()){
       condition = it->second;
    }
    args.pop();
    Expression* e = args.top();
    args.pop();
    if (!condition->get_bool()){
        e = args.top();
    }
    // Popping the argument
    args.pop();
    // Popping the parenthesis
    args.pop();
    it = vars.find(e->get_symbol());
    if (it != vars.end()){
       e = it->second;
    }
    exec.push(e);
}

#include "cdr_operand.h"
#include "expression.h"
#include "constants.h"
#include <map>
#include <string>
#include <stack>

CdrOperand::CdrOperand(): Operand(CDR_SYM){}
        
void CdrOperand::execute(std::stack<Expression*>& exec,
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
    // Popping the parenthesis
    args.pop();
    current->cdr(exec, exp_cont);
}

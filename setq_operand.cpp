#include "setq_operand.h"
#include "expression.h"
#include "constants.h"
#include "mutex.h"
#include <map>
#include <string>
#include <stack>

SetqOperand::SetqOperand(): Operand(SETQ_SYM){}
        
void SetqOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    Expression *key = args.top();
    args.pop();
    Expression *value = args.top();
    args.pop();
    m.lock();
    vars[key->get_symbol()] = value;
    m.unlock();
}

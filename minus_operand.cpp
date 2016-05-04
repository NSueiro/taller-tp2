#include "minus_operand.h"
#include "expression.h"
#include "num_expression.h"
#include "constants.h"
#include <string>
#include <sstream>
#include <map>
#include <stack>

MinusOperand::MinusOperand(): Operand(MINUS_SYM){}
        
void MinusOperand::execute(std::stack<Expression*>& exec,
                           std::stack<Expression*>& args,
                           ExpressionContainer& exp_cont,
                           std::map<std::string, Expression*>& vars,
                           Mutex &m){
    int aux = 0;
    int cont = 0;
    while (true){
        Expression *current = args.top();
        std::map<std::string,Expression*>::iterator it = 
            vars.find(current->get_symbol());
        if (it != vars.end()){
           current = it->second;
        }
        args.pop();
        if (current->is_delim()) break;
        std::string s = current->get_symbol();
        ++cont;
        std::istringstream is(s);
        int i;
        is >> i;
        if (cont == 1) aux += i;
        else 
            aux -= i;
    }
    std::string str;  
    std::ostringstream temp;
    temp << aux;
    str = temp.str();
    Expression* e = new NumExpression(str);
    exp_cont.add(e);
    exec.push(e);
}    

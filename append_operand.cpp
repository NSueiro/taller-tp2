#include "append_operand.h"
#include "expression.h"
#include "constants.h"
#include "list_expression.h"
#include <map>
#include <string>
#include <stack>
#include <vector>

AppendOperand::AppendOperand(): Operand(APPEND_SYM){}
        
void AppendOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    int cont = 0;
    while (true){
        Expression* current = args.top();
        std::map<std::string,Expression*>::iterator it = 
            vars.find(current->get_symbol());
        if (it != vars.end()){
           current = it->second;
        }
        args.pop();
        if (current->is_delim()) break;
        if (current->get_bool()){
            current->car(exec, exp_cont);
            current->cdr(exec, exp_cont);
            current = exec.top();
            exec.pop();
            current->execute(exec, args, exp_cont, vars, m);
            ++cont;
        }
    }
    std::stack<Expression*> aux;
    while (cont != 0){
        aux.push(exec.top());
        exec.pop();
        --cont;
    }
    std::vector<Expression*> vec;
    while (!aux.empty()){
        vec.push_back(aux.top());
        aux.pop();
    }
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
}

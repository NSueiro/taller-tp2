#include "list_operand.h"
#include "expression.h"
#include "list_expression.h"
#include "constants.h"
#include <string>
#include <map>
#include <stack>
#include <vector>

ListOperand::ListOperand(): Operand(LIST_OP_SYM){}
        
void ListOperand::execute(std::stack<Expression*>& exec,
                         std::stack<Expression*>& args,
                         ExpressionContainer& exp_cont,
                         std::map<std::string, Expression*>& vars,
                         Mutex &m){
    std::vector<Expression*> vec;
    while (true){
        Expression *current = args.top();
        std::map<std::string,Expression*>::iterator it = 
            vars.find(current->get_symbol());
        if (it != vars.end()){
           current = it->second;
        }
        args.pop();
        if (current->is_delim()) break;
        vec.push_back(current);
    }
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
}

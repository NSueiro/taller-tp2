#include "parenthesis_expression.h"
#include "expression.h"
#include "list_expression.h"
#include "constants.h"
#include <map>
#include <string>
#include <stack>
#include <vector>

ParenthesisExpression::ParenthesisExpression(std::string s): Expression(s){}
        
void ParenthesisExpression::execute(std::stack<Expression*>& exec, 
                     std::stack<Expression*>& args,
                     ExpressionContainer& exp_cont,
                     std::map<std::string, Expression*>& vars,
                     Mutex &m){
    if (this->symbol == PAR_CLOSE_SYM) args.push(this);
}
bool ParenthesisExpression::car(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont){
    std::vector<Expression*> vec;
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
    return true;
}
bool ParenthesisExpression::cdr(std::stack<Expression*>& exec,
                 ExpressionContainer& exp_cont){
    std::vector<Expression*> vec;
    Expression* e = new ListExpression(vec);
    exp_cont.add(e);
    exec.push(e);
    return true;
}

bool ParenthesisExpression::is_delim(){
    return true;
}

#include "expression_factory.h"
#include "exec_stack.h"
#include "expression.h"
#include "thread.h"
#include "constants.h"
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <stack>

void ExecutionStack::add_space(std::string& line, const std::string& old, 
               const std::string& _new){
    size_t index = 0;
    while (true) {
        index = line.find(old, index);
        if (index == std::string::npos) break;
        line.replace(index, old.length(), _new);
        index += _new.length();
    }
}
        
void ExecutionStack::parse_line(std::string& line){
    std::string buffer;
    std::stringstream stream(line);
    while (stream >> buffer){
        this->tokens.push_back(buffer);
    }
}

void ExecutionStack::prepare_execution_stack(std::map<std::string,
                                             Expression*>& vars){
    int i = 0;
    std::string _exp;
    while (i < (int)this->tokens.size()){
        _exp = this->tokens[i];
        ExpressionFactory::create(this->exp_cont, this->exec_stack, 
                                  _exp);
        ++i;
    }
}

ExecutionStack::ExecutionStack(std::string line, 
               std::map<std::string, Expression*>& vars, Mutex& m):
               vars(vars), m(m){
    this->add_space(line, "(", "( ");
    this->add_space(line, ")", " )");
    this->parse_line(line);
    this->prepare_execution_stack(vars);
}

bool ExecutionStack::check_parenthesis_balance(){
    int open_p = 0;
    int close_p = 0;
    for (std::vector<std::string>::iterator it = tokens.begin(); 
         it != tokens.end(); ++it) {
        if (*it == PAR_OPEN_SYM) ++open_p;
        else if (*it == PAR_CLOSE_SYM) ++close_p;   
    }
    return open_p == close_p;
}

Expression* ExecutionStack::execute(){
    std::stack<Expression*> args;
    while (!this->exec_stack.empty()){
        Expression *current = this->exec_stack.top();
        this->exec_stack.pop();
        current->execute(this->exec_stack, args, this->exp_cont, 
                         this->vars, this->m);
    }
    if (!args.empty()) return args.top();
    return NULL;
}

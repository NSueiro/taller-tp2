#ifndef EXEC_STACK_H
#define EXEC_STACK_H

#include "thread.h"
#include "mutex.h"
#include "expression_container.h"
#include <vector>
#include <string>
#include <map>
#include <stack>


class ExecutionStack: public Thread {
    private:
        std::vector<std::string> tokens;
        std::stack<Expression*> exec_stack;
        ExpressionContainer exp_cont;
        std::map<std::string, Expression*>& vars;
        Mutex &m;

        void add_space(std::string& line, const std::string& old, 
                       const std::string& _new);
        
        void parse_line(std::string& line);

        void prepare_execution_stack(std::map<std::string, Expression*>& vars);

    public:
        ExecutionStack(std::string line, 
                       std::map<std::string, Expression*>& vars, Mutex& m);

        bool check_parenthesis_balance();

        Expression* execute();
};

#endif

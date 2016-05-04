#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <map>
#include <pthread.h>
#include "constants.h"
#include "mutex.h"
#include "thread.h"
#include "expression.h"
#include "expression_container.h"
#include "expression_factory.h"
#include "exec_stack.h"

int main(int argc, char *argv[]){
    if (argc != 1) {
        std::cout << "ERROR: argumentos\n";
        return 1;
    }
    std::string line;
    std::map<std::string, Expression*> vars;
    std::vector<Thread*> vec;
    Mutex m;
    unsigned int last_run = 0;
    unsigned int last_joined = 0;
    unsigned int current = 0;
    while (true){
        std::getline(std::cin, line);
        if (line == "") break;
        if (line == SYNC_SYM){
            while (last_run < current){
                vec[last_run]->start();
                ++last_run;
            }
            while (last_joined < current){
                vec[last_joined]->join();
                ++last_joined;
            }
            continue;
        }
        ExecutionStack *e = new ExecutionStack(line, vars, m);
        vec.push_back(e);
        if (!e->check_parenthesis_balance()){
            std::cout << "ERROR: " << line << "\n";
            for (std::vector<Thread*>::iterator it = vec.begin(); 
                 it != vec.end(); ++it){
                delete (*it);
            }
            return 2;
        }
        ++current;
    }
    while (last_run < current){
        vec[last_run]->start();
        ++last_run;
    }
    while (last_joined < current){
        vec[last_joined]->join();
        ++last_joined;
    }
    for (std::vector<Thread*>::iterator it = vec.begin(); 
         it != vec.end(); ++it){
        delete (*it);
    }
    return 0;
}

#include "operand.h"
#include "expression.h"
#include <string>

Operand::Operand(std::string s): Expression(s){}

bool Operand::get_bool(){
    return false;
}

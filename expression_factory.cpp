#include "constants.h"
#include "expression.h"
#include "expression_container.h"
#include "expression_factory.h"
#include "list_expression.h"
#include "num_expression.h"
#include "operand.h"
#include "parenthesis_expression.h"
#include "sum_operand.h"
#include "minus_operand.h"
#include "mul_operand.h"
#include "div_operand.h"
#include "list_operand.h"
#include "car_operand.h"
#include "cdr_operand.h"
#include "setq_operand.h"
#include "if_operand.h"
#include "print_operand.h"
#include "append_operand.h"
#include <string>
#include <stack>

void ExpressionFactory::create(ExpressionContainer& exp_cont, 
                          std::stack<Expression*>& exec_stack,
                          const std::string& _exp){
    bool has_letters = false;
    int i = 0;
    while (_exp[i]) {
        if (std::isalpha(_exp[i])){
            has_letters = true;
            break;
        }
        ++i;
    }
    Expression* e = NULL;
    if (_exp == PAR_CLOSE_SYM) e = new ParenthesisExpression(_exp);
    else if (_exp == PAR_OPEN_SYM) return;
    else if (_exp == SUM_SYM) e = new SumOperand;
    else if (_exp == MINUS_SYM) e = new MinusOperand;
    else if (_exp == MUL_SYM) e = new MulOperand;
    else if (_exp == DIV_SYM) e = new DivOperand;
    else if (_exp == LIST_SYM) e = new ListOperand;
    else if (_exp == CAR_SYM) e = new CarOperand;
    else if (_exp == CDR_SYM) e = new CdrOperand;
    else if (_exp == APPEND_SYM) e = new AppendOperand;
    else if (_exp == IF_SYM) e = new IfOperand;
    else if (_exp == SETQ_SYM) e = new SetqOperand;
    else if (_exp == PRINT_SYM) e = new PrintOperand;
    else if (has_letters) e = new Expression(_exp);
    else 
        e = new NumExpression(_exp);
    exp_cont.add(e);
    exec_stack.push(e);
}

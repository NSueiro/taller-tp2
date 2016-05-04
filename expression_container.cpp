#include "expression_container.h"
#include "expression.h"

ExpressionContainer::ExpressionContainer(){}
        
void ExpressionContainer::add(Expression* e){
    this->container.push_back(e);
}
ExpressionContainer::~ExpressionContainer(){
    for (int i = 0; i < (int)this->container.size(); ++i){
        delete this->container[i];
    }
}

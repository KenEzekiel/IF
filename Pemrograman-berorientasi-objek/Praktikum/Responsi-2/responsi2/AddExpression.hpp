#ifndef ADDEXPRESSION_HPP
#define ADDEXPRESSION_HPP

#include "Expression.hpp"

class AddExpression : public BinaryExpression
{
public:
    AddExpression(Expression *x, Expression *y);
    int solve();
};

#endif
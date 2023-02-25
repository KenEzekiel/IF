#ifndef SUBEXPRESSION_HPP
#define SUBEXPRESSION_HPP

#include "Expression.hpp"

class SubstractExpression : public BinaryExpression
{
public:
    SubstractExpression(Expression *x, Expression *y);
    int solve();
};

#endif
#ifndef NEGEXPRESSION_HPP
#define NEGEXPRESSION_HPP

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression
{
public:
    NegativeExpression(Expression *x);
    int solve();
};

#endif
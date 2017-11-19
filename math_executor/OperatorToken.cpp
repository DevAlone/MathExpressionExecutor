#include "OperatorToken.h"

OperatorToken::OperatorToken(char value)
    : value(value)
{
    type = TYPE::OPERATOR;
    if (value == '+' || value == '-')
        priority = 0;
    else if (value == '/' || value == '*')
        priority = 1;
    association = ASSOCIATION::LEFT;
}

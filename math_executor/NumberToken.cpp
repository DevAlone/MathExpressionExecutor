#include "NumberToken.h"

NumberToken::NumberToken(double value)
    : value(value)
{
    type = TYPE::NUMBER;
}

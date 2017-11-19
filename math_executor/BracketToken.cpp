#include "BracketToken.h"

BracketToken::BracketToken(char value)
    : value(value)
{
    type = TYPE::BRACKET;
}

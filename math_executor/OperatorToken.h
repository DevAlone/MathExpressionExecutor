#ifndef OPERATORTOKEN_H
#define OPERATORTOKEN_H

#include "Token.h"

struct OperatorToken : public Token {
    enum class ASSOCIATION : char {
        LEFT,
        RIGHT
    };

    OperatorToken(char value);

    char value;
    int priority;
    ASSOCIATION association;
};

#endif // OPERATORTOKEN_H

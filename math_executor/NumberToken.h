#ifndef NUMBERTOKEN_H
#define NUMBERTOKEN_H

#include "Token.h"

struct NumberToken : public Token {
    NumberToken(double value);

    double value;
};

#endif // NUMBERTOKEN_H

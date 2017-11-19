#ifndef BRACKETTOKEN_H
#define BRACKETTOKEN_H

#include "Token.h"

struct BracketToken : public Token {
    BracketToken(char value);

    char value;
};

#endif // BRACKETTOKEN_H

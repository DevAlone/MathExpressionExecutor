#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct Token {
    enum class TYPE {
        NUMBER,
        OPERATOR,
        BRACKET,
    };
    Token();

    TYPE type;
};

#endif // TOKEN_H

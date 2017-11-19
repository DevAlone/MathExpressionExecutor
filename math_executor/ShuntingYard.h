#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include "Token.h"

#include <memory>
#include <vector>

class ShuntingYard {
public:
    static std::vector<std::shared_ptr<Token>> infixExpressionToPostfix(
        const std::vector<std::shared_ptr<Token>>& tokens);
};

#endif // SHUNTINGYARD_H

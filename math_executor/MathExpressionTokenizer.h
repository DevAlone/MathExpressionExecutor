#ifndef MATHEXPRESSIONTOKENIZER_H
#define MATHEXPRESSIONTOKENIZER_H

#include "Token.h"

#include <memory>
#include <string>
#include <vector>

class MathExpressionTokenizer {
public:
    static std::vector<std::shared_ptr<Token> > split(const std::string& expression);
};

#endif // MATHEXPRESSIONTOKENIZER_H

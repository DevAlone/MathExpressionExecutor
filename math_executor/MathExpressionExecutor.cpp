#include "MathExpressionExecutor.h"
#include "BracketToken.h"
#include "ExecutorError.h"
#include "MathExpressionTokenizer.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "ReversePolishNotationExecutor.h"
#include "ShuntingYard.h"

#include <iostream>

bool checkBracketBalance(const std::string& str)
{
    long long brackets = 0;
    for (char ch : str) {
        if (ch == '(')
            ++brackets;
        else if (ch == ')')
            --brackets;

        if (brackets < 0)
            return false;
    }

    return brackets == 0;
}

double MathExpressionExecutor::execute(const std::string& expression)
{
    if (!checkBracketBalance(expression))
        throw ExecutorError("Something bad with your brackets");

    auto tokens = ShuntingYard::infixExpressionToPostfix(
        MathExpressionTokenizer::split(expression));

    return ReversePolishNotationExecutor::execute(tokens);
}

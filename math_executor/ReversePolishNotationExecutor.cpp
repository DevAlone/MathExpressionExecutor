#include "ReversePolishNotationExecutor.h"
#include "ExecutorError.h"
#include "NumberToken.h"
#include "OperatorToken.h"

#include <stack>
#include <string>

double ReversePolishNotationExecutor::execute(const std::vector<std::shared_ptr<Token> >& tokens)
{
    std::stack<double> stack;

    for (const auto& token : tokens) {
        switch (token->type) {
        case Token::TYPE::NUMBER: {
            auto numberToken = std::static_pointer_cast<NumberToken>(token);
            stack.push(numberToken->value);
        } break;
        case Token::TYPE::OPERATOR: {
            auto operatorToken = std::static_pointer_cast<OperatorToken>(token);

            auto leftOperand = stack.top();
            stack.pop();
            auto rightOperand = stack.top();
            stack.pop();

            switch (operatorToken->value) {
            case '+':
                stack.push(rightOperand + leftOperand);
                break;
            case '-':
                stack.push(rightOperand - leftOperand);
                break;
            case '*':
                stack.push(rightOperand * leftOperand);
                break;
            case '/':
                stack.push(rightOperand / leftOperand);
                break;
            }

        } break;
        default:
            break;
        }
    }

    if (stack.size() != 1)
        throw ExecutorError("Bad expression");

    return stack.top();
}

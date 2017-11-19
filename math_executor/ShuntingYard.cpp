#include "ShuntingYard.h"
#include "BracketToken.h"
#include "OperatorToken.h"

#include <memory>
#include <stack>
#include <stdexcept>

std::vector<std::shared_ptr<Token>> ShuntingYard::infixExpressionToPostfix(
    const std::vector<std::shared_ptr<Token>>& tokens)
{
    std::vector<std::shared_ptr<Token>> result;
    std::stack<std::shared_ptr<OperatorToken>> operators;

    for (const auto& token : tokens) {
        switch (token->type) {
        case Token::TYPE::NUMBER: {
            result.push_back(token);
        } break;
        case Token::TYPE::BRACKET: {
            auto bracketToken = std::static_pointer_cast<BracketToken>(token);
            if (bracketToken->value == '(') {
                operators.push(std::make_shared<OperatorToken>('('));
            } else {
                while (operators.size()) {
                    auto topOperator = operators.top();
                    if (topOperator->value != '(') {
                        result.push_back(topOperator);
                        operators.pop();
                    } else
                        break;
                }

                if (operators.size())
                    operators.pop();
            }
        } break;
        case Token::TYPE::OPERATOR: {
            auto operatorToken = std::static_pointer_cast<OperatorToken>(token);

            while (operators.size()) {
                auto topOperator = operators.top();
                if (
                    topOperator->value != '('
                    && topOperator->priority >= operatorToken->priority
                    && topOperator->association == OperatorToken::ASSOCIATION::LEFT) {

                    result.push_back(topOperator);
                    operators.pop();
                } else
                    break;
            }

            operators.push(operatorToken);
        } break;
            //        default:
            //            throw std::logic_error("Something went wrong");
            //            break;
        }
    }

    while (operators.size()) {
        result.push_back(operators.top());
        operators.pop();
    }

    return result;
}

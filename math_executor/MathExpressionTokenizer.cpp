#include "MathExpressionTokenizer.h"
#include "BracketToken.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "ParseError.h"

void flushBuffer(std::string& buffer, std::vector<std::shared_ptr<Token>>& tokens, Token::TYPE tokenType)
{
    if (buffer.size()) {
        if (tokenType == Token::TYPE::NUMBER) {
            tokens.push_back(std::make_shared<NumberToken>(std::stoi(buffer)));
        } else if (buffer[0] == '(' || buffer[0] == ')') {
            tokens.push_back(std::make_shared<BracketToken>(buffer[0]));
        } else {
            tokens.push_back(std::make_shared<OperatorToken>(buffer[0]));
        }

        buffer.clear();
    }
}

std::vector<std::shared_ptr<Token>> MathExpressionTokenizer::split(const std::string& expression)
{
    std::vector<std::shared_ptr<Token>> result;
    std::string buffer = "";
    Token::TYPE lastTokenType = Token::TYPE::OPERATOR;

    for (char ch : expression) {
        if (ch >= '0' && ch <= '9') {
            if (lastTokenType != Token::TYPE::NUMBER)
                flushBuffer(buffer, result, lastTokenType);

            buffer += ch;
            lastTokenType = Token::TYPE::NUMBER;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            flushBuffer(buffer, result, lastTokenType);

            buffer = ch;

            lastTokenType = Token::TYPE::OPERATOR;
        } else if (ch == '(' || ch == ')') {
            flushBuffer(buffer, result, lastTokenType);

            buffer = ch;

            lastTokenType = Token::TYPE::BRACKET;
        } else {
            flushBuffer(buffer, result, lastTokenType);
        }
    }
    flushBuffer(buffer, result, lastTokenType);

    // validate tokens and process negative numbers
    for (size_t i = 1; i < result.size(); ++i) {
        std::shared_ptr<Token> previousToken = result[i - 1];
        std::shared_ptr<Token> currentToken = result[i];
        std::shared_ptr<Token> nextToken;
        if (i < result.size() - 1)
            nextToken = result[i + 1];

        if (previousToken->type == Token::TYPE::OPERATOR) {
            auto previousOperatorToken = std::static_pointer_cast<OperatorToken>(previousToken);

            if (i < 2 && currentToken->type == Token::TYPE::NUMBER) {
                auto currentNumberToken = std::static_pointer_cast<NumberToken>(currentToken);
                if (previousOperatorToken->value == '-')
                    currentNumberToken->value = -currentNumberToken->value;
                result.erase(result.begin() + long(i - 1));
                --i;
            }
        }

        if (
            (previousToken->type == Token::TYPE::OPERATOR
                || (previousToken->type == Token::TYPE::BRACKET && std::static_pointer_cast<BracketToken>(previousToken)->value == '('))
            && currentToken->type == Token::TYPE::OPERATOR) {
            auto currentOperatorToken = std::static_pointer_cast<OperatorToken>(currentToken);

            if ((currentOperatorToken->value == '+' || currentOperatorToken->value == '-')
                && nextToken && nextToken->type == Token::TYPE::NUMBER) {
                auto nextNumberToken = std::static_pointer_cast<NumberToken>(nextToken);
                if (currentOperatorToken->value == '-')
                    nextNumberToken->value = -nextNumberToken->value;
                result.erase(result.begin() + long(i));
                --i;
            } else {
                throw ParseError("Bad syntax");
            }
        }
    }

    return result;
}

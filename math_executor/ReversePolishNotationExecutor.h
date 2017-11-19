#ifndef REVERSEPOLISHNOTATIONEXECUTOR_H
#define REVERSEPOLISHNOTATIONEXECUTOR_H

#include "Token.h"

#include <memory>
#include <vector>

class ReversePolishNotationExecutor {
public:
    static double execute(const std::vector<std::shared_ptr<Token>>& tokens);
};

#endif // REVERSEPOLISHNOTATIONEXECUTOR_H

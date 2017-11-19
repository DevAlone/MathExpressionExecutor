#ifndef MATHEXPRESSIONEXECUTOR_H
#define MATHEXPRESSIONEXECUTOR_H

#include <stdexcept>
#include <string>

class MathExpressionExecutor {
public:
    static double execute(const std::string& expression);
};

#endif // MATHEXPRESSIONEXECUTOR_H

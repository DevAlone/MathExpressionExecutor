#include "math_executor/MathExpressionExecutor.h"

#include <iostream>
#include <string>

#include <math_executor/ExecutorError.h>

int main()
{
    std::cout << (5 / -24) << std::endl;
    std::string input;
    while (std::cin) {
        try {
            std::getline(std::cin, input);

            std::cout << (MathExpressionExecutor::execute(input)) << std::endl;
        } catch (const std::exception& error) {
            std::cout << "ERROR: " << error.what() << std::endl;
        }
    }

    return 0;
}

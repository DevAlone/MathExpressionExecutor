#ifndef EXECUTORERROR_H
#define EXECUTORERROR_H

#include <stdexcept>

class ExecutorError : public std::runtime_error {
public:
    ExecutorError(const std::string& message);
};

#endif // EXECUTORERROR_H

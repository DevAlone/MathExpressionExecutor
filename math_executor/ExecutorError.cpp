#include "ExecutorError.h"

ExecutorError::ExecutorError(const std::string& message)
    : std::runtime_error(message)
{
}

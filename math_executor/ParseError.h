#ifndef PARSEERROR_H
#define PARSEERROR_H

#include <stdexcept>

class ParseError : public std::runtime_error {
public:
    ParseError(const std::string& message);
};

#endif // PARSEERROR_H

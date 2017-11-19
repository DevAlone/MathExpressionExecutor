TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    math_executor/MathExpressionExecutor.cpp \
    math_executor/MathExpressionTokenizer.cpp \
    math_executor/ReversePolishNotationExecutor.cpp \
    math_executor/ShuntingYard.cpp \
    math_executor/Token.cpp \
    math_executor/NumberToken.cpp \
    math_executor/OperatorToken.cpp \
    math_executor/BracketToken.cpp \
    math_executor/ExecutorError.cpp \
    math_executor/ParseError.cpp

HEADERS += \
    math_executor/MathExpressionExecutor.h \
    math_executor/MathExpressionTokenizer.h \
    math_executor/ReversePolishNotationExecutor.h \
    math_executor/ShuntingYard.h \
    math_executor/Token.h \
    math_executor/NumberToken.h \
    math_executor/OperatorToken.h \
    math_executor/BracketToken.h \
    math_executor/ExecutorError.h \
    math_executor/ParseError.h

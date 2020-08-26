#pragma once
#include <set>

enum tokens {
    PLUS = '+',
    MINUS = '-',
    TIMES = '*',
    DIVIDE = '/',
    LPAREN = '(',
    RPAREN = ')',
    DOT = '.',
    COMMA = ','
};

enum types {
    digit = 0,
    operation = 1,
    parenthesis = 2,
    delimiter = 3,
    other = 4
};

const std::set<char> parens {LPAREN, RPAREN}; 
const std::set<char> opers {PLUS, MINUS, TIMES, DIVIDE}; 
const std::set<char> digits {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const std::set<char> delims {DOT, COMMA};

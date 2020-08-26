/*
* This is my totally messed up calculator. The idea is to parse an input string int an array 
* of numerical values and a string of operations. Along with it there is a map that counts
* the amount of operations before every parenthesis. Corresponding parentheses have, therefore
* closest indexes. Calculation starts with closest parentheses. Then the program deletes their
* indices from the map and shifts the position of every other parenthesis that needs shifting.
* Inside the parenthesis I calculate every division or multiplication by replacing i-th element
* with the result of the operation, while dropping i+1-th along with the sign of preformed operation.
* Therefore, the answer is the last remaining number in the array.
*/




#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "consts.h"
#include "data.h"


class Parser {
    private:
        std::string expr;

    public:
        Parser();
        Parser(const std::string&);
        ~Parser();
        Data parseStr();
        void setString(const std::string&);
};
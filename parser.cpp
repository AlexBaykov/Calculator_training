#include "parser.h"
using namespace std;


Parser :: Parser(){};
Parser :: Parser(const string& input) {
    expr = input;
}
Parser :: ~Parser(){};

void Parser :: setString(const std::string& inputstr){
    expr = inputstr;
}

Data Parser :: parseStr(){

    Data parsedData;

    if (expr.empty()){
        parsedData.err.code = 1;
        parsedData.err.msg = "Empty input! Nothing to parse";
        parsedData.clearOnErr();
    }

    // Remove whitespaces from input string
    expr.erase(remove_if(expr.begin(), expr.end(), [](unsigned char c) {return c == ' ';}), expr.end());

    auto getType = [&](const char c){
         if (parens.count(c))
           return parenthesis;
        if (opers.count(c))
            return operation;
        if (digits.count(c))
            return digit;
        if (delims.count(c))
            return delimiter;
        return other;
    };

    auto pushNumber = [&](string& str){
        if (!str.empty()){
            parsedData.values.push_back(stod(str));
            str = ""s;
        }
    };

    string numstr {""s};
    for(const char c : expr){
        switch(getType(c)){
            case other:
                parsedData.err.code = 2; 
                parsedData.err.msg = "Invalid symbol in input. Only numerals, operation signs and parentheses allowed."; 
                parsedData.clearOnErr();
                return parsedData;
            case digit:
                numstr.push_back(c);
                break;
            case delimiter:
                numstr.push_back(DOT);
                break;
            case parenthesis:
                // Writing the amount of operations before parethesis.
                parsedData.parentheses[c].push_back(parsedData.operations.size());
                pushNumber(numstr);
                break;
            case operation:
                if (c == MINUS && (numstr.empty() && parsedData.operations.empty())){
                    //Account for expressions starting with negative values
                    numstr.push_back(c);
                } else {
                    parsedData.operations.push_back(c);
                    pushNumber(numstr); 
                }
                break;
        }
    }
    pushNumber(numstr);

    if(parsedData.operations.size() > parsedData.values.size() - 1){
        parsedData.err.code = 3;
        parsedData.err.msg = "Invalid input! Dangling operations";
        parsedData.clearOnErr();
    }

    if (parsedData.parentheses[LPAREN].size() != parsedData.parentheses[RPAREN].size()){
        parsedData.err.code = 4;
        parsedData.err.msg = "Parentheses do not match!";
        parsedData.clearOnErr();
    }
    return parsedData;
}


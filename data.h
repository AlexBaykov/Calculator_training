#pragma once
#include <vector>
#include <string>
#include <map>

struct Error {
    std::string msg;
    int code;
};

struct Data{
        std::string datastr;
        std::vector<double> values;
        std::string operations;
        std::map<char, std::vector<int>> parentheses;
        Error err;

        Data();
        Data(std::vector<double>, std::string, std::map<char, std::vector<int>>);
        Data(Data&);
        ~Data();
        void clearOnErr();
};
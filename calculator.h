#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "data.h"
#include "consts.h"

class Calculator {
    private:
        Data calcData;
    public:
        Calculator();
        Calculator(const Data&);
        Calculator(const Calculator&);
        ~Calculator();
        void setData(const Data&);
        void reduce(const int, int&);
        void reduceParens();
        Data evaluate();
};
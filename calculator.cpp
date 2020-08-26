#include "calculator.h"
using namespace std;

Calculator :: Calculator(){};
Calculator :: Calculator(const Data& inputData){
    calcData = inputData;
};

Calculator :: Calculator(const Calculator& inputCalc){
    calcData = inputCalc.calcData;
}
Calculator :: ~Calculator(){};

void Calculator :: setData(const Data& inputData){
    calcData = inputData;
}

void Calculator :: reduce(const int start, int& end){

    if (end <= start || end < 0 || start < 0 || start > calcData.operations.size() || end > calcData.operations.size()){
        calcData.err.msg = "Index out of bounds";
        calcData.err.code = 5;
        calcData.clearOnErr();
        return;
    }


    auto dropElements = [&](int pos){
        if (pos <  0 || calcData.operations.size() <= pos){
            calcData.err.msg = "Index out of bounds";
            calcData.err.code = 5;
            calcData.clearOnErr();
            return 0;
        }
        calcData.operations.erase(calcData.operations.begin() + pos);
        calcData.values.erase(calcData.values.begin() + pos + 1);
        return 1;
    };


    auto containsMultOrDiv = [&](){
        return (find(&calcData.operations[start], &calcData.operations[end], TIMES) != &calcData.operations[end] ||
                find(&calcData.operations[start], &calcData.operations[end], DIVIDE) != &calcData.operations[end]);
    };
    while(containsMultOrDiv()){

        for(int i = start; i < end; i++){
        
            switch (calcData.operations[i]){
            
                case TIMES:
                    calcData.values[i] = calcData.values[i] * calcData.values[i + 1];
                    if (dropElements(i)){
                        end--;
                        break;
                    } else {
                        return;
                    }

                case DIVIDE:
                    if (calcData.values[i + 1] == 0){
                        calcData.err.code = 6;
                        calcData.err.msg = "Division by zero!";
                        calcData.clearOnErr();
                        return;
                    }
                    calcData.values[i] = calcData.values[i] / calcData.values[i + 1];
                    if (dropElements(i)){
                        end--;
                        break;
                    } else {
                        return;
                    }
            }
        }
    }


    while(end > start){
        for(int i = start; i < end; i++){
        
            switch (calcData.operations[i]){
            
                case PLUS:
                    calcData.values[i] = calcData.values[i] + calcData.values[i + 1];
                    if (dropElements(i)){
                        end--;
                        break;
                    } else {
                        return;
                    }

                case MINUS:
                    calcData.values[i] = calcData.values[i] - calcData.values[i + 1];
                    if (dropElements(i)){
                        end--;
                        break;
                    } else {
                        return;
                    }
            }
        }
    }

}

void Calculator :: reduceParens(){

    while(!calcData.parentheses[LPAREN].empty()){
        auto opening_paren = calcData.parentheses[LPAREN].end() - 1;

        auto isGreater = [=](int x){return x >= *opening_paren;};

        auto closing_paren = find_if(calcData.parentheses[RPAREN].begin(), calcData.parentheses[RPAREN].end(), isGreater);

        if (*opening_paren != *closing_paren){

            int diff = calcData.operations.size();
            reduce(*opening_paren, *closing_paren); 
            diff -= calcData.operations.size();

            // Inline function do decrease indices of following calcData.parentheses
            auto decrementIdx = [&](int& idx){
                if (idx > 0 && idx > *opening_paren)
                    idx = idx - diff;
            };
            for_each(calcData.parentheses[LPAREN].begin(), calcData.parentheses[LPAREN].end(), decrementIdx);
            for_each(calcData.parentheses[RPAREN].begin(), calcData.parentheses[RPAREN].end(), decrementIdx);

            calcData.parentheses[LPAREN].erase(opening_paren);
            calcData.parentheses[RPAREN].erase(closing_paren);
        } else {
            calcData.parentheses[LPAREN].erase(opening_paren);
            calcData.parentheses[RPAREN].erase(closing_paren);
        }
    }
}

Data Calculator :: evaluate(){

    if (calcData.err.code != 0 || !calcData.err.msg.empty()){
        return calcData;
    }
    reduceParens();
    while(!calcData.operations.empty()){
        int sz {static_cast<int>(calcData.operations.size())};
        reduce(0, sz);
    }
    return calcData;
}
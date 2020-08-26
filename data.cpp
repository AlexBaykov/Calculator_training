#include "data.h"

Data :: Data(){
    err.code = 0;
};
Data :: Data(std::vector<double> input_values, std::string input_operations, std::map<char, std::vector<int>> input_parentheses){
    values = input_values;
    operations = input_operations;
    parentheses = input_parentheses;
    err.code = 0;
};

Data :: Data(Data& inputData){
    datastr = inputData.datastr;
    values = inputData.values;
    operations = inputData.operations;
    parentheses = inputData.parentheses;
    err = inputData.err;
}
Data :: ~Data(){};
void Data :: clearOnErr(){
    values.clear();
    parentheses.clear();
    operations = "";
}
#include <iostream>
#include "parser.h"
#include "communicator.h"
#include "calculator.h"
using namespace std;


int main(){
    cout << "This is a simple calculator.";
    cout << "It supports only arithmetic operations and parentheses. To exit, type quit " << endl;
    cout << "Enter your expression below:" << endl;

    string input;

    Communicator comm;
    Parser prs;
    Calculator calc;
    Data data;

    while( getline(cin, input) ){
        if(input == "quit!"){
            cout << "Goodbye!" << endl;
            return 0;
        }
        data.datastr = input;
        comm.setData(data);
        prs.setString(comm.getData().datastr);
        calc.setData(prs.parseStr());
        comm.setData(calc.evaluate());
        comm.print();
        cout << "Enter your expression below:" << endl;
    }
    return 0;
}
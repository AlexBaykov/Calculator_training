#include "communicator.h"

Communicator :: Communicator(){};
Communicator :: Communicator(const std::string& inputstr){
    data.datastr = inputstr;
};
Communicator :: Communicator(const Data& inputData){
    data = inputData;
};
Communicator :: Communicator(const Communicator& inputCommunicator){
    data = inputCommunicator.data;
};
Communicator :: ~Communicator(){};

void Communicator :: print(){
    if (data.err.code == 0 && data.err.msg.empty()){
        std::cout << "The result is: " << data.values[0] << std::endl;
    } else {
        std::cout << "Error encountered. Error code " << data.err.code << ". Message: " << data.err.msg << std::endl;
    }
}

Data Communicator :: getData(){
    return data;
}

void Communicator :: setData(const Data& inputData){
    data = inputData;
}

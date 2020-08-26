#pragma once
#include <iostream>
#include "data.h"


class Communicator {
    private:
        Data data;
    public:
        Communicator();
        Communicator(const std::string&);
        Communicator(const Data&);
        Communicator(const Communicator&);
        ~Communicator();
        void print();
        Data getData();
        void setData(const Data&);
};
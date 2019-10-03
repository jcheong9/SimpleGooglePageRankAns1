//
// Created by jcheong on 2019-10-02.
//

#include "ConnectivityMatrix.hpp"

void ConnectivityMatrix::makeConnectivityMatrix() {
    this->set_value(0,1,1);
    this->set_value(0,2,1);
    this->set_value(1,0,1);
    this->set_value(1,2,1);
    this->set_value(2,0,1);
    this->set_value(2,1,1);
}
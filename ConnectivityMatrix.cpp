//
// Created by jcheong on 2019-10-02.
//

#include "ConnectivityMatrix.hpp"

void ConnectivityMatrix::makeConnectivityMatrix() {
    this->vectMatrix.at(0).at(1) = 1;
    this->vectMatrix.at(0).at(2) = 1;
    this->vectMatrix.at(1).at(0) = 1;
    this->vectMatrix.at(1).at(2) = 1;
    this->vectMatrix.at(2).at(0) = 1;
    this->vectMatrix.at(2).at(1) = 1;
}
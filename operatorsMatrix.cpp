//
// Created by jcheong on 2019-10-01.
//

#include "operatorsMatrix.hpp"

Matrix& operator=(Matrix a){
    mySwap(*this, a);
    return *this;
};
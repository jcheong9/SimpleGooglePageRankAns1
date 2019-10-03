//
// Created by jcheong on 2019-10-02.
//

#ifndef MATRIX_CONNECTIVITYMATRIX_HPP
#define MATRIX_CONNECTIVITYMATRIX_HPP

#include "Matrix.hpp"
class ConnectivityMatrix: public Matrix{

public:
    ConnectivityMatrix(const int& size) : Matrix(size){
        makeConnectivityMatrix();
    }
    //function prototype
    void makeConnectivityMatrix();
};
#endif //MATRIX_CONNECTIVITYMATRIX_HPP

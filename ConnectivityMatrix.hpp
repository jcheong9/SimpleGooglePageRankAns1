//
// Created by jcheong on 2019-10-02.
//

#ifndef MATRIX_CONNECTIVITYMATRIX_HPP
#define MATRIX_CONNECTIVITYMATRIX_HPP

#include "Matrix.hpp"
class ConnectivityMatrix: public Matrix{

public:
    //constructor
    ConnectivityMatrix(const int& size) : Matrix(size){
        makeConnectivityMatrix();
    }
    ConnectivityMatrix(vector<double> vector);

//function prototype
    void makeConnectivityMatrix();
};
#endif //MATRIX_CONNECTIVITYMATRIX_HPP

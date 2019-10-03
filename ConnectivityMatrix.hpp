//
// Created by jcheong on 2019-10-02.
//

#ifndef MATRIX_CONNECTIVITYMATRIX_HPP
#define MATRIX_CONNECTIVITYMATRIX_HPP

#include "Matrix.hpp"
const int ConnectivityMatrixSize = 4;
class ConnectivityMatrix: public Matrix{
private:
    int width = ConnectivityMatrixSize;
    int height = ConnectivityMatrixSize;
    vector<vector<double>> vectMatrix;
public:
    ConnectivityMatrix(const int& width,const int& height) : Matrix( width, height){
        makeConnectivityMatrix();
    }
    //function prototype
    void makeConnectivityMatrix();
};
#endif //MATRIX_CONNECTIVITYMATRIX_HPP

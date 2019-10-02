//
// Created by jcheong on 2019-09-29.
//
#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP
#include <vector>
#include <ostream>
#include <iostream>
#include <cmath>

using namespace std;
class Matrix{
private:
    int width;
    int height;
    vector<vector<double>> vectMatrix;
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    friend bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo);
public:
    Matrix(){
        vectMatrix = createMatrix(1,1);
    }
    Matrix(int n){
        if(n <= 0)
            throw "number enter must be greater than zero";
        width = n;
        height = n;
        vectMatrix = createMatrix(n,n);
    }
    Matrix(int r, int c){
        if(r <= 0 && c <= 0)
            throw "number enter must be greater than zero";
        width = r;
        height = c;
        vectMatrix = createMatrix(r, c);
    }
    Matrix(vector<double> vec){
        double sr = sqrt(vec.size());
        if(!(sr - floor(sr)) == 0) {
            throw "array must be integer square";
        }
        height = sqrt(sr);
        width = sqrt(sr);
        vectMatrix = createMatrixSquare(vec);

    }

    vector<vector<double>> createMatrixSquare(vector<double > vec);
    vector<vector<double>> createMatrix(int w, int h);
    void set_value(int r, int c, double value);
    double get_value(int r, int c);
    void clear();

    Matrix operator++(){

    };
    ~Matrix(){};
};
#endif //MATRIX_MATRIX_HPP

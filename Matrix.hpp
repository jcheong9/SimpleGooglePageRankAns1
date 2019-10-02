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
    void clear();
    double const get_value(int r, int c){
        if(r > width || c > height || r < 0 || c < 0){
            throw  "integers are negative or too large.";
        }
        return vectMatrix.at(r).at(c);
    };
    void mySwap(Matrix a, Matrix b);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    friend bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo);
    friend bool operator!=(const Matrix& matrixOne, const Matrix& matrixTwo);
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);
    Matrix operator*=(const Matrix& matrixOne);
    Matrix& operator+=(const Matrix& matrixOne);
    Matrix& operator-=(const Matrix& matrixOne);
    Matrix operator++();
    Matrix operator++(int);
    Matrix operator--();
    Matrix operator--(int);
    Matrix& operator=(Matrix a);

    ~Matrix(){};
};

#endif //MATRIX_MATRIX_HPP

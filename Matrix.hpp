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
    int row;
    int col;
    vector<vector<double>> vectMatrix;
public:
    //default constructor
    Matrix(){
        row = 1;
        col = 1;
        vectMatrix = createMatrix(1,1);
    }
    //constructor take one parameter
    Matrix(int n){
        if(n <= 0)
            throw "number enter must be greater than zero";
        row = n;
        col = n;
        vectMatrix = createMatrix(n,n);
    }
    //constructor take two parameter
    Matrix(int r, int c){
        if(r <= 0 || c <= 0)
            throw "number enter must be greater than zero";
        row = r;
        col = c;
        vectMatrix = createMatrix(r, c);
    }
    //constructor take vector parameter
    Matrix(vector<double> vec){
        double sr = sqrt(vec.size());
        if(!(sr - floor(sr)) == 0 || sr == 0) {
            throw "array must be integer square";
        }
        col = sr;
        row = sr;
        vectMatrix = createMatrixSquare(vec);
    }
    //get value of matrix at user's input
    double const get_value(int r, int c){
        if(r > row || c > col || r < 0 || c < 0){
            throw  "integers are negative or too large.";
        }
        return vectMatrix.at(r).at(c);
    };
    const int getRow(){
        return row;
    }
    const int getColumns(){
        return col;
    }
    const vector<vector<double>> getMatrixVector(){
        return vectMatrix;
    }
    //functions prototypes
    vector<vector<double>> createMatrixSquare(vector<double > vec);
    static vector<vector<double>> createMatrix(int w, int h);
    void set_value(int r, int c, double value);
    void clear();
    Matrix& operator=(Matrix a);
    void mySwap(Matrix& a, Matrix& b);
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
    ~Matrix(){};
};

#endif //MATRIX_MATRIX_HPP

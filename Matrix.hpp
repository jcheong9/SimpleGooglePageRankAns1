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
    //default constructor
    Matrix(){
        width = 1;
        height = 1;
        vectMatrix = createMatrix(1,1);
    }
    //constructor take one parameter
    Matrix(int n){
        if(n <= 0)
            throw "number enter must be greater than zero";
        width = n;
        height = n;
        vectMatrix = createMatrix(n,n);
    }
    //constructor take two parameter
    Matrix(int r, int c){
        if(r <= 0 || c <= 0)
            throw "number enter must be greater than zero";
        width = r;
        height = c;
        vectMatrix = createMatrix(r, c);
    }
    //constructor take vector parameter
    Matrix(vector<double> vec){
        double sr = sqrt(vec.size());
        if(!(sr - floor(sr)) == 0 || sr == 0) {
            throw "array must be integer square";
        }
        height = sr;
        width = sr;
        vectMatrix = createMatrixSquare(vec);
    }
    //get value of matrix at user's input
    double const get_value(int r, int c){
        if(r > width || c > height || r < 0 || c < 0){
            throw  "integers are negative or too large.";
        }
        return vectMatrix.at(r).at(c);
    };
    const int getWidth(){
        return width;
    }
    const int getHeight(){
        return height;
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

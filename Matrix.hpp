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
    //constructors
    Matrix();
    explicit Matrix(int n);
    Matrix(int r, int c);
    explicit Matrix(vector<double> vec);

    //functions prototypes
    double const get_value(int r, int c);
    int const getRow();
    int const getColumns();
    vector<vector<double>> createMatrixSquare(vector<double > vec);
    static vector<vector<double>> createMatrix(int w, int h);
    void set_value(int r, int c, double value);
    void clear();
    void mySwap(Matrix& a, Matrix& b);
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    friend bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo);
    friend bool operator!=(const Matrix& matrixOne, const Matrix& matrixTwo);
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);
    Matrix& operator=(Matrix a);
    Matrix operator*=(const Matrix& matrixOne);
    Matrix& operator+=(const Matrix& matrixOne);
    Matrix& operator-=(const Matrix& matrixOne);
    Matrix operator++();
    const Matrix operator++(int);
    Matrix operator--();
    const Matrix operator--(int);
    ~Matrix()= default;;
};

#endif //MATRIX_MATRIX_HPP

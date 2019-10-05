//
// Created by jcheong on 2019-09-29.
//
#include "Matrix.hpp"
//default constructor
Matrix::Matrix(){
    row = 1;
    col = 1;
    vectMatrix = createMatrix(1,1);
}
//constructor take one parameter
Matrix::Matrix(int n){
    if(n <= 0)
        throw "number enter must be greater than zero";
    row = n;
    col = n;
    vectMatrix = createMatrix(n,n);
}
//constructor take two parameter
Matrix::Matrix(int r, int c){
    if(r <= 0 || c <= 0)
        throw "number enter must be greater than zero";
    row = r;
    col = c;
    vectMatrix = createMatrix(r, c);
}
//constructor take vector parameter
Matrix::Matrix(vector<double> vec){
    double sr = sqrt(vec.size());
    if((sr - floor(sr)) != 0 ) {
        throw "array must be integer square";
    }
    col = sr;
    row = sr;
    vectMatrix = createMatrixSquare(vec);
};
//get value of matrix at user's input
double const Matrix::get_value(int r, int c){
    if(r > row || c > col || r < 0 || c < 0){
        throw  "integers are negative or too large.";
    }
    return vectMatrix.at(r).at(c);
};
//get the row value.
int const Matrix::getRow(){
    return row;
}
//get the column value
int const Matrix::getColumns(){
    return col;
}
//create matrix with the two input size.
vector<vector<double>> Matrix::createMatrix(int w, int h) {
    vector<vector<double> > myVector;
    for (int i = 0; i < w; i++) {
        vector<double> temp;
        myVector.push_back(temp);
        for (int j = 0; j < h; j++) {
            myVector.at(i).push_back(0.0);
        }
    }
    return myVector;
}

//create perfect square matrix using vector input
vector<vector<double>> Matrix::createMatrixSquare(vector<double > vec) {
    vector<vector<double >> vec2D;
    int sr = sqrt(vec.size());
    int count = 0;
    for (int i = 0; i < sr; i++) {
        vector<double> temp;
        vec2D.push_back(temp);
        for (int j = 0; j < sr; j++) {
            vec2D.at(i).push_back(vec.at(count));
            count++;
        }
    }
    return vec2D;
}
//set the values at the input coordinates
void Matrix::set_value(int r, int c, double value){
    if(r > row || c > col || r < 0 || c < 0){
        throw  "integers are negative or too large.";
    }
    vectMatrix.at(r).at(c) = value;
}
//make matrix all zeros
void Matrix::clear(){
    for (int i = 0; i < row; i++) {
        vector<double> temp;
        vectMatrix.push_back(temp);
        for (int j = 0; j < col; j++) {
            vectMatrix.at(i).at(j) = 0.0;
        }
    }
}
//copy& swap method introducing in class
Matrix& Matrix::operator=(Matrix a){
    if (this->row != a.row || this->col != a.col) {
        throw "The martix is not the same size.\n";
    }else {
        mySwap(*this, a);
        return *this;
    }
}
//helper function for operator= overriding
void Matrix::mySwap(Matrix& a, Matrix& b) {
    using std::swap;
    swap(a.row, b.row);
    swap(a.col, b.col);
    swap(a.vectMatrix,b.vectMatrix);
}
//print out matrix using operation overriding
ostream& operator<<(ostream& os, const Matrix& matrix){
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            cout << matrix.vectMatrix.at(i).at(j) << "\t";
        }
        cout << endl;
    }
}
//compare the values and sizes of the matrices return bool.
bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo){
    if(matrixOne.row != matrixTwo.row || matrixOne.col != matrixTwo.col){
        return false;
    }
    for (int i = 0; i < matrixOne.row; i++) {
        for (int j = 0; j < matrixOne.col; j++) {
            return (floor(10000 * matrixOne.vectMatrix.at(i).at(j)) / 10000)
                   == (floor(10000 * matrixTwo.vectMatrix.at(i).at(j)) / 10000);
        }
    }
}
//adds the two matrices returns matrix
 Matrix operator+(Matrix lhs, const Matrix& rhs){
     if (lhs.row != rhs.row || lhs.col != rhs.col) {
         throw "The martix is not the same size.";
     }else{
         Matrix temp {lhs.row, lhs.col};
         for (int i = 0; i < lhs.row; i++)
             for (int j = 0; j < lhs.col; j++){
                 temp.vectMatrix.at(i).at(j) = lhs.vectMatrix.at(i).at(j)
                         + rhs.vectMatrix.at(i).at(j);
             }
        return temp;
     }
 }
 //subtract the two matrices returns Matrix
 Matrix operator-(Matrix lhs, const Matrix& rhs){
     if (lhs.row != rhs.row && lhs.col != rhs.col) {
         throw "The matrix is not the same size.";
     }
     Matrix temp {lhs.row, lhs.col};
     for (int i = 0; i < lhs.row; i++)
         for (int j = 0; j < lhs.col; j++){
             temp.vectMatrix.at(i).at(j) = lhs.vectMatrix.at(i).at(j)
                                           - rhs.vectMatrix.at(i).at(j);
         }
     return temp;
 }
 //multiplying the two matrices returns Matrix
 Matrix operator*(Matrix lhs, const Matrix& rhs) {
     if (lhs.col != rhs.row) {
         throw "The matrix lhs columns must be same as matrix rhs rows";
     }else{
         Matrix temp{lhs.row, rhs.col};
         double sum = 0;
         for (int i = 0; i < lhs.row; i++) {
             for (int j = 0; j < rhs.col; j++) {
                 for (int k = 0; k < rhs.row; k++) {
                     temp.vectMatrix.at(i).at(j) += (lhs.vectMatrix.at(i).at(k)
                             * rhs.vectMatrix.at(k).at(j));
                 }
             }
         }
         return temp;
     }
 }
 //comparsion overriding != of two matrices.
bool operator!=(const Matrix& matrixOne, const Matrix& matrixTwo){
    return (!operator==(matrixOne,matrixTwo));
}
//add the right hand copy matrix to the left matrix and assign into that matrix
Matrix& Matrix::operator+=(const Matrix& matrixOne){
    this->vectMatrix = operator+(*this,matrixOne).vectMatrix;
    return *this;
}
//subtract the right hand copy matrix to the left matrix and assign into that matrix
Matrix& Matrix::operator-=(const Matrix& matrixOne) {
    this->vectMatrix = operator-(*this,matrixOne).vectMatrix;
    return *this;
}
//increment by 1 to all the values in matrix prefix
Matrix Matrix::operator++(){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->vectMatrix.at(i).at(j) += 1; //check
    return *this;
};
//increment by 1 to all the values in matrix postfix
Matrix Matrix::operator++(int){
    Matrix tmp(*this);
    operator++();
    return tmp;
};
//decrement by 1 to all the values in matrix prefix
Matrix Matrix::operator--(){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            this->vectMatrix.at(i).at(j) -= 1; //check
    return *this;
};
//decrement by 1 to all the values in matrix postfix
Matrix Matrix::operator--(int){
    Matrix tmp(*this);
    operator--();
    return tmp;
};
//multiplying the two matrices returns matrix
 Matrix Matrix::operator*=(const Matrix& matrixOne){
     this->vectMatrix = operator*(*this,matrixOne).vectMatrix;
     return *this;
 }


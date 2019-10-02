//
// Created by jcheong on 2019-09-29.
//
#include "Matrix.hpp"

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
vector<vector<double>> Matrix::createMatrixSquare(vector<double > vec) {
    vector<vector<double >> vec2D;
    int sr = sqrt(vec.size());

    for (int i = 0; i < sr; i++) {
        vector<double> temp;
        vec2D.push_back(temp);
        for (int j = 0; j < sr; j++) {
            vec2D.at(i).push_back(0.0);
        }
    }
    return vec2D;
}
void Matrix::set_value(int r, int c, double value){
    if(r > width || c > height || r < 0 || c < 0){
        throw  "integers are negative or too large.";
    }
    vectMatrix.at(r).at(c) = value;
}
void Matrix::clear(){
    for (int i = 0; i < width; i++) {
        vector<double> temp;
        vectMatrix.push_back(temp);
        for (int j = 0; j < height; j++) {
            vectMatrix.at(i).push_back(0.0);
        }
    }
}
void Matrix::mySwap(Matrix a, Matrix b) {
    using std::swap;
    swap(a.width,b.width);
    swap(a.height,b.height);
    swap(a.vectMatrix,b.vectMatrix);
}
ostream& operator<<(ostream& os, const Matrix& matrix){

    for (int i = 0; i < matrix.width; i++) {
        for (int j = 0; j < matrix.height; j++) {
            cout << matrix.vectMatrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo){
    if(matrixOne.width != matrixTwo.width && matrixOne.height != matrixTwo.height){
        return false;
    }

    for (int i = 0; i < matrixOne.width; i++) {
        for (int j = 0; j < matrixOne.height; j++) {
            return (floor(10000 * matrixOne.vectMatrix.at(i).at(j)) / 10000)
                   != (floor(10000 * matrixTwo.vectMatrix.at(i).at(j)) / 10000);
        }
    }
}
bool operator!=(const Matrix& matrixOne, const Matrix& matrixTwo){
    return (!operator==(matrixOne,matrixTwo));
}
Matrix& Matrix::operator+=(const Matrix& matrixOne){
    Matrix temp = operator+(*this,matrixOne);
    return temp;;
}
Matrix& Matrix::operator-=(const Matrix& matrixOne) {
    Matrix temp = operator-(*this,matrixOne);
    return temp;;
}
Matrix Matrix::operator++(){
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            vectMatrix[i][j] += 1;
    return *this;
};
Matrix Matrix::operator++(int){
    Matrix tmp(*this);
    operator++();
    return tmp;
};
Matrix Matrix::operator--(){
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            vectMatrix[i][j] -= 1;
    return *this;
};
Matrix Matrix::operator--(int){
    Matrix tmp(*this);
    operator--();
    return tmp;
};
 Matrix operator+(Matrix lhs, const Matrix& rhs){
     if (lhs.width != rhs.width && lhs.height != rhs.height) {
         throw "The martix is not the same size.";
     }
     Matrix temp {lhs.width,lhs.height};
     for (int i = 0; i < lhs.width; i++)
         for (int j = 0; j < lhs.height; j++){
             temp.vectMatrix.at(i).at(j) = lhs.vectMatrix.at(i).at(j)
                     + rhs.vectMatrix.at(i).at(j);
         }
     return temp;
 }
 Matrix operator-(Matrix lhs, const Matrix& rhs){
     if (lhs.width != rhs.width && lhs.height != rhs.height) {
         throw "The matrix is not the same size.";
     }
     Matrix temp {lhs.width,lhs.height};
     for (int i = 0; i < lhs.width; i++)
         for (int j = 0; j < lhs.height; j++){
             temp.vectMatrix.at(i).at(j) = lhs.vectMatrix.at(i).at(j)
                                           - rhs.vectMatrix.at(i).at(j);
         }
     return temp;
 }
 Matrix operator*(Matrix lhs, const Matrix& rhs) {
     if (lhs.height != rhs.width) {
         throw "The matrix lhs columns must be same as matrix rhs rows";
     }
     Matrix temp{lhs.width, rhs.height};
     double sum = 0;
     for (int i = 0; i < lhs.width; i++)
         for (int j = 0; j < rhs.width; j++) {
             sum +=
         }
 
 }
 Matrix Matrix::operator*=(const Matrix& matrixOne){

 }


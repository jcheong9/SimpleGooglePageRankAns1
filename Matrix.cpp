//
// Created by jcheong on 2019-09-29.
//
#include "Matrix.hpp"
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

    for (int i = 0; i < sr; i++) {
        vector<double> temp;
        vec2D.push_back(temp);
        for (int j = 0; j < sr; j++) {
            vec2D.at(i).push_back(0.0);
        }
    }
    return vec2D;
}
//set the values at the input coordinates
void Matrix::set_value(int r, int c, double value){
    if(r > width || c > height || r < 0 || c < 0){
        throw  "integers are negative or too large.";
    }
    vectMatrix.at(r).at(c) = value;
}
//make martix all zeros
void Matrix::clear(){
    for (int i = 0; i < width; i++) {
        vector<double> temp;
        vectMatrix.push_back(temp);
        for (int j = 0; j < height; j++) {
            vectMatrix.at(i).at(j) = 0.0;
        }
    }
}
//copy& swap method introducing in class
Matrix& Matrix::operator=(Matrix a){
    if (this->width != a.width || this->height != a.height) {
        throw string("The martix is not the same size.\n");
    }else {
        mySwap(*this, a);
        return *this;
    }

}
//helper function for operator= overriding
void Matrix::mySwap(Matrix a, Matrix b) {
    using std::swap;
    swap(a.width,b.width);
    swap(a.height,b.height);
    swap(a.vectMatrix,b.vectMatrix);
}
//print out matrix using operation overriding
ostream& operator<<(ostream& os, const Matrix& matrix){
    for (int i = 0; i < matrix.width; i++) {
        for (int j = 0; j < matrix.height; j++) {
            cout << matrix.vectMatrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
//compare the values and sizes of the matrices return bool.
bool operator==(const Matrix& matrixOne, const Matrix& matrixTwo){
    if(matrixOne.width != matrixTwo.width || matrixOne.height != matrixTwo.height){
        return false;
    }
    for (int i = 0; i < matrixOne.width; i++) {
        for (int j = 0; j < matrixOne.height; j++) {
            return (floor(10000 * matrixOne.vectMatrix.at(i).at(j)) / 10000)
                   == (floor(10000 * matrixTwo.vectMatrix.at(i).at(j)) / 10000);
        }
    }
}
//adds the two matrices returns Martix
 Matrix operator+(Matrix lhs, const Matrix& rhs){
     if (lhs.width != rhs.width || lhs.height != rhs.height) {
         throw "The martix is not the same size.";
     }else{
         Matrix temp {lhs.width,lhs.height};
         for (int i = 0; i < lhs.width; i++)
             for (int j = 0; j < lhs.height; j++){
                 temp.vectMatrix.at(i).at(j) = lhs.vectMatrix.at(i).at(j)
                         + rhs.vectMatrix.at(i).at(j);
             }
        return temp;
     }
 }
 //subtract the two matrices returns Martix
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
 //multiplying the two matrices returns Martix
 Matrix operator*(Matrix lhs, const Matrix& rhs) {
     if (lhs.height != rhs.width) {
         throw "The matrix lhs columns must be same as matrix rhs rows";
     }else{
         Matrix temp{lhs.width, rhs.height};
         double sum = 0;
         for (int i = 0; i < lhs.width; i++) {
             for (int j = 0; j < rhs.width; j++) {
                 for (int k = 0; k < rhs.width; k++) {
                     temp.vectMatrix.at(i).at(j) += lhs.vectMatrix.at(i).at(k)
                             * rhs.vectMatrix.at(k).at(j);
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
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            vectMatrix.at(i).at(j) += 1;
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
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            vectMatrix[i][j] -= 1;
    return *this;
};
//decrement by 1 to all the values in matrix postfix
Matrix Matrix::operator--(int){
    Matrix tmp(*this);
    operator--();
    return tmp;
};
//multiplying the two matrices returns Martix
 Matrix Matrix::operator*=(const Matrix& matrixOne){
     this->vectMatrix = operator*(*this,matrixOne).vectMatrix;
     return *this;
 }


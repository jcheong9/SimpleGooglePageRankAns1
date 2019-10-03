#include <iostream>
#include "Matrix.hpp"


int main() {
        cout << "Hello, World!" << std::endl;
        Matrix matrixOne {2};
        Matrix matrixTwo {2};
        Matrix matrixThree {2,3};
        Matrix matrixFour ;
//    vector<double > vet;
//    Matrix matrixFive {vet};

        for(int i = 0; i<2;i++){
            for(int k = 0; k<2;k++) {
                matrixOne.set_value(i,k, 5);
                matrixTwo.set_value(i,k, 3);
            }
        }
        matrixTwo.set_value(0,1, 4);
        for(int i = 0; i<2;i++){
            for(int k = 0; k<3;k++) {
                matrixThree.set_value(i,k, 3.44456);
            }
        }
        cout << matrixOne;
        cout << matrixTwo;
        cout << "---------" << "\n";
        matrixOne--;
        cout << matrixOne;
        //cout << matrixTwo;
//    cout << matrixOne*matrixThree <<endl;
//    cout << matrixOne+matrixTwo <<endl;



    return 0;
}
#include <iostream>
#include "ConnectivityMatrix.hpp"

const int sizeConMatrix = 4;
const double randChance = 0.25;
int main() {
    vector<double> sumColumns;
    ConnectivityMatrix S{sizeConMatrix};
    Matrix Q{sizeConMatrix};
    Matrix M{sizeConMatrix};
    double sum;
    //take the sum of each value and put it in vector
    for(int i = 0; i < S.getWidth(); i++){
        sum = 0;
        for(int k = 0; k < S.getHeight(); k++){
            sum+=S.get_value(i, k);
        }
        sumColumns.push_back(sum);
    }
    //divide the sum of each column by it value.
    for(int i = 0; i < S.getWidth(); i++){
        for(int k = 0; k < S.getHeight(); k++){
            if(S.get_value(i, k) != 0)
                S.set_value(i, k, (S.get_value(i, k) / sumColumns.at(i)));
        }
    }
    //Set last column to 0.25
    for(int k = 0; k < S.getHeight(); k++){
        S.set_value(k,3,randChance);
    }
    //divide the sum of each column by it value.
    for(int i = 0; i < S.getWidth(); i++)
        for(int k = 0; k < S.getHeight(); k++)
            Q.set_value(i,k,randChance);



    cout << S;
    return 0;
}

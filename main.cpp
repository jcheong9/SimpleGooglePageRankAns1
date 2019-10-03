#include <iostream>
#include "ConnectivityMatrix.hpp"

const int sizeConMatrix = 4;
const double randChance = 0.25;
const double probClickValue = 0.85;
const double probTelValue = 0.15;
int main() {
    vector<double> sumColumns;
    ConnectivityMatrix S{sizeConMatrix};
    Matrix Q{sizeConMatrix};
    Matrix M{sizeConMatrix};
    Matrix rankMat{4,1};
    double sum;
    double sumRank;
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
    //q contains all 0.25.
    for(int i = 0; i < S.getWidth(); i++)
        for(int k = 0; k < S.getHeight(); k++)
            Q.set_value(i,k,randChance);

    //probability click links all 0.85
    for(int i = 0; i < S.getWidth(); i++)
        for(int k = 0; k < S.getHeight(); k++)
            S.set_value(i,k,(S.get_value(i,k)*probClickValue));

    //probability click links all 0.15
    for(int i = 0; i < Q.getWidth(); i++)
        for(int k = 0; k < Q.getHeight(); k++)
            Q.set_value(i,k,(Q.get_value(i,k)*probTelValue));

    //add S and Q to get M
    M = (S + Q);
    //rankMat is 4 by 1 matrix assigning all 1s.
    for(int i = 0; i < rankMat.getWidth(); i++)
        for(int k = 0; k < rankMat.getHeight(); k++)
            rankMat.set_value(i,k,1);

    //Markov process until rank is stablized
    while(rankMat != (M * rankMat)){
        rankMat = (M * rankMat);
    }

    //get the sum of the rank column
    for(int i = 0;i < rankMat.getWidth();i++)
        sumRank+=rankMat.get_value(i,rankMat.getHeight()-1);

    for(int i = 0;i< rankMat.getWidth();i++) {
        double tempValue = rankMat.get_value(i,0)/sumRank;
        rankMat.set_value(i,0, tempValue*100);
    }
    //print out result and format
    cout << "Page A: " << to_string(rankMat.get_value(0,0)).substr(0, 5) << "%" << endl;
    cout << "Page B: " << to_string(rankMat.get_value(1,0)).substr(0, 5) << "%" << endl;
    cout << "Page C: " << to_string(rankMat.get_value(2,0)).substr(0, 5) << "%" << endl;
    cout << "Page D: " << to_string(rankMat.get_value(3,0)).substr(0, 4) << "%" << endl;
    return 0;
}

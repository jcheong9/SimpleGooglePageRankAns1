#include <iostream>
#include <fstream>
#include <sstream>
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
    double sumRank = 0;
    double numInText;
    vector<double> fileVectNumber;
    ifstream infile("connectivity.txt");
    string line;
    stringstream stream;

    if (infile.is_open()) {

        while(!infile.eof()){
            stream.clear();
//            getline(infile, line);
//            stream.str(line);
//            stream >> numInText;
//            fileVectNumber.push_back(numInText);
        }
    }
    infile.close();
    Matrix connectivity{fileVectNumber};
    cout << connectivity;

//take the sum of each value and put it in vector
    for(int i = 0; i < S.getRow(); i++){
        sum = 0;
        for(int k = 0; k < S.getColumns(); k++){
            sum+=S.get_value(i, k);
        }
        sumColumns.push_back(sum);
    }
//divide the sum of each column by it value.
    for(int i = 0; i < S.getRow(); i++){
        for(int k = 0; k < S.getColumns(); k++){
            if(S.get_value(i, k) != 0)
                S.set_value(i, k, (S.get_value(i, k) / sumColumns.at(i)));
        }
    }
//Set last column to 0.25
    for(int k = 0; k < S.getColumns(); k++){
        S.set_value(k,3,randChance);
    }
//q contains all 0.25.
    for(int i = 0; i < S.getRow(); i++)
        for(int k = 0; k < S.getColumns(); k++)
            Q.set_value(i,k,randChance);

//probability click links all 0.85
    for(int i = 0; i < S.getRow(); i++)
        for(int k = 0; k < S.getColumns(); k++)
            S.set_value(i,k,(S.get_value(i,k)*probClickValue));

//probability click links all 0.15
    for(int i = 0; i < Q.getRow(); i++)
        for(int k = 0; k < Q.getColumns(); k++)
            Q.set_value(i,k,(Q.get_value(i,k)*probTelValue));

//add S and Q to get M
    M = (S + Q);
//rankMat is 4 by 1 matrix assigning all 1s.
    for(int i = 0; i < rankMat.getRow(); i++)
        for(int k = 0; k < rankMat.getColumns(); k++)
            rankMat.set_value(i,k,1);

//Markov process until rank is stablized
    while(rankMat != (M * rankMat)){
        rankMat = (M * rankMat);
    }

//get the sum of the rank column
    for(int i = 0;i < rankMat.getRow(); i++)
        sumRank+=rankMat.get_value(i, rankMat.getColumns() - 1);

    for(int i = 0;i< rankMat.getRow(); i++) {
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

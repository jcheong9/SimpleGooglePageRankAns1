#include <iostream>
#include <fstream>
#include <sstream>
#include "ConnectivityMatrix.hpp"
#include "calculationMatrix.hpp"
//constant
const int sizeConMatrix = 4;
//function prototypes
void readFile(vector<double> *numInText);
void printRanking(Matrix rankMat);

int main() {
    ConnectivityMatrix S{sizeConMatrix};
    Matrix Q{sizeConMatrix};
    Matrix M{sizeConMatrix};
    Matrix rankMat{sizeConMatrix,1};
    vector<double> numInText;
    //read file
    readFile(&numInText);
    Matrix connectivity{numInText};

    //set up S and Q for summation
    setClickLinksAndTeleport(&S, &Q);

    //add S and Q to get M
    M = (S + Q);

    setRankMatrixToOnes(&rankMat);
    rankMat = applyMarkovProcess(M, rankMat);
    //print out result and format
    printRanking( rankMat);

    return 0;
}
void printRanking(Matrix rankMat){
    cout << "Page A: " << to_string(rankMat.get_value(0,0)).substr(0, 5) << "%" << endl;
    cout << "Page B: " << to_string(rankMat.get_value(1,0)).substr(0, 5) << "%" << endl;
    cout << "Page C: " << to_string(rankMat.get_value(2,0)).substr(0, 5) << "%" << endl;
    cout << "Page D: " << to_string(rankMat.get_value(3,0)).substr(0, 4) << "%" << endl;
}


void readFile(vector<double> *numInText){
    ifstream infile;
    infile.open("connectivity.txt");
    string line;
    stringstream stream;
    if (infile.is_open()) {
        while(!infile.eof()){
            stream.clear();
            getline(infile, line);
            stream.str(line);
            for (int i; stream >> i;) {
                numInText->push_back(i);
                if (stream.peek() == ' ')
                    stream.ignore();
            }
        }
    }
    infile.close();
}


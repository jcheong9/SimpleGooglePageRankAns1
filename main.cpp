#include <iostream>
#include <fstream>
#include <sstream>
#include "ConnectivityMatrix.hpp"
#include "calculationMatrix.hpp"

const int sizeConMatrix = 4;
//const double randChance = 0.25;
//const double probClickValue = 0.85;
//const double probTelValue = 0.15;
void readFile(vector<double> *numInText);

int main() {
//    vector<double> sumColumns;
    ConnectivityMatrix S{sizeConMatrix};
    Matrix Q{sizeConMatrix};
    Matrix M{sizeConMatrix};
    Matrix rankMat{4,1};
    vector<double> numInText;
    vector<double> fileVectNumber;
    readFile(&numInText);
    Matrix connectivity{numInText};


    sumColumnDivideBySum(&S);
    setLastColumnRandomChance(&S);
    setAllValuesToRandomChance(&Q);
    setRandomWalkProbability(&S);
    setTeleportationProbability(&Q);

//add S and Q to get M
    M = (S + Q);

    setRankMatrixToOnes(&rankMat);
    rankMat = applyMarkovProcess(M, rankMat);

//print out result and format
    cout << "Page A: " << to_string(rankMat.get_value(0,0)).substr(0, 5) << "%" << endl;
    cout << "Page B: " << to_string(rankMat.get_value(1,0)).substr(0, 5) << "%" << endl;
    cout << "Page C: " << to_string(rankMat.get_value(2,0)).substr(0, 5) << "%" << endl;
    cout << "Page D: " << to_string(rankMat.get_value(3,0)).substr(0, 4) << "%" << endl;
    return 0;
}
//void printRanking(){
//
//}


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


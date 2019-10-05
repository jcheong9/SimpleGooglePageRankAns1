//
// Created by jcheong on 2019-10-03.
//

#include "calculationMatrix.hpp"
//----------------------------------------------------------------
//The function takes ConnectivityMatrix S and Matrix Q
//Set the matrix to the correct matrix for transition matrix M
//returns void.
//----------------------------------------------------------------
void setClickLinksAndTeleport(ConnectivityMatrix *S, Matrix *Q){
    sumColumnDivideBySum(S);
    setLastColumnRandomChance(S);
    setAllValuesToRandomChance(Q);
    setRandomWalkProbability(S);
    setTeleportationProbability(Q);
}
//----------------------------------------------------------------
//The function takes ConnectivityMatrix and sum the columns
//then divide each columns values by the sum
//returns void.
//----------------------------------------------------------------
void sumColumnDivideBySum(ConnectivityMatrix *S){
    double sum;
    vector<double> sumColumns;
    for(int i = 0; i < S->getRow(); i++){
    sum = 0;
        for(int k = 0; k < S->getColumns(); k++){
            sum+=S->get_value(i, k);
        }
        sumColumns.push_back(sum);
    }
    for(int i = 0; i < S->getRow(); i++){
        for(int k = 0; k < S->getColumns(); k++){
            if(S->get_value(i, k) != 0)
            S->set_value(i, k, (S->get_value(i, k) / sumColumns.at(i)));
        }
    }
}
//----------------------------------------------------------------
//The function takes ConnectivityMatrix and set the last
//column to 0.25 (random chance value)
//returns void.
//----------------------------------------------------------------
void setLastColumnRandomChance(ConnectivityMatrix *S){
//Set last column to 0.25
    for(int k = 0; k < S->getColumns(); k++){
        S->set_value(k,3,randChance);
    }
}
//----------------------------------------------------------------
//The function takes Matrix and set all values
//to 0.25 (random chance value)
//returns void.
//----------------------------------------------------------------
void setAllValuesToRandomChance(Matrix *Q){
//q contains all 0.25.
for(int i = 0; i < Q->getRow(); i++)
    for(int k = 0; k < Q->getColumns(); k++)
        Q->set_value(i,k,randChance);
}
//----------------------------------------------------------------
//The function takes ConnectivityMatrix and times all values
//to 0.85 (Random Walk Probability Factor)
//returns void.
//----------------------------------------------------------------
void setRandomWalkProbability(ConnectivityMatrix *S){
//probability click links all 0.85
for(int i = 0; i < S->getRow(); i++)
    for(int k = 0; k < S->getColumns(); k++)
        S->set_value(i,k,(S->get_value(i,k)*probClickValue));

}
//----------------------------------------------------------------
//The function takes Matrix and times all values
//to 0.15 (Random Walk Probability Factor)
//returns void.
//----------------------------------------------------------------
void setTeleportationProbability(Matrix *Q){
//probability click links all 0.15
for(int i = 0; i < Q->getRow(); i++)
    for(int k = 0; k < Q->getColumns(); k++)
        Q->set_value(i,k,(Q->get_value(i,k)*probTelValue));
}
//----------------------------------------------------------------
//The function takes Matrix and set all values
//to 1 for starting rank matrix.
//returns void.
//----------------------------------------------------------------
void setRankMatrixToOnes(Matrix *rankMat){
//rankMat is 4 by 1 matrix assigning all 1s.
for(int i = 0; i < rankMat->getRow(); i++)
    for(int k = 0; k < rankMat->getColumns(); k++)
        rankMat->set_value(i,k,1);
}
//----------------------------------------------------------------
//The function takes Matrix M and Matrix rankMat
//and applies Markov Process until get converges result.
//returns Matrix.
//----------------------------------------------------------------
Matrix applyMarkovProcess(Matrix M, Matrix rankMat){
    double sumRank = 0;
    //Markov process until rank is stablized
    while(rankMat != (M * rankMat)) {
        rankMat = (M * rankMat);
    }
    //get the sumRank of the rank column
    for(int i = 0;i < rankMat.getRow(); i++)
        sumRank+=rankMat.get_value(i, rankMat.getColumns() - 1);
    //divide the sumRank to all the values in M
    for(int i = 0;i< rankMat.getRow(); i++) {
        double tempValue = rankMat.get_value(i,0)/sumRank;
        //set to percentage
        rankMat.set_value(i,0, tempValue*100);
    }
    return rankMat;
}


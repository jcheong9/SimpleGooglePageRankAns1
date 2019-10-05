//
// Created by jcheong on 2019-10-03.
//

#ifndef MATRIX_CALCULATIONMATRIX_HPP
#define MATRIX_CALCULATIONMATRIX_HPP

#include "ConnectivityMatrix.hpp"

//constant
const double randChance = 0.25;
const double probClickValue = 0.85;
const double probTelValue = 0.15;

//function prototypes
void setClickLinksAndTeleport(ConnectivityMatrix *S, Matrix *Q);
void sumColumnDivideBySum(ConnectivityMatrix *S);
void setLastColumnRandomChance(ConnectivityMatrix *S);
void setAllValuesToRandomChance(Matrix *Q);
void setRandomWalkProbability(ConnectivityMatrix *S);
void setTeleportationProbability(Matrix *Q);
void setRankMatrixToOnes(Matrix *rankMat);
Matrix applyMarkovProcess(Matrix M, Matrix rankMat);
#endif //MATRIX_CALCULATIONMATRIX_HPP

#include <iostream>
#include "ConnectivityMatrix.hpp"

const int sizeConMatrix = 4;
int main() {
    
    ConnectivityMatrix conMatrix{sizeConMatrix};

    cout << conMatrix;
    return 0;
}
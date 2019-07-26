#include "spiral.h"
#include <fstream>
#include <string>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

spiral::spiral(const char *inputFileName) {
    // read input from file into ourString
    if (inputFileName != nullptr) {
        std::ifstream inputStream(inputFileName);
        while (getline(inputStream, ourString)) {
            getline(inputStream, ourString);
        }
    }
    // replaces the matrixSideSize function
    matrixSize = ceil(sqrt(strlen(ourString.c_str())));
    for(int i = ourString.size(); i < matrixSize * matrixSize; i++){
        ourString += '.';
    }
}

void spiral::spiralMaker() {
    spiralMaker(ourString, matrixSize);
}

void spiral::spiralMaker(string inputString, int matrixSideSize) {
    int row = 0;
    int col = -1;
    
    int stringIndexVal = 0;
    int side = matrixSideSize;
    int matrixTotal = matrixSideSize * matrixSideSize;
    
    ourSpiral = new char*[matrixTotal];
    
    for(int i = 0; i < matrixTotal; i++)
        ourSpiral[i] = new char[matrixSize];
    
    while(stringIndexVal < matrixTotal) {
        for (int i = 0; i < matrixSideSize; i++) {
            col++;
            ourSpiral[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }
        
        matrixSideSize--;
        
        for (int i = 0; i < matrixSideSize; i++){
            row++;
            ourSpiral[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }
        
        for (int i = 0; i < matrixSideSize; i++){
            col--;
            ourSpiral[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }
        
        matrixSideSize--;
        
        for (int i = 0; i < matrixSideSize; i++){
            row--;
            ourSpiral[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }
    }
    for (int i = 0; i < side; i++){
        for (int j = 0; j < side; j++){
            cout << ourSpiral[i][j];
        }
        cout << endl;
    }
}

void spiral::printToOutput(const char* outputFileName) {
    ofstream outFile;
    outFile.open(outputFileName);
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            outFile << ourSpiral[i][j];
        }
        outFile << endl;
    }
    outFile.close();
}

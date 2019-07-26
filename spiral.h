#ifndef SPIRAL_H
#define SPIRAL_H
#include <string>


class spiral {
private:
    char ** ourSpiral;
    int matrixSize;
    std::string ourString;
    void spiralMaker(std::string inputString, int matrixSideSize);
    
public:
    spiral(const char* inputFileName);
    void printToOutput(const char* outputFileName);
    void spiralMaker();
    
    
};


#endif //SPIRAL_H

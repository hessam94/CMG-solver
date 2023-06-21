#include "coreFunctions.h"

void display(std::string s)
{
    //ofstream outClientFile("outputFile.txt", ios::out); 
    //std::ostream& ost = outClientFile;
    std::ostream& ost = std::cout;
    ost << std::endl << s << std::endl;
}


int validate_input(const matrix& A, matrix& A_)
{
    return 1;
}
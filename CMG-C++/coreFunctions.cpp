#include "coreFunctions.h"

void display(std::string s)
{
    //ofstream outClientFile("outputFile.txt", ios::out); 
    //std::ostream& ost = outClientFile;
    std::ostream& ost = std::cout;
    ost << s << std::endl;
}
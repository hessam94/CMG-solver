#ifndef coreFunctions_H
#define coreFunctions_H

#include <iostream>
#include <fstream>
#include <vector>
#include "mex/cmg.h"
#include <string>

using namespace std;
void cmg_precondition(std::vector<int>  pfun, std::vector<shlevel> H, int& flag, matrix A, int opts);

void display(std::string s);

#endif // !codeFunctions_H
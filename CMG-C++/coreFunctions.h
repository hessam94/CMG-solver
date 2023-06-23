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
int validate_input(const matrix& A, matrix& A_);
shlevel level_init();
matrix sparse();
int nnz(matrix m); // number of non zero item in a matrix, matlab builtin function
matrix diag(matrix m);// need to figure out about this matlab function
pair<mIndex*, int> steiner_group(matrix A, matrix dA_); // cI is mindex* so means array

// template function must be implemented fully in a file. cannot be separated into .h and .cpp. (compile error)
template<typename T>
T max_of_array(T* arr)
{
    T maxi = arr[0];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        if (arr[i] > maxi) maxi = arr[i];

    return maxi;
}

matrix matrix_mult(int multiplier, matrix m);

matrix matrix_div(int divider, matrix m);

#endif // !codeFunctions_H
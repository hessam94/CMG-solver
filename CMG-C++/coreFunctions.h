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
matrix sparse(mIndex*, int startIndex, int endIndex, int , int nc, int n); 
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
matrix matrix_mult(matrix m1, matrix m2);
matrix matrix_div(int divider, matrix m);
matrix transpose(matrix m);

void crop_matrix(const matrix& input_matrix, int left, int right, int up, int bottom, matrix& output_matrix);
matrix make_preconditioner(vector<shlevel>& H);

mSize* ldl_(const matrix& A, matrix& L, matrix& D); // function [L,D,p] = ldl_(A) we want to return p as int;

#endif // !codeFunctions_H
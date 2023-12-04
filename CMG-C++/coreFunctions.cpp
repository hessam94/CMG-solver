#include "coreFunctions.h"
// here is the test...
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

shlevel level_init()
{


    //% used for last level


    shlevel S;
    //S.sd = true;
    S.islast = 0;
    S.iterative = 1;
    S.A = sparse(); // equal to sparse([]) in the main matlab code
    S.invD = 0;
    S.cI = 0;
    S.nc = 0;
    //S.R = sparse(); there is R attribute in the shlevel struct
    S.repeat = 0;
    S.chol.ld = sparse();
    S.chol.ldT = sparse();
    //S.chol.d = 0; not found s.chol.d in the sturct
    S.chol.p = 0;

    return S;
}

matrix sparse()
{
    matrix m;
    return m;
}

int nnz(matrix m)
{
    return 0;// default
}

matrix diag(matrix m)
{
    matrix diag_m;
    return diag_m;
}

pair<mIndex*, int> steiner_group(matrix A, matrix dA_)
{
    pair <mIndex*, int> p;// p.first  = cI, p.second = nc

    return p;
}

matrix matrix_mult(int multiplier, matrix m)
{
    matrix res;
    return res;
}

matrix matrix_div(int divider, matrix m)
{
    matrix res;
    return res;
}
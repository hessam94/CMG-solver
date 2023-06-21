#include <iostream>
#include <vector>
#include"coreFunctions.h"

using namespace std;

void cmg_precondition(vector<int> pfun, vector<shlevel> H, int& flag, matrix  A, int opts)
{
    matrix A_;

	if (A.n < 500)
	{
		pfun = {};
		H = {};
		flag = 0;
		display("Input matrix is small. Solve Ax=b with A\b");
		return;
	}


    if (opts == 1)
    {

        int flag = validate_input(A, A_);

        if (flag == 1)
        {
            display("The input matrix must be symmetric");
            pfun = {};
            return;
        }
        else if (flag == 2)
        {
            display("The current version of CMG does not support positive off-diagonals");
            pfun = {};
            return;
        }
    }

    else
    {
        flag = 2;
        A_ = A;
    }
}

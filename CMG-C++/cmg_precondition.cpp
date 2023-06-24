#include <iostream>
#include <vector>
#include"coreFunctions.h"

using namespace std;

void cmg_precondition(vector<int> pfun, vector<shlevel> H, int& flag, matrix  A, int opts)
{
	matrix A_, dA_;
	shlevel S_init;
	bool loop;
	int j, h_nnz, nc;
	mIndex* cI; // array of integer
	// A.n = Length(A) ???
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

	S_init = level_init();
	H.push_back(S_init);

	// A_ is Laplacian
	// there is no .sd for this struct, in this version
		//if (A_.n > A.n)
		//    H[0].sd = true; // original matrix is strongly dominant
		//else
		//    H[0].sd = false;


   // construct hierarchy
	loop = true;
	j = 0; // j = 1 in matlab code, perhaps the first item of array which is zero in C++
	h_nnz = 0;

	while (loop)
	{
		int n = A.n;
		// direct method for small size
		if (n < 700)
		{
			H[j].iterative = 0;
			break;
		}

		dA_ = diag(A_);
		cI = steiner_group(A_, dA_).first; // as mentioned in main code, [cI, ~] seem we dont need the second output here. so just take the first
		nc = max_of_array(cI);

		H[j].islast = 0;
		H[j].A = A_;
		// H[j].invD =  ???   // 1. / (2 * dA_); no idea about what this means
		H[j].cI = cI;
		H[j].nc = nc;
		//H[ j ].R = sparse(cI, 1:n, ones(n, 1), nc, n);% added for efficiency

			// check for full contraction
		if (nc == 1)
		{
			H[ j ].islast = 1;
			H[ j ].iterative = 1;
			flag = 1;
			break;
		}

	}

}

int y = 0;
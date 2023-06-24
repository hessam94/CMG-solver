#include <iostream>
#include <vector>
#include"coreFunctions.h"

using namespace std;

void cmg_precondition(vector<int> pfun, vector<shlevel> H, int& flag, matrix  A, int opts)
{
	matrix A_, dA_, Rt;
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
			H[j].islast = 1;
			H[j].iterative = 1;
			flag = 1;
			break;
		}

		// check for hierarchy stagnation for potentially bad reasons
		h_nnz = h_nnz + nnz(A_);
		if ((nc >= (n - 1)) || (h_nnz > (5 * nnz(H[0].A))))
		{
			H[j].islast = 1;
			H[j].iterative = 1;
			flag = 3; // indicates stagnation
			cout << "CMG convergence may be slow due to matrix density.Future versions of CMG will eliminate this problem.";
			break;
		}


		Rt = sparse(cI, 1, n, 1, nc, n); // cI should be cast to double sparse(double(cI),1:n,1,nc,n);
		A_ = matrix_mult(Rt, matrix_mult(H[j].A, transpose(Rt)));

		j = j + 1;
		H[j] = S_init; // initialize level
	}

	// code for last hierarchy level
	if (flag == 0) // no previous error
	{
		H[j].islast = 1;
		H[j].iterative = 0;
		matrix A_cropped;
		crop_matrix(A_, 1, A.n - 1, 1, A.n - 1, A_cropped);
		H[j].A = A_cropped;
		// [L, D, p] = ldl(H{ j }.A, 'vector');
		matrix D, L;
		mSize* p = ldl_(A_cropped, L, D);
		H[j].chol.ld = L;
		H[j].chol.ldT = transpose(L);
		//H[j].chol.d = matrix_div(1,diag(D)); // cholesky struct doens't have d
		H[j].chol.p = p; // x = A * y = > y(p) = LT\(H{ j }.d.*(L\x(p)));
	}


	//determine number of recursive calls between levels
	for (int k = 0; k < (j - 2); k++)
		H[k].repeat = max(floor(nnz(H[k].A) / nnz(H[k + 1].A) - 1), 1.0);
	
		if (flag == 0)
			H[j - 1].repeat = max(floor(nnz(H[ j - 1].A) / nnz(H[ j ].chol.ld) - 1), 1.0);
		else
			H[j - 1].repeat = max(floor(nnz(H[j - 1].A) / nnz(H[ j ].A) - 1), 1.0);

		// H = cell2mat(H);

	// create precondition function
		matrix pfun = make_preconditioner(H);
}


#include <iostream>
#include <vector>
#include"coreFunctions.h"

using namespace std;

void cmg_precondition(vector<int> pfun, vector<shlevel> H, int& flag, matrix  A, int opts)
{
	if (A.n < 500)
	{
		pfun = {};
		H = {};
		flag = 0;
		display("Input matrix is small. Solve Ax=b with A\b");
		return;
	}
}

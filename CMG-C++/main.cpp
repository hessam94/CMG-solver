#include <iostream>
#include <vector>
#include "coreFunctions.h"

using namespace std;
void main()
{
	cout << "Hello Cmg-solver..";
	vector<int> pfun;
	vector<shlevel>  H;
	int flag = 0;
	int opts = 1;
	matrix A;
	A.n = 550;
	cmg_precondition(pfun, H, flag,A,  opts);
	system("Pause");
}
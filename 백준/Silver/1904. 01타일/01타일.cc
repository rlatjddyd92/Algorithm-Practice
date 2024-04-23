#include <iostream>

using namespace std;

struct Dp
{
	int iDivide;
	int iRemain;
};

int main()
{
	int iNum = 0;

	cin >> iNum;

	Dp* iDp = new Dp[iNum + 1];

	iDp[0] = { 0,0 };
	iDp[1] = { 0,1 };

	if (2 <= iNum)
		iDp[2] = { 0,2 };

	for (int i = 3; i <= iNum; ++i)
	{
		int iTempDivide = iDp[i - 2].iDivide + iDp[i - 1].iDivide;
		int iTempRemain = iDp[i - 2].iRemain + iDp[i - 1].iRemain;

		if (0 != iTempRemain / 15746)
		{
			iTempDivide += iTempRemain / 15746;
			iTempRemain = iTempRemain % 15746;
		}

		iDp[i] = { iTempDivide ,iTempRemain };
	}

	cout << iDp[iNum].iRemain;

	delete[]iDp;
	iDp = nullptr;

	return 0;
}
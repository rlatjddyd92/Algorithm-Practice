#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iInput = 0;
	int iCount = 0;

	cin >> iInput;

	vector<int> vecdp(iInput+1);

	vecdp[1] = 1;
	
	for (int i = 2; i <= iInput; ++i)
	{
		int iMin = vecdp[1] + vecdp[i - 1];
		int iNum = 2;
		
		while (1)
		{
			if (i < pow(iNum, 2))
				break;

			if (iMin > vecdp[i - pow(iNum, 2)] + 1)
				iMin = vecdp[i - pow(iNum, 2)] + 1;

			++iNum;
		}
		
		vecdp[i] = iMin;
		
	}

	cout << vecdp[iInput];

	vecdp.clear();
	vector<int>().swap(vecdp);

	return 0;
}
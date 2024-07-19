#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCoin = 0;
	int iMax = 0;
	int iAnswer = 0;

	cin >> iCoin >> iMax;

	vector<int> vecCoin;
	vector<int> vecSum;
	vecCoin.resize(iCoin);
	vecSum.resize(iMax + 1);

	for (int i = 0; i < iCoin; ++i)
		cin >> vecCoin[i];

	for (int i = 0; i < iCoin; ++i)
		for (int j = 1; j <= iMax; ++j)
		{
			if (vecCoin[i] == j)
				vecSum[j] = 1;
			else if ((vecCoin[i] < j) && (vecSum[j - vecCoin[i]] > 0))
				if ((vecSum[j] == 0)||(vecSum[j - vecCoin[i]] + 1 < vecSum[j]))
					vecSum[j] = vecSum[j - vecCoin[i]] + 1;

			if (j == iMax)
				if ((iAnswer == 0) || (vecSum[j] < iAnswer))
					iAnswer = vecSum[j];
		}

	if (iAnswer == 0)
		iAnswer = -1;

	cout << iAnswer;

	vecCoin.clear();
	vecSum.clear();

	return 0;
}
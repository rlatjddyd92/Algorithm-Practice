#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iCoin = 0;
		int iMax = 0;

		cin >> iCoin;

		vector<int> vecCoin; 
		vecCoin.resize(iCoin);

		for (int j = 0; j < iCoin; ++j)
			cin >> vecCoin[j];

		cin >> iMax;

		vector<int> vecSum;
		vecSum.resize(iMax + 1);

		for (int j = 0; j < iCoin; ++j)
			for (int k = 0; k <= iMax; ++k)
			{
				if (k == 0)
					vecSum[k] = 1;
				else if (vecCoin[j] <= k)
					vecSum[k] += vecSum[k - vecCoin[j]];
			}

		cout << vecSum[iMax] << "\n";

		vecCoin.clear();
		vecSum.clear();
	}

	return 0;
}
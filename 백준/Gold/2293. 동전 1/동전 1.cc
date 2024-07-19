#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iMax = 0;

	cin >> iNum >> iMax;

	vector<int> vecCoin;
	vecCoin.resize(iNum + 1);

	vector<int> vecSum;
	vecSum.resize(iMax + 1);
	vecSum[0] = 1;

	for (int i = 1; i <= iNum; ++i)
		cin >> vecCoin[i];

	for (int i = 1; i <= iNum; ++i)
		for (int j = 0; j <= iMax; ++j)
			if (vecCoin[i] <= j)
				vecSum[j] += vecSum[j - vecCoin[i]];

	cout << vecSum[iMax];

	vecCoin.clear();
	vecSum.clear();

	return 0;
}
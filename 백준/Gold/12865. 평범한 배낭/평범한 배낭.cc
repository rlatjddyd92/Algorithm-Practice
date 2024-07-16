#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct GOODS
{
	int iValue;
	int iWeight;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iGoods = 0;
	int iMax = 0;

	cin >> iGoods >> iMax;

	vector<GOODS> vecGoods;
	vecGoods.resize(iGoods + 1);

	for (int i = 1; i <= iGoods; ++i)
		cin >> vecGoods[i].iWeight >> vecGoods[i].iValue;

	vector<vector<int>> vecSumVal;
	vecSumVal.resize(iGoods + 1);
	vecSumVal[0].resize(iMax + 1);

	for (int i = 1; i <= iGoods; ++i)
	{
		vecSumVal[i].resize(iMax + 1);

		for (int j = 1; j <= iMax; ++j)
		{
			int iRemain = j - vecGoods[i].iWeight;

			if (iRemain < 0)
				vecSumVal[i][j] = vecSumVal[i - 1][j];
			else
				vecSumVal[i][j] = max((vecGoods[i].iValue + vecSumVal[i - 1][iRemain]), vecSumVal[i - 1][j]);
		}
	}

	int iAnswer = 0;

	for (int i = 1; i <= iGoods; ++i)
		if (vecSumVal[i][iMax] > iAnswer)
			iAnswer = vecSumVal[i][iMax];

	cout << iAnswer;

	for (int i = 1; i <= iGoods; ++i)
		vecSumVal[i].clear();

	vecSumVal.clear();
	vecGoods.clear();

	return 0;
}
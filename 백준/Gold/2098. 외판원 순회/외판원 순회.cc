#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<long long>> vecDP;
vector<vector<long long>> vecCost;

long long iCity = 0;
long long iTotalRoute = 0;
const long long iMax = 100 * 100 * 100 * 100;

int Check_Route(long long iNext, long long iVisited);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iCity;

	vecCost.resize(iCity + 1);
	for(auto& iter : vecCost)
		iter.resize(iCity + 1);

	for (long long i = 1; i <= iCity; ++i)
		for (long long j = 1; j <= iCity; ++j)
			cin >> vecCost[i][j];

	iTotalRoute = pow(2, iCity);

	vecDP.resize(iCity + 1);
	for (auto& iter : vecDP)
		iter.resize(iTotalRoute, iMax);

	cout << Check_Route(1, 1);

	return 0;
}

int Check_Route(long long iNext, long long iVisited)
{
	if (vecDP[iNext][iVisited] < iMax)
		return vecDP[iNext][iVisited];

	if (iVisited + 1 == iTotalRoute)
	{
		if (vecCost[iNext][1] > 0)
			vecDP[iNext][iVisited] = vecCost[iNext][1];
		else
			vecDP[iNext][iVisited] = -1;

		return vecDP[iNext][iVisited];
	}

	bool bIsOk = false;

	for (long long i = 1; i <= iCity; ++i)
	{
		long long iNextVisit = (iVisited | (1 << (i- 1)));
		if (iNextVisit == iVisited)
			continue;

		if (vecCost[iNext][i] == 0)
			continue;

		long long llNextCost = Check_Route(i, iNextVisit);
		if (llNextCost == -1)
			continue;

		bIsOk = true;

		vecDP[iNext][iVisited] = min(vecDP[iNext][iVisited], llNextCost + vecCost[iNext][i]);
	}

	if (bIsOk == false)
		vecDP[iNext][iVisited] = -1;

	return vecDP[iNext][iVisited];
}

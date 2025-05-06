#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iHouse = 0;
	long long iPoint = 0;

	cin >> iHouse >> iPoint;

	vector<long long> vecHouse;
	vecHouse.resize(iHouse);

	for (long long i = 0; i < iHouse; ++i)
		cin >> vecHouse[i];

	sort(vecHouse.begin(), vecHouse.end());

	long long iDiff = 0;
	long long iDiffMin = 0;
	long long iDiffMax = vecHouse[iHouse - 1] - vecHouse[0];

	long long iAnswer = 0;

	while (iDiffMax >= iDiffMin)
	{
		iDiff = ((iDiffMax - iDiffMin) / 2) + iDiffMin;

		long long iCount = 1;
		long long iNowValue = vecHouse[0] + iDiff;

		while (iCount <= iPoint)
		{
			long long iIndex = lower_bound(vecHouse.begin(), vecHouse.end(), iNowValue) - vecHouse.begin();

			if (iIndex >= vecHouse.size())
				break;

			iNowValue = vecHouse[iIndex] + iDiff;
			++iCount;
		}

		if (iCount < iPoint)
			iDiffMax = iDiff - 1;
		else
		{
			iAnswer = max(iAnswer, iDiff);
			iDiffMin = iDiff + 1;
		}
	}

	cout << iAnswer;

	return 0;
}
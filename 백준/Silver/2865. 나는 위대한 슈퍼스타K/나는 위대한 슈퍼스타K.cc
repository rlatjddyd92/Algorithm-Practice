#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(1);

	int iNum = 0;
	int iType = 0;
	int iMin = 0;

	cin >> iNum >> iType >> iMin;

	vector<float> vecMax;
	vecMax.resize(iNum + 1);

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iType; ++j)
		{
			int iCount = 0;
			float fScore = 0.f;

			cin >> iCount >> fScore;

			if (fScore > vecMax[iCount])
				vecMax[iCount] = fScore;
		}
	}

	float fAnswer = 0.f;
	stable_sort(vecMax.begin(), vecMax.end(), [](float first, float second) {return first > second; });

	for (int i = 0; i < iMin; ++i)
		fAnswer += vecMax[i];

	fAnswer *= 10.f;
	fAnswer = round(fAnswer);
	fAnswer /= 10.f;
	
	cout << fAnswer;

	return 0;
}
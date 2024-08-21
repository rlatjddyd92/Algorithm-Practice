#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct GEM
{
	int iValue;
	int iWeight;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iGem = 0;
	int iBag = 0;

	cin >> iGem >> iBag;

	vector<GEM> vecGem;
	vecGem.resize(iGem);

	for (int i = 0; i < iGem; ++i)
		cin >> vecGem[i].iWeight >> vecGem[i].iValue;

	vector<int> vecBag;
	vecBag.resize(iBag);

	for (int i = 0; i < iBag; ++i)
		cin >> vecBag[i];
		
	stable_sort(vecGem.begin(), vecGem.end(), [](GEM first, GEM second) {return first.iWeight < second.iWeight; });
	stable_sort(vecBag.begin(), vecBag.end(), [](int first, int second) {return first < second; });

	long long iAnswer = 0;
	int iIndex = 0;

	priority_queue<int> queueValue;

	for (int i = 0; i < iGem; ++i)
	{
		while (vecBag[iIndex] < vecGem[i].iWeight)
		{
			if (!queueValue.empty())
			{
				iAnswer += queueValue.top();
				queueValue.pop();
			}
			++iIndex;
			if (iIndex >= iBag)
				break;
		}

		if (iIndex < iBag)
			queueValue.push(vecGem[i].iValue);
		else
			break;
	}

	while (queueValue.empty() + (iIndex >= iBag) == 0)
	{
		iAnswer += queueValue.top();
		queueValue.pop();
		++iIndex;
	}


	cout << iAnswer;

	vecGem.clear();

	return 0;
}
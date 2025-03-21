#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCrane = 0;
	int iBox = 0;

	vector<int> vecCrane;

	cin >> iCrane;

	vecCrane.resize(iCrane);

	for (int i = 0; i < iCrane; ++i)
		cin >> vecCrane[i];

	sort(vecCrane.begin(), vecCrane.end(), less<int>());
	priority_queue<int, vector<int>, less<int>> queueBox;

	cin >> iBox;

	for (int i = 0; i < iBox; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		queueBox.push(iInput);
	}

	int iCount = 1;
	int iBefore = queueBox.size();
	vector<int> vecVisit;
	vecVisit.resize(iCrane);

	if (vecCrane.back() >= queueBox.top())
	while (queueBox.empty() == false)
	{
		int iNow = queueBox.top();
		int iIndex = lower_bound(vecCrane.begin(), vecCrane.end(), iNow) - vecCrane.begin();
		int iTemp = iIndex;
		while ((iTemp < iCrane) && (vecVisit[iTemp] == iCount))
			++iTemp;

		if (iTemp >= iCrane)
		{
			++iCount;
			iTemp = iIndex;
		}
		else
			iIndex = iTemp;
		iIndex = min(iIndex, iCrane - 1);
		vecVisit[iIndex] += 1;
		queueBox.pop();
	}

	if (queueBox.empty() == false)
		cout << -1;
	else
		cout << iCount;

	vecCrane.clear();
	vecVisit.clear();

	return 0;
}
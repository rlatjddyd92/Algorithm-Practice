#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct STATION
{
	int iPosition;
	int iFuel;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	cin >> iNum;

	vector<STATION> vecStation;
	vecStation.resize(iNum);

	for (int i = 0; i < iNum; ++i)
		cin >> vecStation[i].iPosition >> vecStation[i].iFuel;

	int iEnd = 0;
	int iNow = 0;
	int iAnswer = 0;

	cin >> iEnd >> iNow;

	stable_sort(vecStation.begin(), vecStation.end(), [](STATION first, STATION second) {return first.iPosition < second.iPosition; });
	priority_queue<int> queueFuel;

	for (int i = 0; i < iNum; ++i)
	{
		while ((!queueFuel.empty()) && (vecStation[i].iPosition > iNow))
		{
			iNow += queueFuel.top();
			queueFuel.pop();
			++iAnswer;
		}

		if (vecStation[i].iPosition <= iNow)
			queueFuel.push(vecStation[i].iFuel);
		else
			break;
	}

	while ((!queueFuel.empty()) && (iNow < iEnd))
	{
		iNow += queueFuel.top();
		queueFuel.pop();
		++iAnswer;
	}

	if (iNow < iEnd)
		cout << -1;
	else
		cout << iAnswer;

	vecStation.clear();

	return 0;
}
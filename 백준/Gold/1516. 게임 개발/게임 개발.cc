#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct HOUSE
{
	long long iBefore = 0;
	long long iTime = 0;
	long long iAnswer = 0;
	list<long long> Nextlist;
};

long long iCountHouuse = 0;

vector<HOUSE> vecHouse;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iCountHouuse;

	vecHouse.resize(iCountHouuse + 1);

	for (long long i = 1; i <= iCountHouuse; ++i)
	{
		cin >> vecHouse[i].iTime;
		vecHouse[i].iAnswer = vecHouse[i].iTime;

		while (1)
		{
			long long iInput = 0;
			cin >> iInput;
			if (iInput > 0)
			{
				vecHouse[iInput].Nextlist.push_back(i);
				++vecHouse[i].iBefore;
			}
			else
				break;
		}
	}

	queue<long long> queueNext;

	for (long long i = 1; i <= iCountHouuse; ++i)
		if (vecHouse[i].iBefore == 0)
			queueNext.push(i);

	while (queueNext.empty() == false)
	{
		long long Now = queueNext.front();
		queueNext.pop();

		for (auto& iter : vecHouse[Now].Nextlist)
		{
			--vecHouse[iter].iBefore;
			if (vecHouse[Now].iAnswer + vecHouse[iter].iTime > vecHouse[iter].iAnswer)
				vecHouse[iter].iAnswer = vecHouse[Now].iAnswer + vecHouse[iter].iTime;
			if (vecHouse[iter].iBefore == 0)
				queueNext.push(iter);
		}
	}

	for (long long i = 1; i <= iCountHouuse; ++i)
		cout << vecHouse[i].iAnswer << "\n";

	for (auto& iter : vecHouse)
		iter.Nextlist.clear();

	vecHouse.clear();

	return 0;
}
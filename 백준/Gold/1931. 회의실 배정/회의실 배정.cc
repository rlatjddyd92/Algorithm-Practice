#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TIME
{
	int iStart = 0;
	int iEnd = 0;
};

vector<TIME> vecTime;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iClass = 0;

	cin >> iClass;

	vecTime.resize(iClass);

	for (int i = 0; i < iClass; ++i)
	{
		cin >> vecTime[i].iStart >> vecTime[i].iEnd;
	}

	stable_sort(vecTime.begin(), vecTime.end(), [](TIME First, TIME Second)
		{
			if (First.iStart < Second.iStart)
				return true;
			else if ((First.iStart == Second.iStart) && (First.iEnd < Second.iEnd))
				return true;

			return false;
		});

	stack<TIME> stackReserveClass;
	stackReserveClass.push({ -1, -1 });

	for (auto& iter : vecTime)
	{
		int iStart = iter.iStart;
		int iEnd = iter.iEnd;

		if (iStart >= stackReserveClass.top().iEnd)
			stackReserveClass.push({ iStart ,iEnd });
		else if ((iStart >= stackReserveClass.top().iStart) && (iEnd <= stackReserveClass.top().iEnd))
		{
			stackReserveClass.top().iStart = iStart;
			stackReserveClass.top().iEnd = iEnd;
		}
	}

	cout << stackReserveClass.size() - 1;

	while (stackReserveClass.empty() == false)
		stackReserveClass.pop();

	vecTime.clear();

	return 0;
}
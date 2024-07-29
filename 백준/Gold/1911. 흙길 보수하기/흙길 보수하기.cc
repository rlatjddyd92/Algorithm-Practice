#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iWater = 0;
	int iLength = 0;
	int iAnswer = 0;

	cin >> iWater >> iLength;

	priority_queue<int, vector<int>, greater<int>> queueInput;

	for (int i = 0; i < iWater; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		queueInput.push(iInput);
		cin >> iInput;
		queueInput.push(iInput - 1);
	}

	int iStart = 0;
	int iEnd = 0;

	while (!queueInput.empty())
	{
		iStart = max(iEnd + 1, queueInput.top());
		queueInput.pop();
		iEnd = queueInput.top();

		if (iEnd < iStart)
		{
			iEnd = iStart - 1;
			queueInput.pop();
			continue;
		}

		iEnd = (iStart-1) + ((iEnd - iStart + 1) / iLength) * iLength;
		if (iEnd < queueInput.top())
			iEnd += iLength;

		iAnswer += (iEnd - iStart + 1) / iLength;

		queueInput.pop();
	}

	cout << iAnswer;

	return 0;
}
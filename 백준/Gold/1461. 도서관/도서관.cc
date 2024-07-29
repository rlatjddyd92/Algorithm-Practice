#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iCapacity = 0;
	int iAnswer = 0;

	cin >> iNum >> iCapacity;

	priority_queue<int, vector<int>, greater<int>> queueMinus;
	priority_queue<int, vector<int>, less<int>> queuePlus;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		if (iInput < 0)
			queueMinus.push(iInput);
		else 
			queuePlus.push(iInput);
	}

	int iCountMinus = iCapacity;
	int iCountPlus = iCapacity;

	while ((!queueMinus.empty()) || (!queuePlus.empty()))
	{
		if (iAnswer == 0)
		{
			if (queueMinus.empty())
				iAnswer += queuePlus.top();
			else if (queuePlus.empty())
				iAnswer -= queueMinus.top();
			else
			{
				iAnswer += max(-queueMinus.top(), queuePlus.top());
				iAnswer += 2 * min(-queueMinus.top(), queuePlus.top());
			}
		}
		else
		{
			if ((!queueMinus.empty()) && (iCountMinus == iCapacity))
				iAnswer -= 2 * queueMinus.top();
			if ((!queuePlus.empty()) && (iCountPlus == iCapacity))
				iAnswer += 2 * queuePlus.top();
		}

		--iCountMinus;
		--iCountPlus;
		if (iCountMinus == 0)
			iCountMinus = iCapacity;
		if (iCountPlus == 0)
			iCountPlus = iCapacity;

		if (!queueMinus.empty())
			queueMinus.pop();

		if (!queuePlus.empty())
			queuePlus.pop();
	}

	cout << iAnswer;

	return 0;
}
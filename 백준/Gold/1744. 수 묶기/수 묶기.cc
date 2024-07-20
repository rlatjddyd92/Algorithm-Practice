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
	int iAnswer = 0;
	int iZero = 0;
	int iOne = 0;
	cin >> iNum;

	priority_queue<int> queuePlus;
	priority_queue<int> queueMinus;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		if (iInput > 1)
			queuePlus.push(iInput);
		else if (iInput < 0)
			queueMinus.push(-iInput);
		else if (iInput == 0)
			++iZero;
		else
			++iOne;
	}

	while (!queuePlus.empty())
	{
		int iTemp = queuePlus.top();
		queuePlus.pop();

		if (!queuePlus.empty())
		{
			iTemp *= queuePlus.top();
			queuePlus.pop();
		}

		iAnswer += iTemp;
	}

	while (!queueMinus.empty())
	{
		int iTemp = -queueMinus.top();
		queueMinus.pop();

		if (!queueMinus.empty())
		{
			iTemp *= -queueMinus.top();
			queueMinus.pop(); 
		}
		else if (iZero > 0)
			break;

		iAnswer += iTemp;
	}

	iAnswer += iOne;

	cout << iAnswer;

	return 0;
}
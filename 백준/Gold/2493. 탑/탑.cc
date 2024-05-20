#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TOWER
{
	int iFloor;
	int iOrder;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	stack<TOWER> stackTower;
	queue<int> queueAnswer;

	stackTower.push({ 0,0 });

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		while (1)
		{
			if (stackTower.top().iFloor == 0)
			{
				queueAnswer.push(stackTower.top().iOrder);
				stackTower.push({ iInput , i + 1 });
				break;
			}

			if (stackTower.top().iFloor < iInput)
				stackTower.pop();
			else 
			{
				queueAnswer.push(stackTower.top().iOrder);

				if (stackTower.top().iFloor == iInput)
					stackTower.top().iOrder = i + 1;
				else
					stackTower.push({ iInput , i + 1 });

				break;
			}
		}
	}

	while (!queueAnswer.empty())
	{
		cout << queueAnswer.front();

		queueAnswer.pop();

		if (!queueAnswer.empty())
			cout << " ";
	}
		
	return 0;
}
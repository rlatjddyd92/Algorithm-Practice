#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	cin >> iNum;

	priority_queue<int> queueFront;
	priority_queue<int> queueBack;
	queue<int> queueAnswer;

	int iCenter = 0;

	for (int i = 1; i <= iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		if ((!queueFront.empty()) && (queueFront.top() > iInput))
			queueFront.push(iInput);
		else 
			queueBack.push(-iInput);

		while (queueBack.size() > ((i / 2) + 1))
		{
			queueFront.push(-queueBack.top());
			queueBack.pop();
		}
		while (queueBack.size() != ((i / 2) + 1))
		{
			queueBack.push(-queueFront.top());
			queueFront.pop();
		}

		queueAnswer.push(-queueBack.top());
	}

	while (!queueAnswer.empty())
	{
		cout << queueAnswer.front() << "\n";
		queueAnswer.pop();
	}

	return 0;
}
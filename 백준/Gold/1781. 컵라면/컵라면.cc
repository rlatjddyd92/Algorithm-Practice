#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TASK
{
	int iScore;
	int iDeadline;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	vector<TASK> vecTask;
	vecTask.resize(iNum);

	for (int i = 0; i < iNum; ++i)
		cin >> vecTask[i].iDeadline >> vecTask[i].iScore;

	stable_sort(vecTask.begin(), vecTask.end(), [](TASK first, TASK second)
		{
			return first.iScore > second.iScore;
		});

	stable_sort(vecTask.begin(), vecTask.end(), [](TASK first, TASK second)
		{
			return first.iDeadline < second.iDeadline;
		});

	priority_queue<int> queueScore;

	for (int i = 0; i < iNum; ++i)
	{
		while ((queueScore.size() >= vecTask[i].iDeadline) && (-queueScore.top() < vecTask[i].iScore))
			queueScore.pop();

		if (queueScore.size() < vecTask[i].iDeadline)
			queueScore.push(-vecTask[i].iScore);
	}

	int iAnswer = 0;

	while (!queueScore.empty())
	{
		iAnswer -= queueScore.top();
		queueScore.pop();
	}

	cout << iAnswer;
		
	vecTask.clear();

	return 0;
}

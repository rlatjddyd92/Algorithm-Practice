#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTask = 0;
	int iToday = 0;

	cin >> iTask;

	priority_queue<int> queueTask; // 점수 (내림)
	vector<queue<int>> vecDays; // 일자 별 마감 과제 
	vecDays.resize(1001);
	
	for (int i = 0; i < iTask; ++i)
	{
		pair<int,int> New = { 0,0 };
		cin >> New.first >> New.second;
		vecDays[New.first].push(New.second);
		iToday = max(iToday, New.first);
	}

	int iAnswer = 0;

	for (int i = iToday; i > 0; --i)
	{
		while (vecDays[i].empty() == false)
		{
			queueTask.push(vecDays[i].front());
			vecDays[i].pop();
		}

		if (queueTask.empty() == false)
		{
			iAnswer += queueTask.top();
			queueTask.pop();
		}
	}

	cout << iAnswer;

	return 0;
}
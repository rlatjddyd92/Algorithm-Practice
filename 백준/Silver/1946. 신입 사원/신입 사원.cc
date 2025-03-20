#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iPeople = 0;
		int iAnswer = 0;

		cin >> iPeople;

		priority_queue<pair<int, int>> queueInput;
		priority_queue<pair<int, int>> queueSecond;

		for (int j = 0; j < iPeople; ++j)
		{
			pair<int, int> New = { 0,0 };

			cin >> New.first >> New.second;

			queueInput.push(New);
		}

		while (queueInput.empty() == false)
		{
			pair<int, int> Now = queueInput.top();
			queueInput.pop();
			
			while ((queueSecond.empty() == false) && (queueSecond.top().first > Now.second))
				queueSecond.pop();

			queueSecond.push({ Now.second , Now.first });
		}

		cout << queueSecond.size() << "\n";
	}



	return 0;
}
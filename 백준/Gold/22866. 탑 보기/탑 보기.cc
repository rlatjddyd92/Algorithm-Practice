#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vecSize;
vector<pair<int, int>> vecAnswer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;

	cin >> iNumber;

	vecSize.resize(iNumber + 1);
	vecAnswer.resize(iNumber + 1, {10000000, 0});

	for (int i = 1; i <= iNumber; ++i)
		cin >> vecSize[i];

	stack<pair<int,int>> stackStragit;
	stackStragit.push({ 10000000, -1000000 });

	for (int i = 1; i <= iNumber; ++i)
	{
		while (stackStragit.top().first <= vecSize[i])
			stackStragit.pop();

		vecAnswer[i].first = stackStragit.top().second;
		vecAnswer[i].second += stackStragit.size() - 1;
		
		stackStragit.push({ vecSize[i], i });
	}

	stack<pair<int, int>> stackBackward;
	stackBackward.push({ 10000000,-1000000 });

	for (int i = iNumber; i >= 0; --i)
	{
		while (stackBackward.top().first <= vecSize[i])
			stackBackward.pop();

		int iIndex = stackBackward.top().second;

		if (abs(vecAnswer[i].first - i) > abs(iIndex - i))
			vecAnswer[i].first = iIndex;
		vecAnswer[i].second += stackBackward.size() - 1;

		stackBackward.push({ vecSize[i], i });
	}

	for (int i = 1; i <= iNumber; ++i)
	{
		if (vecAnswer[i].second <= 0)
			cout << 0;
		else
			cout << vecAnswer[i].second << " " << vecAnswer[i].first;

		cout << "\n";
	}

	vecSize.clear();
	vecAnswer.clear();

	return 0;
}
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct UNIT
{
	int iNow;
	int iSecond;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStart = 0;
	int iEnd = 0;

	cin >> iStart >> iEnd;

	if (iStart == iEnd)
	{
		cout << 0 << "\n" << iEnd;
		return 0;
	}

	queue<UNIT> queueNext;
	vector<bool> vecVisit;
	vecVisit.resize(max(iStart, iEnd) * 2);

	queueNext.push({ iStart, 0 });
	map<int, int> mapRoute;

	while (!queueNext.empty())
	{
		int iNow = queueNext.front().iNow;
		int iNowSecond = queueNext.front().iSecond;
		vecVisit[iNow] = true;

		if (iNow == iEnd)
			break;

		queueNext.pop();

		if ((iNow - 1 > -1) && (!vecVisit[iNow - 1]))
		{
			queueNext.push({ iNow - 1 ,iNowSecond + 1 });
			mapRoute.insert({ iNow - 1 , iNow });
		}

		if ((iNow + 1 <= iEnd * 2) && (!vecVisit[iNow + 1]))
		{
			queueNext.push({ iNow + 1 ,iNowSecond + 1 });
			mapRoute.insert({ iNow + 1 , iNow });
		}

		if ((iNow * 2 <= iEnd * 2) && (!vecVisit[iNow * 2]))
		{
			queueNext.push({ iNow * 2 ,iNowSecond + 1 });
			mapRoute.insert({ iNow * 2 , iNow });
		}
	}

	int iAnswer = queueNext.front().iSecond;

	cout << iAnswer << "\n";

	stack<int> stackAnswer;
	stackAnswer.push(iEnd);

	while (stackAnswer.size() - 1 < iAnswer)
	{
		iEnd = mapRoute.find(iEnd)->second;
		stackAnswer.push(iEnd);
	}

	while (!stackAnswer.empty())
	{
		cout << stackAnswer.top();
		stackAnswer.pop();

		if (!stackAnswer.empty())
			cout << " ";
	}

	vecVisit.clear();
	mapRoute.clear();

	while (!queueNext.empty())
		queueNext.pop();

	return 0;
}
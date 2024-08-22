#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	int iIndex;
	int iMin;
	int iMax;
	int iAnswer = -1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iQuery = 0;

	cin >> iNum >> iQuery;

	vector<int> vecInput;
	vecInput.resize(iNum + 1);

	for (int i = 1; i <= iNum; ++i)
		cin >> vecInput[i];

	vector<NODE> vecNode;
	vecNode.resize(iNum * 4);

	queue<NODE> queueDown;
	queue<NODE> queueUp;

	queueDown.push({ 1,1,iNum ,-1 });

	while (!queueDown.empty())
	{
		NODE tNow = queueDown.front();
		queueDown.pop();
		vecNode[tNow.iIndex] = tNow;

		if (tNow.iMin == tNow.iMax)
		{
			vecNode[tNow.iIndex].iAnswer = vecInput[tNow.iMin];
			queueUp.push({ vecNode[tNow.iIndex] });
			continue;
		}

		int iNext = tNow.iIndex * 2;
		int iGap = (tNow.iMax - tNow.iMin) / 2;

		queueDown.push({ iNext, tNow.iMin,tNow.iMin + iGap, -1 });
		queueDown.push({ iNext + 1, tNow.iMin + iGap + 1,tNow.iMax, -1 });
	}

	while (!queueUp.empty())
	{
		NODE tNow = queueUp.front();
		queueUp.pop();

		if ((vecNode[tNow.iIndex].iAnswer != -1) && (vecNode[tNow.iIndex].iAnswer < tNow.iAnswer))
			continue;

		if ((vecNode[tNow.iIndex / 2].iAnswer == -1) || (vecNode[tNow.iIndex / 2].iAnswer > tNow.iAnswer))
		{
			vecNode[tNow.iIndex / 2].iAnswer = tNow.iAnswer;
			tNow.iIndex /= 2;
			queueUp.push(tNow);
		}
	}

	for (int i = 0; i < iQuery; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iAnswer = -1;

		cin >> iStart >> iEnd;

		queue<int> queueSerach;
		queueSerach.push(1);

		while (!queueSerach.empty())
		{
			NODE tNow = vecNode[queueSerach.front()];
			queueSerach.pop();

			if ((tNow.iMin >= iStart) && (tNow.iMax <= iEnd))
			{
				if ((iAnswer == -1) || (iAnswer > tNow.iAnswer))
					iAnswer = tNow.iAnswer;
			}
			else if ((tNow.iMin > iEnd) || (tNow.iMax < iStart))
			{
				continue;
			}
			else
			{
				queueSerach.push(tNow.iIndex * 2);
				queueSerach.push((tNow.iIndex * 2) + 1);
			}
		}

		cout << iAnswer << "\n";
	}

	vecInput.clear();
	vecNode.clear();

	return 0;
}
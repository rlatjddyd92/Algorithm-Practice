#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ROUTE
{
	int iNode[2] = { 0, };
	int iLength = 0;
};

vector<ROUTE> vecRoute;
vector<int> vecGroup;

int FindHead(int iNode);
void MergeGroup(int iFirst, int iSecond);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNode = 0;
	int iRoute = 0;
	int iAnswer = 0;

	cin >> iNode;
	cin >> iRoute;

	vecRoute.resize(iRoute);
	vecGroup.resize(iNode + 1);

	for (int i = 1; i <= iNode; ++i)
		vecGroup[i] = i;

	for (int i = 0; i < iRoute; ++i)
	{
		int iNode[2] = { 0, };
		int iLength = 0;
		cin >> iNode[0] >> iNode[1] >> iLength;

		vecRoute[i] = { iNode[0] ,iNode[1], iLength };
	}

	sort(vecRoute.begin(), vecRoute.end(), [](ROUTE First, ROUTE Second) {return First.iLength < Second.iLength; });

	for (auto& iter : vecRoute)
	{
		int iFirst = iter.iNode[0];
		int iSecond = iter.iNode[1];
		
		if (FindHead(iFirst) != FindHead(iSecond))
		{
			MergeGroup(iFirst, iSecond);
			iAnswer += iter.iLength;
			--iNode;
		}

		if (iNode <= 1)
			break;
	}

	cout << iAnswer;

	vecRoute.clear();
	vecGroup.clear();

	return 0;
}

int FindHead(int iNode)
{
	int iHead = vecGroup[iNode];
	int iNow = iNode;

	queue<int> queuePath;

	while (iHead != iNow)
	{
		queuePath.push(iNow);
		iNow = iHead;
		iHead = vecGroup[iNow];
	}

	while (queuePath.empty() == false)
	{
		vecGroup[queuePath.front()] = iHead;
		queuePath.pop();
	}

	return iHead;
}

void MergeGroup(int iFirst, int iSecond)
{
	int iHeadFirst = FindHead(iFirst);
	int iHeadSecond = FindHead(iSecond);

	vecGroup[max(iHeadFirst, iHeadSecond)] = vecGroup[min(iHeadFirst, iHeadSecond)];
	vecGroup[iFirst] = vecGroup[min(iHeadFirst, iHeadSecond)];
	vecGroup[iSecond] = vecGroup[min(iHeadFirst, iHeadSecond)];
}

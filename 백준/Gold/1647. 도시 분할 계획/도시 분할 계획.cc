#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ROUTE
{
	int iNode[2] = { 0, };
	int iCost = 0;
};

int FindHead(int iNode);
void MergeGroup(int iFirst, int iSecond);

vector<ROUTE> vecRoute;
vector<int> vecGroup;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iHouse = 0;
	int iRoute = 0;
	int iAnswer = 0;

	cin >> iHouse >> iRoute;

	vecRoute.resize(iRoute);
	vecGroup.resize(iHouse + 1);

	for (int i = 1; i <= iHouse; ++i)
		vecGroup[i] = i;

	for (int i = 0; i < iRoute; ++i)
	{
		int iNode[2] = { 0, };
		int iCost = 0;

		cin >> iNode[0] >> iNode[1] >> iCost;

		vecRoute[i] = { iNode[0], iNode[1],iCost };
	}

	stable_sort(vecRoute.begin(), vecRoute.end(), [](ROUTE First, ROUTE Second) {return First.iCost < Second.iCost; });

	for (auto& iter : vecRoute)
	{
		if (FindHead(iter.iNode[0]) != FindHead(iter.iNode[1]))
		{
			MergeGroup(iter.iNode[0], iter.iNode[1]);
			--iHouse;

			if (iHouse > 1)
				iAnswer += iter.iCost;
			else
				break;
		}
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

	if (iNow != iHead)
		vecGroup[iNode] = FindHead(iHead);

	return vecGroup[iNode];
}

void MergeGroup(int iFirst, int iSecond)
{
	int iFirstHead = FindHead(iFirst);
	int iSecondHead = FindHead(iSecond);

	vecGroup[iFirstHead] = min(iFirstHead, iSecondHead);
	vecGroup[iSecondHead] = min(iFirstHead, iSecondHead);
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iIsland = 0;
int iBridge = 0;

struct ROUTE
{
	int iStart = 0;
	int iEnd = 0;
	int iLimit = 0;
};

vector<ROUTE> vecRoute;
vector<int> vecHead;

int Find_Head(int iNode)
{
	if (vecHead[iNode] != iNode)
		vecHead[iNode] = Find_Head(vecHead[iNode]);

	return vecHead[iNode];
}

void Merge_Head(int iFirst, int iSecond)
{
	int iNewHead = min(Find_Head(iFirst), Find_Head(iSecond));
	vecHead[Find_Head(iFirst)] = iNewHead;
	vecHead[Find_Head(iSecond)] = iNewHead;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iIsland >> iBridge;

	vecHead.resize(iIsland + 1);

	for (int i = 0; i <= iIsland; ++i)
		vecHead[i] = i;

	for (int i = 0; i < iBridge; ++i)
	{
		ROUTE New{};
		cin >> New.iStart >> New.iEnd >> New.iLimit;
		vecRoute.push_back(New);
	}

	sort(vecRoute.begin(), vecRoute.end(), [](ROUTE Left, ROUTE Right)
		{
			if (Left.iLimit > Right.iLimit)
				return true;
			else if (Left.iLimit < Right.iLimit)
				return false;

			return false;
		});

	int iStart = 0;
	int iEnd = 0;

	cin >> iStart >> iEnd;

	for (auto& iter : vecRoute)
	{
		Merge_Head(iter.iStart, iter.iEnd);
		if (Find_Head(iStart) == Find_Head(iEnd))
		{
			cout << iter.iLimit;
			break;
		}
	}

	return 0;
}
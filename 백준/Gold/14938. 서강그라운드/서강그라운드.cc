#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct ROUTE
{
	int iNext;
	int iCost;
};

struct NODE
{
	int iItem;
	list<ROUTE> Nextlist;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNode = 0;
	int iMax = 0;
	int iRoute = 0;
	int iAnswer = 0;

	cin >> iNode >> iMax >> iRoute;

	vector<NODE> vecNode;
	vecNode.resize(iNode + 1);

	for (int i = 1; i <= iNode; ++i)
		cin >> vecNode[i].iItem;

	for (int i = 0; i < iRoute; ++i)
	{
		int iNode[2] = { 0,0 };
		int iCost = 0;

		cin >> iNode[0] >> iNode[1] >> iCost;
		vecNode[iNode[0]].Nextlist.push_back({ iNode[1], iCost });
		vecNode[iNode[1]].Nextlist.push_back({ iNode[0], iCost });
	}

	for (int i = 1; i <= iNode; ++i)
	{
		int iTempAnswer = vecNode[i].iItem;

		vector<int> vecSum;
		vecSum.resize(iNode + 1);

		queue<int> queueNext;
		queueNext.push(i);

		while (!queueNext.empty())
		{
			int iNow = queueNext.front();
			queueNext.pop();

			for (auto& iter : vecNode[iNow].Nextlist)
			{
				if (iter.iNext == i)
					continue;

				if (vecSum[iNow] + iter.iCost <= iMax)
					if ((vecSum[iter.iNext] == 0) || (vecSum[iter.iNext] > vecSum[iNow] + iter.iCost))
					{
						queueNext.push(iter.iNext);

						if (vecSum[iter.iNext] == 0)
							iTempAnswer += vecNode[iter.iNext].iItem;

						vecSum[iter.iNext] = vecSum[iNow] + iter.iCost;
					}
			}
		}

		if (iAnswer < iTempAnswer)
			iAnswer = iTempAnswer;

		vecSum.clear();
	}

	cout << iAnswer;

	for (auto& iter : vecNode)
		iter.Nextlist.clear();

	vecNode.clear();

	return 0;
}
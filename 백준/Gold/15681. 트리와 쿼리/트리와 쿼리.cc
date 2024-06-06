#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct NODE
{
	int iCount;
	map<int, int> mapRoute;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNode = 0;
	int iRoot = 0;
	int iQuery = 0;

	cin >> iNode >> iRoot >> iQuery;

	vector<NODE> vecNode;
	vecNode.resize(iNode + 1);

	for (int i = 0; i < iNode - 1; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		vecNode[iStart].mapRoute.insert({iEnd, iEnd});
		vecNode[iStart].iCount = 1;
		vecNode[iEnd].mapRoute.insert({ iStart, iStart });
		vecNode[iEnd].iCount = 1;
	}

	queue<int> queueNext;

	for (int i = 0; i <= iNode; ++i)
	{
		vecNode[i].iCount = 1;

		if ((vecNode[i].mapRoute.size() == 1) && (i != iRoot))
			queueNext.push(i);
	}

	while (!queueNext.empty())
	{
		int iNow = queueNext.front();
		queueNext.pop();

		for (auto& iter : vecNode[iNow].mapRoute)
		{
			vecNode[iter.first].iCount += vecNode[iNow].iCount;
			vecNode[iter.first].mapRoute.erase((vecNode[iter.first].mapRoute.find(iNow)));
			
			if ((vecNode[iter.first].mapRoute.size() == 1) && (iter.first != iRoot))
				queueNext.push(iter.first);
		}
	}

	for (int i = 0; i < iQuery; ++i)
	{
		int iNum = 0;
		cin >> iNum;

		cout << vecNode[iNum].iCount << "\n";
	}

	for (auto& iter : vecNode)
		iter.mapRoute.clear();

	vecNode.clear();

	return 0;
}
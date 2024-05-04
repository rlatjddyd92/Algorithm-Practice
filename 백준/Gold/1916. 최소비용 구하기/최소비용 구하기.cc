#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct RouteInfo
{
	int iDest;
	int iCost;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCity = 0;
	int iRoute = 0;

	cin >> iCity;
	cin >> iRoute;

	vector<int> vecCost; // <- 해당 노드까지 가는 최소비용 기록
	vector<map<int,int>> vecNextNode; // <- 해당 노드에 연결된 다른 노드와 거기 가는 비용 기록

	for (int i = 0; i <= iCity; ++i)
		vecCost.push_back(-1);

	vecNextNode.resize(iCity + 1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iCost = 0;

		cin >> iStart >> iEnd >> iCost;

		if (vecNextNode[iStart].find(iEnd) != vecNextNode[iStart].end())
		{
			if (vecNextNode[iStart].find(iEnd)->second > iCost)
				vecNextNode[iStart].find(iEnd)->second = iCost;
		}
		else
			vecNextNode[iStart].insert({ iEnd , iCost });
	}

	int iBegin = 0;
	int iDestination = 0;

	cin >> iBegin >> iDestination;

	queue<int> queueNextNode;
	queueNextNode.push(iBegin);

	while (!queueNextNode.empty())
	{
		int iNowNode = queueNextNode.front();
		int iSum = 0;
		if (vecCost[iNowNode] != -1)
			iSum = vecCost[iNowNode];

		queueNextNode.pop();

		for (auto& iter : vecNextNode[iNowNode])
		{
			if ((vecCost[iter.first] == -1) || (vecCost[iter.first] > iSum + iter.second))
			{
				vecCost[iter.first] = iSum + iter.second;

				if (iter.first != iDestination)
					queueNextNode.push(iter.first);
			}
		}
	}

	cout << vecCost[iDestination];

	vecCost.clear();


	for (auto& iter : vecNextNode)
	{
		iter.clear();
	}

	vecNextNode.clear();

	return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	priority_queue<pair<int, int>> queueBuffer; // 목적지, 비용
	list<pair<int, int>> Routelist; // 목적지, 비용 
	int iCost = -1;
};

priority_queue<pair<int, int>> queueRoute; // 비용, 목적지 
vector<NODE> vecNode; 

void FindRoute();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNode = 0;
	int iRoute = 0;
	int iStart = 0;

	cin >> iNode >> iRoute;
	cin >> iStart;
	
	vecNode.resize(iNode + 1);

	for (int i = 0; i < iRoute ; ++i)
	{
		int iStart = 0;
		pair<int, int> Route;

		cin >> iStart >> Route.first >> Route.second;

		Route.second *= -1;

		vecNode[iStart].queueBuffer.push(Route);
	}

	for (int i = 1; i <= iNode; ++i)
	{
		while (vecNode[i].queueBuffer.empty() == false)
		{
			pair<int, int> Route = vecNode[i].queueBuffer.top();
			vecNode[i].queueBuffer.pop();
			if ((vecNode[i].Routelist.empty() == true) || (vecNode[i].Routelist.back().first != Route.first))
				vecNode[i].Routelist.push_back(Route);
		}
	}

	vecNode[iStart].iCost = 0;
	queueRoute.push({ 0,iStart });
	FindRoute();

	for (int i = 1; i <= iNode; ++i)
	{
		if (vecNode[i].iCost == -1)
			cout << "INF" << "\n";
		else 
			cout << vecNode[i].iCost << "\n";
	}

	vecNode.clear();

	return 0;
}

void FindRoute()
{
	while (queueRoute.empty() == false)
	{
		pair<int, int> Next = queueRoute.top();
		int iStart = Next.second;
		queueRoute.pop();

		for (auto& iter : vecNode[iStart].Routelist)
		{
			if ((vecNode[iter.first].iCost == -1) || (vecNode[iStart].iCost - iter.second < vecNode[iter.first].iCost))
			{
				vecNode[iter.first].iCost = vecNode[iStart].iCost - iter.second;
				queueRoute.push({ iter.second, iter.first }); // 비용, 목적지 
			}
		}
	} 
}

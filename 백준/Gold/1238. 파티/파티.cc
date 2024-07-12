#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct PEOPLE
{
	int iHouse;
	int iSum;
};

struct ROUTE
{
	int iDest;
	int iCost;
};

struct MAXCOST
{
	int iToParty;
	int iToHouse;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iPeople = 0;
	int iRoute = 0;
	int iDest = 0;

	cin >> iPeople >> iRoute >> iDest;

	vector<list<ROUTE>> vecRouteToParty;
	vector<list<ROUTE>> vecRouteToHouse;

	vector<MAXCOST> vecMaxCost;

	vecRouteToParty.resize(iPeople + 1);
	vecRouteToHouse.resize(iPeople + 1);
	vecMaxCost.resize(iPeople + 1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iCost = 0;

		cin >> iStart >> iEnd >> iCost;

		vecRouteToParty[iEnd].push_back({ iStart ,iCost });
		vecRouteToHouse[iStart].push_back({ iEnd ,iCost });
	}

	queue<PEOPLE> queueToParty;
	queueToParty.push({ iDest , 0 });

	while (!queueToParty.empty())
	{
		int iNowPoint = queueToParty.front().iHouse;
		int iSumCost = queueToParty.front().iSum;

		queueToParty.pop();

		for (auto& iter : vecRouteToParty[iNowPoint])
		{
			if ((vecMaxCost[iter.iDest].iToParty == 0) || (vecMaxCost[iter.iDest].iToParty > iSumCost + iter.iCost))
			{
				vecMaxCost[iter.iDest].iToParty = iSumCost + iter.iCost;
				queueToParty.push({ iter.iDest , iSumCost + iter.iCost });
			}
		}
	}

	queue<PEOPLE> queueToHouse;
	queueToHouse.push({ iDest , 0 });

	while (!queueToHouse.empty())
	{
		int iNowPoint = queueToHouse.front().iHouse;
		int iSumCost = queueToHouse.front().iSum;

		queueToHouse.pop();

		for (auto& iter : vecRouteToHouse[iNowPoint])
		{
			if ((vecMaxCost[iter.iDest].iToHouse == 0) || (vecMaxCost[iter.iDest].iToHouse > iSumCost + iter.iCost))
			{
				vecMaxCost[iter.iDest].iToHouse = iSumCost + iter.iCost;
				queueToHouse.push({ iter.iDest , iSumCost + iter.iCost });
			}
		}
	}

	int iAnswer = 0;

	vecMaxCost[iDest] = { 0,0 };

	for (auto& iter : vecMaxCost)
		if (iter.iToHouse + iter.iToParty > iAnswer)
			iAnswer = iter.iToHouse + iter.iToParty;

	cout << iAnswer;

	for (int i = 0; i < iPeople + 1; ++i)
	{
		vecRouteToParty[i].clear();
		vecRouteToHouse[i].clear();
	}

	vecRouteToParty.clear();
	vecRouteToHouse.clear();
	vecMaxCost.clear();

	return 0;
}
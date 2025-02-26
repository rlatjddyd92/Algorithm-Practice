#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BFS
{
	pair<int, int> Position;
	bool bCanDestroy = true;
};

struct CELL
{
	CELL() { MinCost.first = MinCost.second = 1000 * 1000;}
	pair<int, int> MinCost;
	bool bIsWall = false;
};

pair<int, int> MapSize;
vector<vector<CELL>> vecMap;
queue<BFS> queueSearch;

void SearchNext(BFS Now);
void CheckCell(BFS Now, int iDirec, pair<int, int> CostNow);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> MapSize.first >> MapSize.second;

	vecMap.resize(MapSize.first);

	for (int i = 0; i < MapSize.first; ++i)
	{
		vecMap[i].resize(MapSize.second);
		string sInput = {};
		cin >> sInput;

		for (int j = 0; j < MapSize.second; ++j)
			vecMap[i][j].bIsWall = sInput[j] - '0';
	}
	BFS New{};

	New.Position = { 0,0 };
	vecMap[0][0].MinCost.first = vecMap[0][0].MinCost.second = 0;
	queueSearch.push(New);

	while (queueSearch.empty() == false)
	{
		SearchNext(queueSearch.front());
		queueSearch.pop();
	}

	int iAnswer = min(vecMap[MapSize.first - 1][MapSize.second - 1].MinCost.first, vecMap[MapSize.first - 1][MapSize.second - 1].MinCost.second);

	if (iAnswer < 1000 * 1000)
		cout << iAnswer + 1;
	else
		cout << -1;

	for (auto& iter : vecMap)
		iter.clear();

	vecMap.clear();

	return 0;
}

void SearchNext(BFS Now)
{
	pair<int, int> CostNow = vecMap[Now.Position.first][Now.Position.second].MinCost;

	for (int i = 0; i < 4; ++i)
		CheckCell(Now, i, CostNow);
}

void CheckCell(BFS Now, int iDirec, pair<int, int> CostNow)
{
	if (iDirec == 0) --Now.Position.first;
	else if (iDirec == 1) --Now.Position.second;
	else if (iDirec == 2) ++Now.Position.first;
	else if (iDirec == 3) ++Now.Position.second;

	if ((Now.Position.first < 0) || (Now.Position.first >= MapSize.first))
		return;

	if ((Now.Position.second < 0) || (Now.Position.second >= MapSize.second))
		return;

	int iBeforeCost = Now.bCanDestroy == true ? CostNow.first : CostNow.second;
	++iBeforeCost;

	if (vecMap[Now.Position.first][Now.Position.second].bIsWall == true)
	{
		if (Now.bCanDestroy == false)
			return;
		else
			Now.bCanDestroy = false;
	}
		
	if (Now.bCanDestroy == false)
	{
		if (iBeforeCost >= vecMap[Now.Position.first][Now.Position.second].MinCost.first)
			return;

		if (iBeforeCost >= vecMap[Now.Position.first][Now.Position.second].MinCost.second)
			return;

		vecMap[Now.Position.first][Now.Position.second].MinCost.second = iBeforeCost;
		queueSearch.push(Now);
	}
	else
	{
		if (iBeforeCost >= vecMap[Now.Position.first][Now.Position.second].MinCost.first)
			return;

		vecMap[Now.Position.first][Now.Position.second].MinCost.first = iBeforeCost;
		queueSearch.push(Now);
	}
}

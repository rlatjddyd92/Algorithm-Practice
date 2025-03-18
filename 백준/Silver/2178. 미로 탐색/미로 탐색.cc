#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int>>> vecMap;
queue<pair<int, int>> queueBFS;

int iRow = 0;
int iCol = 0;
int iMax = 0;

void SearchRoute();
void MakeQueue(int iNextRow, int iNextCol, int iNextCost);




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iRow >> iCol;

	iMax = (iRow * iCol) + 1;

	vecMap.resize(iRow);

	for (int i = 0; i < iRow; ++i)
	{
		vecMap[i].resize(iCol, { 0,iMax });

		string strInput = {};

		cin >> strInput;

		for (int j = 0; j < strInput.size(); ++j)
			vecMap[i][j].first = (strInput[j] - '0');
	}

	SearchRoute();

	cout << vecMap[iRow - 1][iCol - 1].second;

	for(auto & iter : vecMap)
		iter.clear();
	vecMap.clear();

	return 0;
}

void SearchRoute()
{
	queueBFS.push({ 0,0 });

	vecMap[0][0].second = 1;

	while (queueBFS.empty() == false)
	{
		pair<int, int> Now = queueBFS.front();
		queueBFS.pop();

		int iNowCost = vecMap[Now.first][Now.second].second + 1;

		MakeQueue(Now.first - 1, Now.second, iNowCost);
		MakeQueue(Now.first + 1, Now.second, iNowCost);
		MakeQueue(Now.first, Now.second - 1, iNowCost);
		MakeQueue(Now.first, Now.second + 1, iNowCost);
	}
}

void MakeQueue(int iNextRow, int iNextCol, int iNextCost)
{
	if ((iNextRow < 0) || (iNextRow >= iRow))
		return;

	if ((iNextCol < 0) || (iNextCol >= iCol))
		return;

	if (vecMap[iNextRow][iNextCol].first == 0)
		return;

	if (vecMap[iNextRow][iNextCol].second <= iNextCost)
		return;

	vecMap[iNextRow][iNextCol].second = iNextCost;
	queueBFS.push({ iNextRow , iNextCol });
}

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<pair<int, int>>> vecMap; // 대나무 수량, 거기 가면 먹을 수 있는 칸
int DFSSearch(pair<int, int> Now);
pair<int, int> CheckCell(pair<int, int> Now, int iDirec);
int iAnswer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize = 0;

	cin >> iSize;
	
	vecMap.resize(iSize);

	for (int i = 0; i < iSize; ++i)
	{
		vecMap[i].resize(iSize);

		for (int j = 0; j < iSize; ++j)
			cin >> vecMap[i][j].first;
	}

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			if (vecMap[i][j].second == 0)
				DFSSearch({ i,j });

	cout << iAnswer;

	for (auto& iter : vecMap)
		iter.clear();

	vecMap.clear();

	return 0;
}

int DFSSearch(pair<int, int> Now)
{
	pair<int, int> Next{};
	int iMaxBuffer = 0;
	int iMax = 0;
	vecMap[Now.first][Now.second].second = 1;

	for (int i = 0; i < 4; ++i)
	{
		Next = CheckCell(Now, i);
		if ((Next.first < 0) || (Next.second < 0))
			continue;

			if ((Next.first >= vecMap.size()) || (Next.second >= vecMap.size()))
				continue;

		
			if (vecMap[Next.first][Next.second].second > 0)
				iMaxBuffer = vecMap[Next.first][Next.second].second;
			else
				iMaxBuffer = DFSSearch(Next);
			
			if (iMax < iMaxBuffer)
				iMax = iMaxBuffer;
		
	}
	
	vecMap[Now.first][Now.second].second += iMax;

	if (iAnswer < vecMap[Now.first][Now.second].second)
		iAnswer = vecMap[Now.first][Now.second].second;

	return vecMap[Now.first][Now.second].second;
}

pair<int, int> CheckCell(pair<int, int> Now, int iDirec)
{
	int iNowBamboo = vecMap[Now.first][Now.second].first;

	if (iDirec == 0) --Now.first;
	else if (iDirec == 1) --Now.second;
	else if (iDirec == 2) ++Now.first;
	else if (iDirec == 3) ++Now.second;

	if ((Now.first < 0) || (Now.second < 0))
		return { -1,-1 };

	if ((Now.first >= vecMap.size()) || (Now.second >= vecMap.size()))
		return { -1,-1 };

	if (vecMap[Now.first][Now.second].first > iNowBamboo)
		return Now;
	else
		return { -1,-1 };
}

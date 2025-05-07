#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int iRow = 0;
int iCol = 0;
int iVisitCount = 0;

vector<vector<pair<int, int>>> vecMap;
vector<vector<int>> vecVisit;

bool Check_Cell(pair<int, int> NEXT, int iNewNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iRow >> iCol;

	vecMap.resize(iRow);
	for(auto& iter : vecMap)
		iter.resize(iCol);

	vecVisit.resize(iRow);
	for (auto& iter : vecVisit)
		iter.resize(iCol);

	for (int i = 0; i < iRow; ++i)
	{
		string strInput = {};
		cin >> strInput;
		for (int j = 0; j < iCol; ++j)
			vecMap[i][j].first = strInput[j] - '0';
	}

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
		{
			if ((vecMap[i][j].first == 0) && (vecMap[i][j].second == 0))
			{
				++iVisitCount;
				vecMap[i][j].second = 1;
				vecVisit[i][j] = iVisitCount;

				queue<pair<int, int>> queueNext;
				int iCount = 1;

				queueNext.push({ i,j });

				while (queueNext.empty() == false)
				{
					pair<int, int> Now = queueNext.front();
					queueNext.pop();
					int iBeforeCount = queueNext.size();

					if (Check_Cell({ Now.first - 1, Now.second }, 1))
						queueNext.push({ Now.first - 1, Now.second });

					if (Check_Cell({ Now.first, Now.second - 1 }, 1))
						queueNext.push({ Now.first, Now.second - 1 });

					if (Check_Cell({ Now.first + 1, Now.second }, 1))
						queueNext.push({ Now.first + 1, Now.second });

					if (Check_Cell({ Now.first, Now.second + 1 }, 1))
						queueNext.push({ Now.first, Now.second + 1 });

					iCount += queueNext.size() - iBeforeCount;
				}

				queueNext.push({ i,j });

				vecMap[i][j].second = iCount;

				while (queueNext.empty() == false)
				{
					pair<int, int> Now = queueNext.front();
					queueNext.pop();
					
					if (Check_Cell({ Now.first - 1, Now.second }, iCount))
						queueNext.push({ Now.first - 1, Now.second });

					if (Check_Cell({ Now.first, Now.second - 1 }, iCount))
						queueNext.push({ Now.first, Now.second - 1 });

					if (Check_Cell({ Now.first + 1, Now.second }, iCount))
						queueNext.push({ Now.first + 1, Now.second });

					if (Check_Cell({ Now.first, Now.second + 1 }, iCount))
						queueNext.push({ Now.first, Now.second + 1 });
				}
			}
		}

	for (int i = 0; i < iRow; ++i)
	{
		string strAnswer = {};
		for (int j = 0; j < iCol; ++j)
		{
			if (vecMap[i][j].first == 0)
			{
				strAnswer += '0';
				continue;
			}
				
			int iAnswer = 1;

			list<int> Visitlist;

			if (i > 0)
			{
				iAnswer += vecMap[i - 1][j].second;
				Visitlist.push_back(vecVisit[i - 1][j]);
			}

			if (j > 0)
			{
				bool bContinue = false;
				for (auto& iter : Visitlist)
					if (vecVisit[i][j - 1] == iter)
						bContinue = true;

				if (bContinue == false)
				{
					iAnswer += vecMap[i][j - 1].second;
					Visitlist.push_back(vecVisit[i][j - 1]);
				}
			}
				

			if (i < iRow - 1)
			{
				bool bContinue = false;
				for (auto& iter : Visitlist)
					if (vecVisit[i + 1][j] == iter)
						bContinue = true;

				if (bContinue == false)
				{
					iAnswer += vecMap[i + 1][j].second;
					Visitlist.push_back(vecVisit[i + 1][j]);
				}
			}

			if (j < iCol - 1)
			{
				bool bContinue = false;
				for (auto& iter : Visitlist)
					if (vecVisit[i][j + 1] == iter)
						bContinue = true;

				if (bContinue == false)
				{
					iAnswer += vecMap[i][j + 1].second;
					Visitlist.push_back(vecVisit[i][j + 1]);
				}
			}

			iAnswer %= 10;

			strAnswer += (iAnswer + '0');
		}
		cout << strAnswer << "\n";
	}
		
	return 0;
}

bool Check_Cell(pair<int, int> NEXT, int iNewNum)
{
	if ((NEXT.first < 0) || (NEXT.first >= iRow))
		return false;

	if ((NEXT.second < 0) || (NEXT.second >= iCol))
		return false;

	if (vecMap[NEXT.first][NEXT.second].first == 1)
		return false;

	if (vecMap[NEXT.first][NEXT.second].second >= iNewNum)
		return false;

	vecMap[NEXT.first][NEXT.second].second = iNewNum;
	vecVisit[NEXT.first][NEXT.second] = iVisitCount;

	return true;
}

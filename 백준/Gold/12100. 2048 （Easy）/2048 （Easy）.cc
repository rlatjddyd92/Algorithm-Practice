#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#include <list>

using namespace std;


vector<vector<vector<int>>> vecGame; // 5단계의 상황 표시
vector<int> vecMax; // 0~5단계의 최대치 표시 
int iSize = 0;



void Check_Answer();
void Make_Number(int iDirec);
bool Check_Max();

list<int> Testlist;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iSize;

	vector<vector<int>> vecNew;

	vecMax.resize(6, -1);

	vecNew.resize(iSize);
	for (auto& iter : vecNew)
		iter.resize(iSize,-1);

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			if (iInput > 0)
			{
				++vecNew[i][j];

				for (int k = 0; k < 12; ++k)
				{
					if ((iInput & 1) == 0)
					{
						iInput = iInput >> 1;
						++vecNew[i][j];
					}
					else
						break;
				}
					
			}

			if (vecMax[0] < vecNew[i][j])
				vecMax[0] = vecNew[i][j];
		}

	vecGame.push_back(vecNew);
		
	Check_Answer();

	long long llAnswer = -1;

	for (auto& iter : vecMax)
		if (iter > llAnswer)
			llAnswer = iter;

	if (llAnswer == -1)
		llAnswer = 0;
	else
		llAnswer = pow(2, llAnswer);

	

	cout << llAnswer;

	return 0;
}

void Check_Answer()
{
	for (int i = 0; i < 4; ++i)
	{
		// i == 방향 
		/*
		0 == 위
		1 == 왼 
		2 == 아래 
		3 == 오 
		*/
		Make_Number(i);

		
		Check_Max();
		if ((vecGame.size() < 6))
		{
			Check_Answer();
		}
		
		vecGame.pop_back();
		
	}
}

void Make_Number(int iDirec)
{
	vector<vector<int>>& rBefore = vecGame.back();
	vector<vector<int>> vecNew;

	vecNew.resize(iSize);
	for (auto& iter : vecNew)
		iter.resize(iSize, -1);

	bool bIsRowFirst = true; // 반복문을 Row -> Col 순서로 돌린다 == 좌우 방향 
	bool bIsTopFirst = true; // 반복문을 위 -> 아래 OR 좌 -> 우 순서로 돌린다

	if (iDirec == 0)
	{
		bIsRowFirst = false; // 상하 
		bIsTopFirst = false; // 아래 -> 위
	}
	else if (iDirec == 1)
	{
		bIsRowFirst = true; // 좌우 
		bIsTopFirst = false; // 오른쪽 -> 왼쪽
	}
	else if (iDirec == 2)
	{
		bIsRowFirst = false; // 상하 
		bIsTopFirst = true; // 위 -> 아래
	}
	else if (iDirec == 3)
	{
		bIsRowFirst = true; // 좌우 
		bIsTopFirst = true; // 왼쪽 -> 오른쪽
	}

	pair<int, int> Order = { 0,0 };
	Order.first = bIsTopFirst == true ? 0 : -iSize + 1;
	Order.second = bIsTopFirst == true ? iSize : 1;

	for (int i = Order.first; i < Order.second; ++i)
	{
		bool bIsCanMerge = false;
		if (bIsTopFirst == false) i *= -1;
		int iNowNum = 0;

		list<int> NewNumberlist;

		for (int j = Order.first; j < Order.second; ++j)
		{
			if (bIsTopFirst == false) j *= -1;

			int iRow = bIsRowFirst == true ? i : j;
			int iCol = bIsRowFirst == true ? j : i;
			
			if ((bIsCanMerge == false) && (rBefore[iRow][iCol] >= 0))
			{
				iNowNum = rBefore[iRow][iCol];
				NewNumberlist.push_back(iNowNum);
				bIsCanMerge = true;
			}
			else if ((bIsCanMerge == true) && (rBefore[iRow][iCol] == iNowNum))
			{
				++NewNumberlist.back();
				bIsCanMerge = false;
			}
			else if ((bIsCanMerge == true) && (rBefore[iRow][iCol] >= 0))
			{
				iNowNum = rBefore[iRow][iCol];
				NewNumberlist.push_back(iNowNum);
			}

			if (bIsTopFirst == false) j *= -1;
		}

		if ((bIsRowFirst == true) && (bIsTopFirst == false))
		{
			for (int k = iSize - 1; k >= 0; --k)
			{
				if (NewNumberlist.empty() == true) break;
				vecNew[i][k] = NewNumberlist.front();
				NewNumberlist.pop_front();
			}
		}
		else if ((bIsRowFirst == true) && (bIsTopFirst == true))
		{
			for (int k = 0; k < iSize; ++k)
			{
				if (NewNumberlist.empty() == true) break;
				vecNew[i][k] = NewNumberlist.front();
				NewNumberlist.pop_front();
			}
		}
		else if ((bIsRowFirst == false) && (bIsTopFirst == false))
		{
			for (int k = iSize - 1; k >= 0; --k)
			{
				if (NewNumberlist.empty() == true) break;
				vecNew[k][i] = NewNumberlist.front();
				NewNumberlist.pop_front();
			}
		}
		else if ((bIsRowFirst == false) && (bIsTopFirst == true))
		{
			for (int k = 0; k < iSize; ++k)
			{
				if (NewNumberlist.empty() == true) break;
				vecNew[k][i] = NewNumberlist.front();
				NewNumberlist.pop_front();
			}
		}


		if (bIsTopFirst == false) i *= -1;
	}
		
	vecGame.push_back(vecNew);
}

bool Check_Max()
{
	int iNow = -1;

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			if (iNow < vecGame.back()[i][j])
				iNow = vecGame.back()[i][j];

	if (iNow >= vecMax[vecGame.size() - 1])
	{
		vecMax[vecGame.size() - 1] = iNow;
		return true;
	}

	return false;
}

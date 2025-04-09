#include <iostream>
#include <vector>

enum class DIREC
{
	DIREC_UP = 0,
	DIREC_LEFT = 1,
	DIREC_DOWN = 2,
	DIREC_RIGHT = 3,
	DIREC_END
};

using namespace std;

vector<vector<pair<int,int>>> vecMap; // 타입, 체크 
vector<pair<int, int>> vecCamera; // 행렬
vector<int> vecTest;

vector<vector<vector<pair<int, int>>>> vecMapStack;

int iRow = 0;
int iCol = 0;
int iAnswer = 0;

void Count_Camera(int iCamera, int iCountNow);
int Check_Cell(pair<int, int> Now, DIREC eDirec);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iRow >> iCol;

	vecMap.resize(iRow);

	for (int i = 0; i < iRow; ++i)
	{
		vecMap[i].resize(iCol);

		for (int j = 0; j < iCol; ++j)
		{
			cin >> vecMap[i][j].first;
			if (vecMap[i][j].first == 0)
				++iAnswer;
			else if (vecMap[i][j].first < 6)
				vecCamera.push_back({ i,j });
		}
	}

	vecMapStack.push_back(vecMap);

	if (vecCamera.empty() == false)
	Count_Camera(0, iAnswer);

	cout << iAnswer;

	for (int i = 0; i < iRow; ++i)
		vecMap[i].clear();

	vecMap.clear();

	return 0;
}

void Count_Camera(int iCamera, int iCountNow)
{
	pair<int, int> NowCamera = vecCamera[iCamera];
	int iType = vecMap[NowCamera.first][NowCamera.second].first;
	
	for (int i = 0; i < 4; ++i)
	{
		vecMapStack.push_back(vecMapStack.back());
		int iMinus = 0;

		if (iType == 1)
		{
			iMinus = Check_Cell(NowCamera, DIREC(i)) * -1;
		}
		else if (iType == 2)
		{
			if (i < 2)
			{
				iMinus = Check_Cell(NowCamera, DIREC(i)) * -1;
				iMinus += Check_Cell(NowCamera, DIREC(i + 2)) * -1;
			}
		}
		else if (iType == 3)
		{
			iMinus = Check_Cell(NowCamera, DIREC(i)) * -1;
			iMinus += Check_Cell(NowCamera, DIREC((i + 1) % 4)) * -1;
		}
		else if (iType == 4)
		{
			iMinus = Check_Cell(NowCamera, DIREC(i)) * -1;
			iMinus += Check_Cell(NowCamera, DIREC((i + 1) % 4)) * -1;
			iMinus += Check_Cell(NowCamera, DIREC((i + 2) % 4)) * -1;
		}
		else if (iType == 5)
		{
			if (i == 0)
			{
				iMinus = Check_Cell(NowCamera, DIREC(i)) * -1;
				iMinus += Check_Cell(NowCamera, DIREC(i + 1)) * -1;
				iMinus += Check_Cell(NowCamera, DIREC(i + 2)) * -1;
				iMinus += Check_Cell(NowCamera, DIREC(i + 3)) * -1;
			}
		}

		//vecTest.push_back(i);

		if (iCamera == vecCamera.size() - 1)
		{
			if (iCountNow + iMinus < iAnswer)
			{
				iAnswer = iCountNow + iMinus;
			}
			vecMapStack.pop_back();
			//vecTest.pop_back();
		}
		else
			Count_Camera(iCamera + 1, iCountNow + iMinus);
	}
	if (vecMapStack.empty() == false)
		vecMapStack.pop_back();
	//if (vecTest.empty() == false)
		//vecTest.pop_back();
	return;
}

int Check_Cell(pair<int, int> Now, DIREC eDirec)
{
	pair<int, int> Start = Now;
	pair<int, int> Add = { 0,0 };

	int iIndex = vecMapStack.size() - 1;

	int iCheck = 0;

	if (eDirec == DIREC::DIREC_UP)
		Add.first = -1;
	else if (eDirec == DIREC::DIREC_LEFT)
		Add.second = -1;
	else if (eDirec == DIREC::DIREC_DOWN)
		Add.first = 1;
	else if (eDirec == DIREC::DIREC_RIGHT)
		Add.second = 1;

	while (1)
	{
		Start.first += Add.first;
		Start.second += Add.second;

		if ((Start.first < 0) || (Start.first >= iRow))
			break;

		if ((Start.second < 0) || (Start.second >= iCol))
			break;

		if (vecMapStack[iIndex][Start.first][Start.second].first == 6)
			break;

		if (vecMapStack[iIndex][Start.first][Start.second].first == 0)
			if (vecMapStack[iIndex][Start.first][Start.second].second == 0)
				++iCheck;

		++vecMapStack[iIndex][Start.first][Start.second].second;
	}

	return iCheck;
}

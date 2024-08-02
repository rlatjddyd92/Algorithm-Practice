#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct SERACH
{
	int iRow;
	int iCol;
	int iCount;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iRow = 0;
	int iCol = 0;
	int iAnswer = 0;

	cin >> iRow >> iCol;

	vector<bool> vecVisit;
	vector<vector<int>> vecMap;
	vecVisit.resize('Z' - 'A' + 1);
	vecMap.resize(iRow);

	for (int i = 0; i < iRow; ++i)
	{
		vecMap[i].resize(iCol);
		string strInput = {};
		cin >> strInput;

		for (int j = 0; j < iCol; ++j)
		{
			vecMap[i][j] = strInput[j];
			vecMap[i][j] -= 'A';
		}
	}

	stack<SERACH> stackSerach;
	stackSerach.push({ 0,0,1 });

	while (!stackSerach.empty())
	{
		SERACH tNow = stackSerach.top();
		int iCheck = stackSerach.size();
		vecVisit[vecMap[tNow.iRow][tNow.iCol]] = true;
		if (tNow.iCount > iAnswer)
			iAnswer = tNow.iCount;

		if ((tNow.iRow > 0) && (vecVisit[vecMap[tNow.iRow - 1][tNow.iCol]] == false))
			stackSerach.push({ tNow.iRow - 1 ,tNow.iCol, tNow.iCount + 1 });
		if ((tNow.iCol > 0) && (vecVisit[vecMap[tNow.iRow][tNow.iCol - 1]] == false))
			stackSerach.push({ tNow.iRow ,tNow.iCol - 1, tNow.iCount + 1 });
		if ((tNow.iRow < iRow - 1) && (vecVisit[vecMap[tNow.iRow + 1][tNow.iCol]] == false))
			stackSerach.push({ tNow.iRow + 1 ,tNow.iCol, tNow.iCount + 1 });
		if ((tNow.iCol < iCol - 1) && (vecVisit[vecMap[tNow.iRow][tNow.iCol + 1]] == false))
			stackSerach.push({ tNow.iRow ,tNow.iCol + 1, tNow.iCount + 1 });

		if (iCheck == stackSerach.size())
		{
			vecVisit[vecMap[tNow.iRow][tNow.iCol]] = false;

			if (!stackSerach.empty())
				stackSerach.pop();

			while ((!stackSerach.empty())&&(stackSerach.top().iCount < tNow.iCount))
			{
				tNow = stackSerach.top();
				vecVisit[vecMap[tNow.iRow][tNow.iCol]] = false;
				stackSerach.pop();
			}
		}
	}

	cout << iAnswer;

	for (int i = 0; i < iRow; ++i)
		vecMap[i].clear();

	vecMap.clear();

	return 0;
}
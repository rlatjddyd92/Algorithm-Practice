#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct CELL
{
	int iWall;
	bool bPipe;
};

struct INDEX
{
	int iRow;
	int iCol;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iRow = 0;
	int iCol = 0;

	cin >> iRow >> iCol;

	vector<vector<CELL>> vecCell;
	vecCell.resize(iRow);

	vector<bool> vecPipe;
	vecPipe.resize(iRow);


	for (int i = 0; i < iRow; ++i)
	{
		vecCell[i].resize(iCol);
		string strInput = {};
		cin >> strInput;

		vecPipe[i] = true;

		for (int j = 0; j < strInput.size(); ++j)
			if (strInput[j] == 'x')
				vecCell[i][j].iWall = 3;
	}

	for (int i = iCol - 1; i > 0; --i)
	{
		for (int j = 0; j < iRow; ++j)
		{
			if (vecCell[j][i].iWall > 2)
			{
				if (j > 0)
					++vecCell[j - 1][i - 1].iWall;
				++vecCell[j][i - 1].iWall;
				if (j < iRow - 1)
					++vecCell[j + 1][i - 1].iWall;
			}
		}
	}

	int iAnswer = 0;

	for (int i = 0; i < iRow; ++i)
	{
		stack<INDEX> stackIndex;
		stackIndex.push({ i,0 });

		while (!stackIndex.empty())
		{
			INDEX tTemp = stackIndex.top();
			if (tTemp.iCol == iCol - 1)
			{
				++iAnswer;
				while (!stackIndex.empty())
					stackIndex.pop();
				break;
			}

			int iCheck = stackIndex.size();
			if ((tTemp.iRow < iRow - 1) && (vecCell[tTemp.iRow + 1][tTemp.iCol + 1].iWall < 3))
			{
				if (vecCell[tTemp.iRow + 1][tTemp.iCol + 1].bPipe == false)
					stackIndex.push({ tTemp.iRow + 1 ,tTemp.iCol + 1 });
			}
			if (vecCell[tTemp.iRow][tTemp.iCol + 1].iWall < 3)
			{
				if (vecCell[tTemp.iRow][tTemp.iCol + 1].bPipe == false)
					stackIndex.push({ tTemp.iRow ,tTemp.iCol + 1 });
			}
			if ((tTemp.iRow > 0) && (vecCell[tTemp.iRow - 1][tTemp.iCol + 1].iWall < 3))
			{
				if (vecCell[tTemp.iRow - 1][tTemp.iCol + 1].bPipe == false)
					stackIndex.push({ tTemp.iRow - 1 ,tTemp.iCol + 1 });
			}

			if ((iCheck != 0)&&(iCheck == stackIndex.size()))
			{
				stackIndex.pop();
				if ((!stackIndex.empty())&&(stackIndex.top().iCol < tTemp.iCol))
					stackIndex.pop();
			}
			else 
				vecCell[tTemp.iRow][tTemp.iCol].bPipe = true;
		}
	}

	cout << iAnswer;

	for (int i = 0; i < iRow; ++i)
		vecCell[i].clear();

	vecCell.clear();
	vecPipe.clear();

	return 0;
}
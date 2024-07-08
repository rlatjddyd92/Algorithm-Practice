#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct DRAW
{
	int iNowNum;
	int iRow;
	int iCol;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	vector<vector<bool>> vecStar;

	vecStar.resize(iNum);

	for (int i = 0; i < iNum; ++i)
		vecStar[i].resize(iNum);

	stack<DRAW> stackDraw;

	stackDraw.push({ iNum, 0, 0 });

	while (!stackDraw.empty())
	{
		int iNow = stackDraw.top().iNowNum;
		int iStartRow = stackDraw.top().iRow;
		int iStartCol = stackDraw.top().iCol;
		stackDraw.pop();

		if (iNow == 1)
		{
			vecStar[iStartRow][iStartCol] = true;
			continue;
		}

		iNow /= 3;

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
			{
				if ((i != 1) || (j != 1))
					stackDraw.push({ iNow , iStartRow + (iNow * i), iStartCol + (iNow * j )});
			}
	}

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iNum; ++j)
		{
			if (vecStar[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < iNum; ++i)
		vecStar[i].clear();

	vecStar.clear();

	return 0;
}
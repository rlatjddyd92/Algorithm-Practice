#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct CELL
{
	bool bEmpty;
	int iCount;
};

struct SERACH
{
	int iRow;
	int iCol;
	int iTime;
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

	vector<vector<CELL>> vecCell;
	vecCell.resize(iRow);

	for (int i = 0; i < iRow; ++i)
		vecCell[i].resize(iCol);

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
			cin >> vecCell[i][j].bEmpty;
			
	deque<SERACH> queueSerach;
	queueSerach.push_front({ 0,0,0 });

	while (!queueSerach.empty())
	{
		SERACH tTemp = queueSerach.front();
		queueSerach.pop_front();

		deque<SERACH> queueTemp;

		if (tTemp.iRow > 0)
			queueTemp.push_back({ tTemp.iRow - 1, tTemp.iCol, tTemp.iTime });

		if (tTemp.iCol > 0)
			queueTemp.push_back({ tTemp.iRow, tTemp.iCol - 1, tTemp.iTime });

		if (tTemp.iRow < iRow - 1)
			queueTemp.push_back({ tTemp.iRow + 1, tTemp.iCol, tTemp.iTime });

		if (tTemp.iCol < iCol - 1)
			queueTemp.push_back({ tTemp.iRow, tTemp.iCol + 1, tTemp.iTime });

		while (!queueTemp.empty())
		{
			tTemp = queueTemp.front();
			queueTemp.pop_front();

			if (vecCell[tTemp.iRow][tTemp.iCol].bEmpty)
			{
				++vecCell[tTemp.iRow][tTemp.iCol].iCount;
				if (vecCell[tTemp.iRow][tTemp.iCol].iCount >= 2)
				{
					vecCell[tTemp.iRow][tTemp.iCol].bEmpty = 0;
					queueSerach.push_back({ tTemp.iRow, tTemp.iCol, tTemp.iTime + 1 });
				}
			}
			else if (vecCell[tTemp.iRow][tTemp.iCol].iCount == 0)
			{
				vecCell[tTemp.iRow][tTemp.iCol].iCount = -1;
				queueSerach.push_front({ tTemp.iRow, tTemp.iCol, tTemp.iTime });
			}
		}

		if (tTemp.iTime > iAnswer)
			iAnswer = tTemp.iTime;
	}

	cout << iAnswer;

	for (int i = 0; i < iRow; ++i)
		vecCell[i].clear();

	vecCell.clear();

	return 0;
}
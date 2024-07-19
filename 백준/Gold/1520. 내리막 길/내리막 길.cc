#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CELL
{
	int iNum;
	int iEntrance;
	bool bVisit;
	int iCount;
};

struct SEARCH
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

	vector<vector<CELL>> vecCell;
	vecCell.resize(iRow);

	for (int i = 0; i < iRow; ++i)
		vecCell[i].resize(iCol);

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
			cin >> vecCell[i][j].iNum;

	queue<SEARCH> queueVisit;
	queueVisit.push({ 0,0,0 });
	while (!queueVisit.empty())
	{
		SEARCH sTemp = queueVisit.front();
		queueVisit.pop();

		vecCell[sTemp.iRow][sTemp.iCol].bVisit = true;
		if ((sTemp.iRow > 0) && (vecCell[sTemp.iRow - 1][sTemp.iCol].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
			if (vecCell[sTemp.iRow - 1][sTemp.iCol].bVisit == false)
			{
				queueVisit.push({ sTemp.iRow - 1 , sTemp.iCol ,sTemp.iCount + vecCell[sTemp.iRow][sTemp.iCol].iCount });
				vecCell[sTemp.iRow - 1][sTemp.iCol].bVisit = true;
			}
			
		if ((sTemp.iCol > 0) && (vecCell[sTemp.iRow][sTemp.iCol - 1].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
			if (vecCell[sTemp.iRow][sTemp.iCol - 1].bVisit == false)
			{
				queueVisit.push({ sTemp.iRow , sTemp.iCol - 1,sTemp.iCount + vecCell[sTemp.iRow][sTemp.iCol].iCount });
				vecCell[sTemp.iRow][sTemp.iCol - 1].bVisit = true;
			}
			
		if ((sTemp.iRow < iRow - 1) && (vecCell[sTemp.iRow + 1][sTemp.iCol].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
			if (vecCell[sTemp.iRow + 1][sTemp.iCol].bVisit == false)
			{
				queueVisit.push({ sTemp.iRow + 1 , sTemp.iCol ,sTemp.iCount + vecCell[sTemp.iRow][sTemp.iCol].iCount });
				vecCell[sTemp.iRow + 1][sTemp.iCol].bVisit = true;
			}
			
		if ((sTemp.iCol < iCol - 1) && (vecCell[sTemp.iRow][sTemp.iCol + 1].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
			if (vecCell[sTemp.iRow][sTemp.iCol + 1].bVisit == false)
			{
				queueVisit.push({ sTemp.iRow , sTemp.iCol + 1,sTemp.iCount + vecCell[sTemp.iRow][sTemp.iCol].iCount });
				vecCell[sTemp.iRow][sTemp.iCol + 1].bVisit = true;
			}
	}

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
		{
			if ((i > 0) && (vecCell[i - 1][j].iNum > vecCell[i][j].iNum))
				if (vecCell[i - 1][j].bVisit == true)
					++vecCell[i][j].iEntrance;

			if ((j > 0) && (vecCell[i][j - 1].iNum > vecCell[i][j].iNum))
				if (vecCell[i][j - 1].bVisit == true)
					++vecCell[i][j].iEntrance;

			if ((i < iRow - 1) && (vecCell[i + 1][j].iNum > vecCell[i][j].iNum))
				if (vecCell[i + 1][j].bVisit == true)
					++vecCell[i][j].iEntrance;

			if ((j < iCol - 1) && (vecCell[i][j + 1].iNum > vecCell[i][j].iNum))
				if (vecCell[i][j + 1].bVisit == true)
					++vecCell[i][j].iEntrance;
		}

	queue<SEARCH> queueSearch;
	queueSearch.push({ 0,0,1 });

	while (!queueSearch.empty())
	{
		SEARCH sTemp = queueSearch.front();
		queueSearch.pop();
		--vecCell[sTemp.iRow][sTemp.iCol].iEntrance;
		if (vecCell[sTemp.iRow][sTemp.iCol].iEntrance > 0)
			vecCell[sTemp.iRow][sTemp.iCol].iCount += sTemp.iCount;
		else
		{
			vecCell[sTemp.iRow][sTemp.iCol].iCount += sTemp.iCount;

			if ((sTemp.iRow > 0) && (vecCell[sTemp.iRow - 1][sTemp.iCol].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
				queueSearch.push({ sTemp.iRow - 1 , sTemp.iCol ,vecCell[sTemp.iRow][sTemp.iCol].iCount });

			if ((sTemp.iCol > 0) && (vecCell[sTemp.iRow][sTemp.iCol - 1].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
				queueSearch.push({ sTemp.iRow , sTemp.iCol - 1,vecCell[sTemp.iRow][sTemp.iCol].iCount });

			if ((sTemp.iRow < iRow - 1) && (vecCell[sTemp.iRow + 1][sTemp.iCol].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
				queueSearch.push({ sTemp.iRow + 1 , sTemp.iCol ,vecCell[sTemp.iRow][sTemp.iCol].iCount });

			if ((sTemp.iCol < iCol - 1) && (vecCell[sTemp.iRow][sTemp.iCol + 1].iNum < vecCell[sTemp.iRow][sTemp.iCol].iNum))
				queueSearch.push({ sTemp.iRow , sTemp.iCol + 1,vecCell[sTemp.iRow][sTemp.iCol].iCount });
		}
	}

	cout << vecCell[iRow - 1][iCol - 1].iCount;

	for (int i = 0; i < iRow; ++i)
		vecCell[i].clear();

	vecCell.clear();

	return 0;
}

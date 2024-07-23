#include <iostream>
#include <vector>
#include <queue>

#define WATER '*'
#define EMPTY '.'
#define DEN 'D'
#define ANIMAL 'S'

using namespace std;

struct MOVE
{
	int iRow;
	int iCol;
	int iTurn;
};

struct CELL
{
	int iState;
	int iTurn;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iMaxRow = 0;
	int iMaxCol = 0;
	int iEndRow = 0;
	int iEndCol = 0;
	int iAnswer = -1;

	cin >> iMaxRow >> iMaxCol;

	vector<vector<CELL>> vecCell;

	vecCell.resize(iMaxRow);

	for (int i = 0; i < iMaxRow; ++i)
		vecCell[i].resize(iMaxCol);

	queue<MOVE> queueWater;
	queue<MOVE> queueAnimal;

	for (int i = 0; i < iMaxRow; ++i)
	{
		string strInput = {};
		cin >> strInput;

		for (int j = 0; j < iMaxCol; ++j)
		{
			vecCell[i][j].iState = strInput[j];
			if (strInput[j] == WATER)
				queueWater.push({ i,j,0 });

			if (strInput[j] == ANIMAL)
				queueAnimal.push({ i,j,0 });

			if (strInput[j] == DEN)
			{
				iEndRow = i;
				iEndCol = j;
			}
		}
	}

	while (!queueAnimal.empty())
	{
		int iCount = queueWater.size();

		for (int i = 0; i < iCount; ++i)
		{
			MOVE tTemp = queueWater.front();
			queueWater.pop();

			queue<MOVE> queueTemp;

			if (tTemp.iRow > 0)
				queueTemp.push({ tTemp.iRow - 1 , tTemp.iCol , 0 });

			if (tTemp.iCol > 0)
				queueTemp.push({ tTemp.iRow , tTemp.iCol - 1 , 0 });

			if (tTemp.iRow < iMaxRow - 1)
				queueTemp.push({ tTemp.iRow + 1 , tTemp.iCol , 0 });

			if (tTemp.iCol < iMaxCol - 1)
				queueTemp.push({ tTemp.iRow , tTemp.iCol + 1, 0 });

			while (!queueTemp.empty())
			{
				tTemp = queueTemp.front();
				queueTemp.pop();
				if (vecCell[tTemp.iRow][tTemp.iCol].iState == EMPTY)
				{
					queueWater.push(tTemp);
					vecCell[tTemp.iRow][tTemp.iCol].iState = WATER;
				}
			}
		}

		iCount = queueAnimal.size();

		for (int i = 0; i < iCount; ++i)
		{
			MOVE tTemp = queueAnimal.front();
			queueAnimal.pop();

			queue<MOVE> queueTemp;

			if (tTemp.iRow > 0)
				queueTemp.push({ tTemp.iRow - 1 , tTemp.iCol , tTemp.iTurn + 1 });

			if (tTemp.iCol > 0)
				queueTemp.push({ tTemp.iRow , tTemp.iCol - 1 , tTemp.iTurn + 1 });

			if (tTemp.iRow < iMaxRow - 1)
				queueTemp.push({ tTemp.iRow + 1 , tTemp.iCol , tTemp.iTurn + 1 });

			if (tTemp.iCol < iMaxCol - 1)
				queueTemp.push({ tTemp.iRow , tTemp.iCol + 1, tTemp.iTurn + 1 });

			while (!queueTemp.empty())
			{
				tTemp = queueTemp.front();
				queueTemp.pop();
				if (vecCell[tTemp.iRow][tTemp.iCol].iState == EMPTY)
					if (vecCell[tTemp.iRow][tTemp.iCol].iTurn == 0)
					{
						queueAnimal.push(tTemp);
						vecCell[tTemp.iRow][tTemp.iCol].iTurn = tTemp.iTurn;
					}

				if (vecCell[tTemp.iRow][tTemp.iCol].iState == DEN)
					if ((iAnswer == -1) || (iAnswer > tTemp.iTurn))
						iAnswer = tTemp.iTurn;
			}
		}
	}

	if (iAnswer == -1)
		cout << "KAKTUS";
	else
		cout << iAnswer;

	for (int i = 0; i < iMaxRow; ++i)
		vecCell[i].clear();

	vecCell.clear();

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

#define EMPTY 0
#define NORMAL 1
#define REMOVED -1

using namespace std;

struct MELT
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

	vector<vector<int>> vecTile;

	vecTile.resize(iRow);

	for (int i = 0; i < iRow; ++i)
		vecTile[i].resize(iCol);

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
			cin >> vecTile[i][j];

	queue<MELT> queueFindSerface;
	queue<MELT> queueMelt;
	queueFindSerface.push({ 0,0 });

	int iTime = 0;
	int iLast = 0;

	do
	{
		while (!queueFindSerface.empty())
		{
			MELT tTemp = queueFindSerface.front();
			queueFindSerface.pop();

			queue<MELT> queueTemp;

			if (tTemp.iRow > 0)
				queueTemp.push({ tTemp.iRow - 1, tTemp.iCol });

			if (tTemp.iCol > 0)
				queueTemp.push({ tTemp.iRow, tTemp.iCol - 1 });

			if (tTemp.iRow < iRow - 1)
				queueTemp.push({ tTemp.iRow + 1, tTemp.iCol });

			if (tTemp.iCol < iCol - 1)
				queueTemp.push({ tTemp.iRow, tTemp.iCol + 1 });

			while (!queueTemp.empty())
			{
				tTemp = queueTemp.front();
				queueTemp.pop();

				if (vecTile[tTemp.iRow][tTemp.iCol] == EMPTY)
				{
					queueFindSerface.push(tTemp);
					vecTile[tTemp.iRow][tTemp.iCol] = REMOVED;
				}
				else if (vecTile[tTemp.iRow][tTemp.iCol] == NORMAL)
				{
					queueMelt.push(tTemp);
					vecTile[tTemp.iRow][tTemp.iCol] = REMOVED;
				}
			}
		}

		if (queueMelt.empty())
			break;

			iLast = queueMelt.size();
			++iTime;

			for (int i = 0; i < iLast; ++i)
			{
				MELT tTemp = queueMelt.front();
				queueMelt.pop();

				queue<MELT> queueTemp;

				if (tTemp.iRow > 0)
					queueTemp.push({ tTemp.iRow - 1, tTemp.iCol });

				if (tTemp.iCol > 0)
					queueTemp.push({ tTemp.iRow, tTemp.iCol - 1 });

				if (tTemp.iRow < iRow - 1)
					queueTemp.push({ tTemp.iRow + 1, tTemp.iCol });

				if (tTemp.iCol < iCol - 1)
					queueTemp.push({ tTemp.iRow, tTemp.iCol + 1 });

				while (!queueTemp.empty())
				{
					tTemp = queueTemp.front();
					queueTemp.pop();

					if (vecTile[tTemp.iRow][tTemp.iCol] == NORMAL)
					{
						queueMelt.push(tTemp);
						vecTile[tTemp.iRow][tTemp.iCol] = REMOVED;
					}
					else if (vecTile[tTemp.iRow][tTemp.iCol] == EMPTY)
					{
						queueFindSerface.push(tTemp);
						vecTile[tTemp.iRow][tTemp.iCol] = REMOVED;
					}
				}
			}
	} while ((!queueFindSerface.empty()) || (!queueMelt.empty()));

	cout << iTime << "\n";
	cout << iLast;

	for (int i = 0; i < iRow; ++i)
		vecTile[i].clear();

	vecTile.clear();

	return 0;
}
#include <iostream>
#include <vector>

#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'
#define UP 'U'

using namespace std;

struct TILE
{
	TILE () :
		iNumCheck(0)
		, szCommand('\0')
	{}

	int iNumCheck;
	char szCommand;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iRow = 0;
	int iCol = 0;

	cin >> iRow >> iCol;

	vector<vector<TILE>> vecTile;
	vecTile.resize(iRow);

	for (int i = 0; i < iRow; ++i)
	{
		string strInput = {};
		cin >> strInput;
		vecTile[i].resize(iCol);
		
		for (int j = 0; j < iCol; ++j)
			vecTile[i][j].szCommand = strInput[j];
	}

	int iNowNum = 0;
	int iAnswer = 0;

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
		{
			if (!vecTile[i][j].iNumCheck)
			{
				++iNowNum;
				int iNowRow = i;
				int iNowCol = j;

				while (1)
				{
					vecTile[iNowRow][iNowCol].iNumCheck = iNowNum;

					if (vecTile[iNowRow][iNowCol].szCommand == UP)
						--iNowRow;
					else if (vecTile[iNowRow][iNowCol].szCommand == DOWN)
						++iNowRow;
					else if (vecTile[iNowRow][iNowCol].szCommand == LEFT)
						--iNowCol;
					else if (vecTile[iNowRow][iNowCol].szCommand == RIGHT)
						++iNowCol;

					if (!vecTile[iNowRow][iNowCol].iNumCheck)
						continue;

					if ((iNowRow < 0) || (iNowRow >= iRow))
					{
						++iAnswer;
						break;
					}

					if ((iNowCol < 0) || (iNowCol >= iCol))
					{
						++iAnswer;
						break;
					}

					if (vecTile[iNowRow][iNowCol].iNumCheck < iNowNum)
						break;

					if (vecTile[iNowRow][iNowCol].iNumCheck == iNowNum)
					{
						++iAnswer;
						break;
					}
				}
			}
		}

	cout << iAnswer;

	for (int i = 0; i < iRow; ++i)
		vecTile[i].clear();

	vecTile.clear();

	return 0;
}
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct COMMAND
{
	int iNum;
	int iRow;
	int iCol;
};

int main()
{
	int iNum = 0;
	int iRow = 0;
	int iCol = 0;
	int iAnswer = 0;

	cin >> iNum >> iRow >> iCol;

	queue<COMMAND> queueCom;
	queueCom.push({ iNum - 1, 0,0 });

	while (!queueCom.empty())
	{
		int iNowNum = queueCom.front().iNum;
		int iNowRow = queueCom.front().iRow;
		int iNowCol = queueCom.front().iCol;
		queueCom.pop();

		if (iNowNum <= 0)
		{
			if ((iNowRow == iRow) && (iNowCol == iCol)) break; else ++iAnswer;
			if ((iNowRow == iRow) && (iNowCol + 1 == iCol)) break; else ++iAnswer;
			if ((iNowRow + 1 == iRow) && (iNowCol == iCol)) break; else ++iAnswer;
			if ((iNowRow + 1 == iRow) && (iNowCol + 1 == iCol)) break; else ++iAnswer;
		}
		else
		{
			if ((iNowCol + int(pow(2, iNowNum)) <= iCol) && (iNowRow + int(pow(2, iNowNum)) <= iRow))
			{
				iAnswer += int(pow(pow(2, iNowNum), 2)) * 3;
				queueCom.push({ iNowNum - 1, iNowRow + int(pow(2, iNowNum)),iNowCol + int(pow(2, iNowNum)) });
			}
			else if ((iNowCol + int(pow(2, iNowNum)) > iCol) && (iNowRow + int(pow(2, iNowNum)) <= iRow))
			{
				iAnswer += int(pow(pow(2, iNowNum), 2)) * 2;
				queueCom.push({ iNowNum - 1, iNowRow + int(pow(2, iNowNum)),iNowCol });
			}
			else if ((iNowCol + int(pow(2, iNowNum)) <= iCol) && (iNowRow + int(pow(2, iNowNum)) > iRow))
			{
				iAnswer += int(pow(pow(2, iNowNum), 2)) ;
				queueCom.push({ iNowNum - 1, iNowRow,iNowCol + int(pow(2, iNowNum)) });
			}
			else
			{
				queueCom.push({ iNowNum - 1, iNowRow,iNowCol });
			}
		}
	}

	cout << iAnswer;

	return 0;
}
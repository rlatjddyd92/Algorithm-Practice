#include <iostream>
#include <vector>

using namespace std;

void DFS(int** Arr, int* Count, int Row, int Col, int Maxrow, int Maxcol);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iRow = 0;
		int iCol = 0;
		int iNum = 0;
		int iCount = 0;

		cin >> iCol >> iRow >> iNum;

		int** iArr = new int* [iRow];

		for (int j = 0; j < iRow; ++j)
			iArr[j] = new int[iCol];

		for (int j = 0; j < iRow; ++j)
			for (int k = 0; k < iCol; ++k)
				iArr[j][k] = 0;

		for (int j = 0; j < iNum; ++j)
		{
			int iInputRow = 0;
			int iInputCol = 0; 

			cin >> iInputCol >> iInputRow;
			iArr[iInputRow][iInputCol] = 1;
		}

		for (int j = 0; j < iRow; ++j)
			for (int k = 0; k < iCol; ++k)
			{
				if (1 == iArr[j][k])
				{
					DFS(iArr, &iCount, j, k, iRow, iCol);
					++iCount;
				}
			}

		cout << iCount << "\n";

		for (int j = 0; j < iRow; ++j)
		{
			delete iArr[j];
			iArr[j] = nullptr;
		}

		delete[]iArr;
		iArr = nullptr;
	}

	return 0;
}

void DFS(int** Arr, int* Count, int Row, int Col, int Maxrow, int Maxcol)
{
	Arr[Row][Col] = 2;

	if ((0 < Row) && (1 == Arr[Row - 1][Col]))
		DFS(Arr, Count, Row - 1, Col, Maxrow, Maxcol);

	if ((Maxrow - 1 > Row) && (1 == Arr[Row + 1][Col]))
		DFS(Arr, Count, Row + 1, Col, Maxrow, Maxcol);

	if ((0 < Col) && (1 == Arr[Row][Col - 1]))
		DFS(Arr, Count, Row, Col - 1, Maxrow, Maxcol);

	if ((Maxcol - 1 > Col) && (1 == Arr[Row][Col + 1]))
		DFS(Arr, Count, Row, Col + 1, Maxrow, Maxcol);
}

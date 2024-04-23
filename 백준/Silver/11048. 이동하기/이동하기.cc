#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int iRow = 0;
	int iCol = 0;

	cin >> iRow >> iCol;

	int** iArr = new int* [iRow + 1];

	for (int i = 0; i <= iRow;++i)
		iArr[i] = new int[iCol + 1];

	for (int i = 0; i <= iCol;++i)
		iArr[0][i] = 0;

	for (int i = 0; i <= iRow;++i)
		iArr[i][0] = 0;

	for (int i = 1; i <= iRow;++i)
		for (int j = 1; j <= iCol;++j)
		{
			int iInput = 0;
			cin >> iInput;

			iArr [i][j] = iInput + max(iArr[i - 1][j - 1], max(iArr[i - 1][j], iArr[i][j - 1]));
		}
			
	cout << iArr[iRow][iCol];

	for (int i = 0; i <= iRow;++i)
	{
		delete iArr[i];
		iArr[i] = nullptr;
	}

	delete[]iArr;
	iArr = nullptr;

	return 0;
}
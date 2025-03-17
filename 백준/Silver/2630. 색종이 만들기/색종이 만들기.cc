#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vecCell;

int iCount[2] = { 0,0 };

int Check_Cell(int iRow, int iCol, int iSize);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize = 0;

	cin >> iSize;

	vecCell.resize(iSize);

	for (auto& iter : vecCell)
		iter.resize(iSize);

	for (int i = 0; i < iSize; ++i)
		for (int j = 0; j < iSize; ++j)
			cin >> vecCell[i][j];

	int iCheck = Check_Cell(0,0, iSize);

	if (iCheck != -1)
		++iCount[iCheck];

	for (auto& iter : vecCell)
		iter.clear();

	vecCell.clear();

	cout << iCount[0] << "\n" << iCount[1];

	return 0;
}

int Check_Cell(int iRow, int iCol, int iSize)
{
	if (iSize == 1)
		return vecCell[iRow][iCol];

	int iCheck[4] = { 0,0,0,0 };

	iCheck[0] = Check_Cell(iRow, iCol, (iSize / 2));
	iCheck[1] = Check_Cell(iRow + (iSize / 2), iCol, (iSize / 2));
	iCheck[2] = Check_Cell(iRow, iCol + (iSize / 2), (iSize / 2));
	iCheck[3] = Check_Cell(iRow + (iSize / 2), iCol + (iSize / 2), (iSize / 2));

	if ((iCheck[0] == iCheck[1]) && (iCheck[2] == iCheck[3]))
		if (iCheck[1] == iCheck[2])
			return iCheck[0];

	for (int i = 0; i < 4; ++i)
		if (iCheck[i] != -1)
			++iCount[iCheck[i]];
	
	return -1;
}

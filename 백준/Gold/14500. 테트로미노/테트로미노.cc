#include <iostream>
#include <vector>

using namespace std;

// 브루트 포스 
// 칸 수 : 500*500 = 250000
// 테트로미노 종류 : 19종 
// 총 횟수 = 25만 * 19 * 4 = 대략 2000만 정도 


void Check_Tetromino(int iRow, int iCol);

void Check_Line_H(int iRow, int iCol); // 가로 4칸
void Check_Line_V(int iRow, int iCol); // 세로 4칸 

void Check_Squre(int iRow, int iCol); // 정사각형 

void Check_Middle_Up(int iRow, int iCol); // ㅗ 위쪽 
void Check_Middle_Left(int iRow, int iCol); // ㅗ 왼쪽
void Check_Middle_Down(int iRow, int iCol); // ㅗ 아래쪽
void Check_Middle_Right(int iRow, int iCol); // ㅗ 오른쪽

void Check_Z_H(int iRow, int iCol); // 지그재그 1형 가로 
void Check_Z_V(int iRow, int iCol); // 지그재그 1형 세로 
void Check_Z_R_H(int iRow, int iCol); // 지그재그 2형 가로
void Check_Z_R_V(int iRow, int iCol); // 지그재그 2형 세로

void Check_L_U(int iRow, int iCol); // L 정방향 위
void Check_L_L(int iRow, int iCol); // L 정방향 왼
void Check_L_D(int iRow, int iCol); // L 정방향 아
void Check_L_R(int iRow, int iCol); // L 정방향 오
void Check_L_R_U(int iRow, int iCol); // L 역방향 위
void Check_L_R_L(int iRow, int iCol); // L 역방향 왼
void Check_L_R_D(int iRow, int iCol); // L 역방향 아
void Check_L_R_R(int iRow, int iCol); // L 역방향 오

vector<vector<int>> vecCell;

pair<int, int> SizeOfCell;
int iAnswer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> SizeOfCell.first >> SizeOfCell.second;

	vecCell.resize(SizeOfCell.first);

	for(auto& iter : vecCell)
		iter.resize(SizeOfCell.second);

	for (int i = 0; i < SizeOfCell.first; ++i)
		for (int j = 0; j < SizeOfCell.second; ++j)
			cin >> vecCell[i][j];

	for (int i = 0; i < SizeOfCell.first; ++i)
		for (int j = 0; j < SizeOfCell.second; ++j)
		{
			Check_Tetromino(i, j);
		}

	cout << iAnswer;

	for (auto& iter : vecCell)
		iter.clear();

	vecCell.clear();

	return 0;
}

void Check_Tetromino(int iRow, int iCol)
{
	Check_Line_H(iRow, iCol);
	Check_Line_V(iRow, iCol);
	Check_Squre(iRow, iCol);
	Check_Middle_Up(iRow, iCol);
	Check_Middle_Left(iRow, iCol);
	Check_Middle_Down(iRow, iCol);
	Check_Middle_Right(iRow, iCol);
	Check_Z_H(iRow, iCol);
	Check_Z_V(iRow, iCol);
	Check_Z_R_H(iRow, iCol);
	Check_Z_R_V(iRow, iCol);
	Check_L_U(iRow, iCol);
	Check_L_L(iRow, iCol);
	Check_L_D(iRow, iCol);
	Check_L_R(iRow, iCol);
	Check_L_R_U(iRow, iCol);
	Check_L_R_L(iRow, iCol);
	Check_L_R_D(iRow, iCol);
	Check_L_R_R(iRow, iCol);
}

void Check_Line_H(int iRow, int iCol)
{
	if (iRow + 3 >= SizeOfCell.first)
		return;

	int iSum = 0;

	for (int i = iRow; i < iRow + 4; ++i)
		iSum += vecCell[i][iCol];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Line_V(int iRow, int iCol)
{
	if (iCol + 3 >= SizeOfCell.second)
		return;

	int iSum = 0;

	for (int i = iCol; i < iCol + 4; ++i)
		iSum += vecCell[iRow][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Squre(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	for (int i = iRow; i < iRow + 2; ++i)
		for (int j = iCol; j < iCol + 2; ++j)
		iSum += vecCell[i][j];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Middle_Up(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol + 1];

	for (int i = iCol; i < iCol + 3; ++i)
			iSum += vecCell[iRow + 1][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Middle_Left(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol + 1];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Middle_Down(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol + 1];

	for (int i = iCol; i < iCol + 3; ++i)
		iSum += vecCell[iRow][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Middle_Right(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol + 1];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Z_H(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol + 1];
	iSum += vecCell[iRow + 1][iCol + 1];
	iSum += vecCell[iRow + 1][iCol];
	iSum += vecCell[iRow + 2][iCol];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Z_V(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol];
	iSum += vecCell[iRow][iCol + 1];
	iSum += vecCell[iRow + 1][iCol + 1];
	iSum += vecCell[iRow + 1][iCol + 2];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Z_R_H(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol];
	iSum += vecCell[iRow + 1][iCol];
	iSum += vecCell[iRow + 1][iCol + 1];
	iSum += vecCell[iRow + 2][iCol + 1];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_Z_R_V(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol];
	iSum += vecCell[iRow + 1][iCol + 1];
	iSum += vecCell[iRow][iCol + 1];
	iSum += vecCell[iRow][iCol + 2];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_U(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 2][iCol + 1];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_L(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol + 2];

	for (int i = iCol; i < iCol + 3; ++i)
		iSum += vecCell[iRow + 1][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_D(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol + 1];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_R(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol];

	for (int i = iCol; i < iCol + 3; ++i)
		iSum += vecCell[iRow][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_R_U(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 2][iCol];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol + 1];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_R_L(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow + 1][iCol + 2];

	for (int i = iCol; i < iCol + 3; ++i)
		iSum += vecCell[iRow][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_R_D(int iRow, int iCol)
{
	if ((iRow + 2 >= SizeOfCell.first) || (iCol + 1 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol + 1];

	for (int i = iRow; i < iRow + 3; ++i)
		iSum += vecCell[i][iCol];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

void Check_L_R_R(int iRow, int iCol)
{
	if ((iRow + 1 >= SizeOfCell.first) || (iCol + 2 >= SizeOfCell.second))
		return;

	int iSum = 0;

	iSum += vecCell[iRow][iCol];

	for (int i = iCol; i < iCol + 3; ++i)
		iSum += vecCell[iRow + 1][i];

	if (iAnswer < iSum)
		iAnswer = iSum;
}

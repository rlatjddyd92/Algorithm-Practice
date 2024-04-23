#include <iostream>
#include <cmath>

using namespace std;

void BackTraking(int* iArr, int Row, int Num, int* iAnswer);

int main()
{
	int iNum = 0;
	int iAnswer = 0;

	cin >> iNum;

	int* iCol = new int [iNum];

	BackTraking(iCol, 0, iNum, &iAnswer);

	cout << iAnswer;

	delete[]iCol;
	iCol = nullptr;

	return 0;
}

void BackTraking(int* iCol, int Row, int Num, int* iAnswer)
{

	for (int i = 0; i < Num; ++i)
	{
		bool bNext = 0;

		for (int j = 0; j < Row; ++j)
		{
			if ((i == iCol[j])|| (pow(Row - j, 2) == pow(i - iCol[j], 2)))
			{
				bNext = 1;
				break;
			}
		}

		if (1 == bNext)
			continue;

		iCol[Row] = i;

		if (Row != Num - 1)
			BackTraking(iCol, Row + 1, Num, iAnswer);
		else
			++ * iAnswer;
	}

	iCol[Row] = 0;
}

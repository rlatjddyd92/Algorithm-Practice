#include <iostream>

using namespace std;

void BT(int* iArr, int* Use, int Start, int order, int iIndex);

int main()
{
	int iNum = 0;
	int iIndex = 0;
	

	cin >> iNum >> iIndex;

	int iArr[10001] = { 0 };
	int* iUseNum = new int[iIndex];

	for (int i = 0; i < iIndex; ++i)
		iUseNum[i] = 0;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		iArr[iInput] = 1;
	}

	BT(iArr, iUseNum, 1, 0, iIndex);

	delete[]iUseNum;
	iUseNum = nullptr;

	return 0;
}

void BT(int* iArr, int* Use, int Start, int order, int iIndex)
{
	for (int i = Start; i < 10001; ++i)
	{
		if (1 == iArr[i])
			Use[order] = i;
		else 
			continue;

		if ((order == iIndex - 1)&&(0 != Use[order]))
		{
			for (int j = 0; j < iIndex; ++j)
				cout << Use[j] << " ";

			cout << "\n";
			Use[order] = 0;
			continue;
		}

		BT(iArr, Use, i, order + 1, iIndex);
	}
}

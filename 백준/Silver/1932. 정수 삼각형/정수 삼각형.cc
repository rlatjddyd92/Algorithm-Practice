#include <iostream>

using namespace std;

int main()
{
	int iFloor = 0;

	cin >> iFloor;

	int** iPyramid = new int*[iFloor+1];

	for (int i = 0; i <= iFloor; ++i)
		iPyramid[i] = new int[iFloor + 1];

	for (int i = 0; i <= iFloor; ++i)
		for (int j = 0; j <= iFloor; ++j)
			iPyramid[i][j] = 0;

	for (int i = 1; i <= iFloor; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			if (iPyramid[i - 1][j - 1] > iPyramid[i - 1][j])
				iPyramid[i][j] = iInput + iPyramid[i - 1][j - 1];
			else 
				iPyramid[i][j] = iInput + iPyramid[i - 1][j];
		}
	}

	int iAnswer = 0;

	for (int i = 1; i <= iFloor; ++i)
		if (iAnswer < iPyramid[iFloor][i])
			iAnswer = iPyramid[iFloor][i];

	cout << iAnswer;

	for (int i = 0; i <= iFloor; ++i)
	{
		delete iPyramid[i];
		iPyramid[i] = nullptr;
	}

	delete[]iPyramid;
	iPyramid = nullptr;

	return 0;
}
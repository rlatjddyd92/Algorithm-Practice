#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum[6] = { 0, };
	int iAnswer = 0;

	for (int i = 0; i < 6; ++i)
		cin >> iNum[i];

	iAnswer += iNum[5];
	iAnswer += iNum[4];
	iNum[0] -= iNum[4] * 11;
	iAnswer += iNum[3];
	if (iNum[1] <= (iNum[3] * 5))
	{
		iNum[0] -= ((iNum[3] * 5) - iNum[1]) * 4;
		iNum[1] = 0;
	}
	else 
		iNum[1] -= iNum[3] * 5;

	if (iNum[0] < 0)
		iNum[0] = 0;
	if (iNum[1] < 0)
		iNum[1] = 0;

	iAnswer += iNum[2] / 4;
	iNum[2] %= 4;

	if (iNum[2] > 0)
	{
		++iAnswer;
		if (iNum[2] == 1)
		{
			iNum[1] -= 5;
			iNum[0] -= 7;
		}
		else if (iNum[2] == 2)
		{
			iNum[1] -= 3;
			iNum[0] -= 6;
		}
		else
		{
			iNum[1] -= 1;
			iNum[0] -= 5;
		}

		if (iNum[1] < 0)
			iNum[0] += (iNum[1] * 4);
	}

	if (iNum[0] < 0)
		iNum[0] = 0;
	if (iNum[1] < 0)
		iNum[1] = 0;

	iAnswer += iNum[1] / 9;
	iNum[1] %= 9;

	if (iNum[1] > 0)
	{
		++iAnswer;
		iNum[0] -= (9 - iNum[1]) * 4;
	}

	if (iNum[0] < 0)
		iNum[0] = 0;
	if (iNum[1] < 0)
		iNum[1] = 0;

	iAnswer += iNum[0] / 36;
	iNum[0] %= 36;

	if (iNum[0] > 0)
		++iAnswer;

	cout << iAnswer;

	return 0;
}
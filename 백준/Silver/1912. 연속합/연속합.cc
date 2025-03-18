#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;
	int iAnswer = -1001;

	int iSum = 0;

	cin >> iNumber;

	for (int i = 0; i < iNumber; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		iSum += iInput;

		if (iSum > iAnswer)
			iAnswer = iSum;

		if (iSum <= 0)
			iSum = 0;
	}

	cout << iAnswer;

	return 0;
}
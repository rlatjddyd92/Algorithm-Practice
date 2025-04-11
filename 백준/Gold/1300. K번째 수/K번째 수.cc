#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iSize = 0;
	long long iNum = 0;

	cin >> iSize >> iNum;

	long long iBefore = 1;
	long long iNow = iNum;

	long long iAnswer = iNum;

	while (1)
	{
		long long iCheckNum = (iBefore + iNow) / 2;
		long long iCount = 0;
		for (long long i = 1; i <= iSize; ++i)
			iCount += min(iCheckNum / i, iSize);

		if (iCount < iNum)
		{
			iBefore = max(iBefore, iNow);
		}
		else if (iCount >= iNum)
		{
			iBefore = min(iBefore, iNow);
			if (iAnswer > iCheckNum)
				iAnswer = iCheckNum;
		}
		if (iCheckNum == iNow) break;
		iNow = iCheckNum;
	}

	cout << iAnswer;

	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iDistance = 0;
		int iAnswer = 0;

		cin >> iStart >> iEnd;

		iDistance = iEnd - iStart;

		while (1)
		{
			int iMinus = sqrt(iDistance);

			iDistance -= iMinus;
			++iAnswer;

			if (!iDistance) break;
		}

		cout << iAnswer << endl;
	}

	return 0;
}
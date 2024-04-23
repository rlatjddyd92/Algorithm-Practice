#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iStartRow = 0;
		int iStartCol = 0;
		int iEndRow = 0;
		int iEndCol = 0;
		int iSystem = 0;
		int iCount = 0;

		cin >> iStartRow >> iStartCol >> iEndRow >> iEndCol;

		cin >> iSystem;

		for (int j = 0; j < iSystem; ++j)
		{
			int iCenterRow = 0;
			int iCenterCol = 0;
			int iR = 0;

			cin >> iCenterRow >> iCenterCol >> iR;

			int iStartCenter = pow((iStartRow - iCenterRow), 2) + pow((iStartCol - iCenterCol), 2);
			int iEndCenter = pow((iEndRow - iCenterRow), 2) + pow((iEndCol - iCenterCol), 2);

			if ((pow(iR, 2) > iStartCenter) && (pow(iR, 2) > iEndCenter))
				continue;
			if ((pow(iR, 2) > iStartCenter) || (pow(iR, 2) > iEndCenter))
				++iCount;
		}

		cout << iCount << "\n";
	}

	return 0;
}
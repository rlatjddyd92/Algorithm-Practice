#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;
	int iCountLeft = 0;
	int iCountRight = 0;

	cin >> iNumber >> iCountLeft >> iCountRight;

	if (iCountLeft + iCountRight > iNumber + 1)
		cout << "-1";
	else
	{
		int iNow = 1;
		for (int i = 1; i <= iNumber; ++i)
		{
			if ((iCountLeft == 1) && (i == 1))
			{
				cout << iCountRight;
			}
			else if (i <= iNumber - (iCountLeft + iCountRight) + 1)
				cout << 1;
			else if (i < iNumber - iCountRight + 1)
			{
				cout << iNow;
				++iNow;
			}
			else if (i == iNumber - iCountRight + 1)
			{
				iNow = iCountLeft > iCountRight ? iCountLeft : iCountRight;
				if ((iCountLeft != 1))
					cout << iNow;
				else
					cout << 1;
				--iNow;
			}
			else
			{
				cout << (iNumber - i) + 1;
				--iNow;
			}

			cout << " ";
		}
	}


	return 0;
}
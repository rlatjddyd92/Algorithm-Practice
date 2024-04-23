#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int ARow = 0;
	int ACol = 0;
	int ADistance = 0; 
	int BRow = 0;
	int BCol = 0;
	int BDistance = 0;

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		cin >> ARow >> ACol >> ADistance >> BRow >> BCol >> BDistance;

		int iRR = (pow((ARow - BRow), 2) + pow((ACol - BCol), 2));
		int iLong = max(ADistance, BDistance);
		int iShort = min(ADistance, BDistance);

		if ((ADistance == BDistance) && (0 == iRR))
			cout << -1 << "\n";
		else if (iRR > pow(ADistance + BDistance, 2))
			cout << 0 << "\n";
		else if (iRR == pow(ADistance + BDistance, 2))
			cout << 1 << "\n";
		else if (iRR == pow(iLong - iShort, 2))
			cout << 1 << "\n";
		else if (iRR < pow(iLong - iShort, 2))
			cout << 0 << "\n";
		else 
			cout << 2 << "\n";

	}

	return 0;
}
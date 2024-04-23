#include <iostream>

using namespace std;

struct Point
{
	double iX;
	double iY;
};

int main()
{
	Point PArr[3];

	for (int i = 0; i < 3; ++i)
	{
		cin >> PArr[i].iX >> PArr[i].iY;
	}

	int iCCW = ((PArr[0].iX * PArr[1].iY) + (PArr[1].iX * PArr[2].iY) + (PArr[2].iX * PArr[0].iY)) - ((PArr[1].iX * PArr[0].iY) + (PArr[2].iX * PArr[1].iY) + (PArr[0].iX * PArr[2].iY));

	if (0 > iCCW)
		cout << -1;
	else if (0 == iCCW)
		cout << 0;
	else 
		cout << 1;

	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int iX = 0;
	int iCount = 1;
	cin >> iX;

	while (iX>1)
	{
		if (iX % 2 == 1)
		{
			iCount += 1;
		}
		iX = iX / 2;
	}

	cout << iCount;
}
#include <iostream>

using namespace std;

/*
0 : 1 ~ 1
1 : 2 ~ 7 : +1 ~ +6
2 : 8 ~ 19  : +6 ~ +12
3 : 20 ~ 37  : +12 ~ +18
4 : 38 ~ 61  : +18 ~ +24


*/



int main()
{
	int iNowRow = 0;
	int iStart = 1;
	int iEnd = 1;

	int iInput = 0;

	cin >> iInput;

	while (iInput > iEnd)
	{
		iStart += 6 * (iNowRow);
		iEnd += 6 * (iNowRow + 1);
		if (iNowRow == 0)
			iStart = 2;
		++iNowRow;
	}

	cout << iNowRow + 1;

    return 0;
}
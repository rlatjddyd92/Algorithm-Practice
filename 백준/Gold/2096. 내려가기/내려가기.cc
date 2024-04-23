#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int iLine = 0;

	vector<int> vecDpMax(3);
	vector<int> vecInputMax(3);
	vector<int> vecDpMin(3);
	vector<int> vecInputMin(3);

	cin >> iLine;

	for (int i = 0;i < iLine;++i)
	{
		int iFirst = 0;
		int iSecond = 0;
		int iThird = 0;

		cin >> iFirst >> iSecond >> iThird;

		vecInputMax[0] = iFirst + max(vecDpMax[0], vecDpMax[1]);
		vecInputMax[1] = iSecond + max(vecDpMax[0], max(vecDpMax[1], vecDpMax[2]));
		vecInputMax[2] = iThird + max(vecDpMax[1], vecDpMax[2]);

		for (int j = 0; j < 3;++j)
			vecDpMax[j] = vecInputMax[j];

		vecInputMin[0] = iFirst + min(vecDpMin[0], vecDpMin[1]);
		vecInputMin[1] = iSecond + min(vecDpMin[0], min(vecDpMin[1], vecDpMin[2]));
		vecInputMin[2] = iThird + min(vecDpMin[1], vecDpMin[2]);

		for (int j = 0; j < 3;++j)
			vecDpMin[j] = vecInputMin[j];
	}

	cout << max(vecInputMax[0], max(vecInputMax[1], vecInputMax[2])) <<" "<< min(vecInputMin[0], min(vecInputMin[1], vecInputMin[2]));

	vecDpMax.clear();
	vecInputMax.clear();
	vecDpMin.clear();
	vecInputMin.clear();

	vector<int>().swap(vecDpMax);
	vector<int>().swap(vecInputMax);
	vector<int>().swap(vecDpMin);
	vector<int>().swap(vecInputMin);

	return 0;
}
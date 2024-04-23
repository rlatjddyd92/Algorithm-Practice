#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int iNum = 0;
	int iGoal = 0;
	int iStart = 0;
	int iEnd = 0;
	int iSum = 0;
	int iAnswer = 0;

	cin >> iNum >> iGoal;

	vector<int> vecNum;
	vecNum.resize(iNum);

	for (int i = 0; i < iNum; ++i)
		cin >> vecNum[i];

	iSum = vecNum[0];

	while (1)
	{
		if (iSum >= iGoal)
		{
			if (!iAnswer)
				iAnswer = (iEnd - iStart) + 1;
			else
				iAnswer = min(iAnswer, (iEnd - iStart) + 1);

			iSum -= vecNum[iStart];
			++iStart;
		}
		else
		{
			++iEnd;
			if (iEnd == iNum) { break; }
			iSum += vecNum[iEnd];
		}
	}

	cout << iAnswer;

	vecNum.clear();

	return 0;
}
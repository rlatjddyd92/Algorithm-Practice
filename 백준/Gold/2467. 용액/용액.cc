#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Answer
{
	int iLow;
	int iHigh;
	int iResult;
};

int main()
{
	int iNum = 0;

	vector<int> vecMinus;
	vector<int> vecPlus;

	Answer Answer = { 0,0,0 };

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		if (iInput < 0)
			vecMinus.push_back(iInput);
		else
			vecPlus.push_back(iInput);
	}

	if ((vecMinus.size() > 0) && (vecPlus.size() > 0))
	{
		for (int i = 0; i < vecMinus.size(); ++i)
		{
			int iIndex = lower_bound(vecPlus.begin(), vecPlus.end(), -vecMinus[i]) - vecPlus.begin();
			int iSum = 0;

			if (iIndex == vecPlus.size())
				--iIndex;
			else if (iIndex)
				if (abs(vecMinus[i] + vecPlus[iIndex]) > abs(vecMinus[i] + vecPlus[iIndex - 1]))
					--iIndex;

			iSum = abs(vecMinus[i] + vecPlus[iIndex]);

			if ((Answer.iHigh != 0) && (Answer.iResult < iSum))
				continue;

			Answer = { vecMinus[i] , vecPlus[iIndex] , iSum };
		}

		for (int i = 0; i < vecPlus.size(); ++i)
		{
			int iIndex = lower_bound(vecMinus.begin(), vecMinus.end(), -vecPlus[i]) - vecMinus.begin();
			int iSum = 0;

			if (iIndex == vecMinus.size())
				--iIndex;
			else if (iIndex)
				if (abs(vecPlus[i] + vecMinus[iIndex]) > abs(vecPlus[i] + vecMinus[iIndex - 1]))
					--iIndex;

			iSum = abs(vecPlus[i] + vecMinus[iIndex]);

			if ((Answer.iHigh != 0) && (Answer.iResult < iSum))
				continue;

			Answer = { vecMinus[iIndex], vecPlus[i] ,iSum };
		}

		if (vecMinus.size() > 1)
			if (abs(Answer.iResult) > abs(vecMinus[vecMinus.size() - 2] + vecMinus[vecMinus.size() - 1]))
				Answer = { vecMinus[vecMinus.size() - 2] , vecMinus[vecMinus.size() - 1] };

		if (vecPlus.size() > 1)
			if (abs(Answer.iResult) > abs(vecPlus[0] + vecPlus[1]))
				Answer = { vecPlus[0] , vecPlus[1] };
	}
	else
	{
		if (vecMinus.size() > 1)
			Answer = { vecMinus[vecMinus.size() - 2] , vecMinus[vecMinus.size() - 1], abs(vecMinus[vecMinus.size() - 2] + vecMinus[vecMinus.size() - 1]) };

		if (vecPlus.size() > 1)
			Answer = { vecPlus[0] , vecPlus[1], abs(vecPlus[0] + vecPlus[1])};
	}

	cout << Answer.iLow << " " << Answer.iHigh;

	vecMinus.clear();
	vecPlus.clear();

	return 0;
}
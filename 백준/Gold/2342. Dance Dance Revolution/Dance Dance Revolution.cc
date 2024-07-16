#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define CENTER 0
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4

using namespace std;

struct STEP
{
	int iLeft;
	int iRight;
	int iSum;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStep[5][5] = { 0, };
	int iVisit[5][5] = { 0, };

	queue<STEP> queueStep;
	queueStep.push({ 0,0,0 });
	int iNowVisit = 1;
	while (1)
	{
		int iInput = 0;
		cin >> iInput;
		if (iInput == 0)
			break;

		int iCount = queueStep.size();
		//cout << iCount << "\n";

		for (int i = 0; i < iCount ; ++i)
		{
			int iNowR = queueStep.front().iRight;
			int iNowL = queueStep.front().iLeft;
			int iNowSum = queueStep.front().iSum;
			queueStep.pop();

			if (iInput != iNowL)
			{
				int iCostR = 0;
				if (iNowR == 0)
					iCostR = 2;
				else if (abs(iNowR - iInput) == 2)
					iCostR = 4;
				else if (iNowR == iInput)
					iCostR = 1;
				else 
					iCostR = 3;

				if ((iVisit[iInput][iNowL] < iNowVisit) || (iStep[iInput][iNowL] > iNowSum + iCostR))
				{
					iStep[iInput][iNowL] = iNowSum + iCostR;
					iVisit[iInput][iNowL] = iNowVisit;
				}
			}

			if (iInput != iNowR)
			{
				int iCostL = 0;
				if (iNowL == 0)
					iCostL = 2;
				else if (abs(iNowL - iInput) == 2)
					iCostL = 4;
				else if (iNowL == iInput)
					iCostL = 1;
				else
					iCostL = 3;

				if ((iVisit[iNowR][iInput] < iNowVisit) || (iStep[iNowR][iInput] > iNowSum + iCostL))
				{
					iStep[iNowR][iInput] = iNowSum + iCostL;
					iVisit[iNowR][iInput] = iNowVisit;
				}
			}
		}

		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				if (iVisit[i][j] == iNowVisit)
					queueStep.push({ i,j,iStep[i][j] });

		++iNowVisit;
	}

	int iAnswer = 0;

	while (!queueStep.empty())
	{
		if ((queueStep.front().iSum < iAnswer) || (iAnswer == 0))
			iAnswer = queueStep.front().iSum;

		queueStep.pop();
	}

	cout << iAnswer;

	return 0;
}
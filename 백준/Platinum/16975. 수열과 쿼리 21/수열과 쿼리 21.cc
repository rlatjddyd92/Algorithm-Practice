#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	int iMin;
	int iMax;
	long long llAdjust = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	cin >> iNum;

	vector<NODE> vecSeg;
	vector<long long> vecData;

	vecSeg.resize(iNum * 5);
	vecData.resize(iNum + 1);

	for (int i = 1; i <= iNum; ++i)
		cin >> vecData[i];

	queue<int> queueNext;
	queueNext.push(1);
	vecSeg[1].iMin = 1;
	vecSeg[1].iMax = iNum;

	while (!queueNext.empty())
	{
		int iNow = queueNext.front();
		queueNext.pop();

		if (vecSeg[iNow].iMin == vecSeg[iNow].iMax)
			continue;

		int iNext = iNow * 2;
		int iGap = (vecSeg[iNow].iMax - vecSeg[iNow].iMin) / 2;

		vecSeg[iNext].iMin = vecSeg[iNow].iMin;
		vecSeg[iNext].iMax = vecSeg[iNow].iMin + iGap;
		queueNext.push(iNext);
		++iNext;
		vecSeg[iNext].iMin = vecSeg[iNow].iMin + iGap + 1;
		vecSeg[iNext].iMax = vecSeg[iNow].iMax;
		queueNext.push(iNext);
	}

	int iQuery = 0;
	cin >> iQuery;

	for (int i = 0; i < iQuery; ++i)
	{
		int iOrder = 0;
		cin >> iOrder;

		if (iOrder == 1)
		{
			int iInput[3] = { 0,0,0 };
			cin >> iInput[0] >> iInput[1] >> iInput[2];

			queue<int> queueNext;
			queueNext.push(1);

			while (!queueNext.empty())
			{
				int iNow = queueNext.front();
				queueNext.pop();

				if ((vecSeg[iNow].iMin >= iInput[0]) && (vecSeg[iNow].iMax <= iInput[1]))
					vecSeg[iNow].llAdjust += iInput[2];
				else if ((vecSeg[iNow].iMin > iInput[1]) || (vecSeg[iNow].iMax < iInput[0]))
					continue;
				else
				{
					queueNext.push(iNow * 2);
					queueNext.push((iNow * 2) + 1);
				}
			}
		}
		else
		{
			int iInput = 0;
			cin >> iInput;

			int iNow = 1;
			long long iAnswer = 0;

			while (1)
			{
				iAnswer += vecSeg[iNow].llAdjust;
				if (vecSeg[iNow].iMax == vecSeg[iNow].iMin)
				{
					cout << vecData[vecSeg[iNow].iMax] + iAnswer << "\n";
					break;
				}
			
				if ((vecSeg[iNow].iMin + ((vecSeg[iNow].iMax - vecSeg[iNow].iMin) / 2)) < iInput)
					iNow = (iNow * 2) + 1;
				else 
					iNow *= 2;
			}
		}
	}

	vecSeg.clear();
	vecData.clear();

	return 0;
}
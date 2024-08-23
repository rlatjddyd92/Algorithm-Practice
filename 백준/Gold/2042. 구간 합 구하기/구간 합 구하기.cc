#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	long long iIndex_Seg;
	long long iIndex_Data_Min = 0;
	long long iIndex_Data_Max = 0;
	long long llAnswer = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;
	long long iWrite = 0;
	long long iQuery = 0;

	cin >> iNum >> iWrite >> iQuery;

	queue<NODE> queueDown;
	queue<NODE> queueUp;

	vector<NODE> vecSeg;
	vector<NODE> vecData;

	vecSeg.resize(iNum * 5);
	vecData.resize(iNum + 1);

	queueDown.push({ 1,1,iNum ,0 });

	while (!queueDown.empty())
	{
		NODE tNow = queueDown.front();
		vecSeg[tNow.iIndex_Seg] = tNow;
		queueDown.pop();

		if (tNow.iIndex_Data_Min == tNow.iIndex_Data_Max)
			queueUp.push(tNow);
		else
		{
			long long iNext = tNow.iIndex_Seg * 2;
			long long iGap = (tNow.iIndex_Data_Max - tNow.iIndex_Data_Min) / 2;

			queueDown.push({ iNext ,tNow.iIndex_Data_Min, tNow.iIndex_Data_Min + iGap, 0 });
			queueDown.push({ iNext + 1,tNow.iIndex_Data_Min + iGap + 1, tNow.iIndex_Data_Max, 0 });
		}
	}

	for (long long i = 1; i <= iNum; ++i)
	{
		long long llInput = 0;
		cin >> llInput;
		vecData[i].llAnswer = llInput;
	}
		

	while (!queueUp.empty())
	{
		NODE tNow = queueUp.front();
		queueUp.pop();

		if (vecSeg[tNow.iIndex_Seg].iIndex_Data_Min == vecSeg[tNow.iIndex_Seg].iIndex_Data_Max)
		{
			tNow.llAnswer = vecData[tNow.iIndex_Data_Min].llAnswer;
			vecData[tNow.iIndex_Data_Min].iIndex_Seg = tNow.iIndex_Seg;
			vecSeg[tNow.iIndex_Seg].llAnswer = tNow.llAnswer;
		}
		else
			tNow.llAnswer = vecSeg[tNow.iIndex_Seg].llAnswer;
			
		long long iNext = tNow.iIndex_Seg / 2;

		if (!iNext) continue;

		vecSeg[iNext].llAnswer += tNow.llAnswer;

		if ((tNow.iIndex_Seg % 2 == 0) || ((tNow.iIndex_Seg % 2 == 1) && (vecSeg[tNow.iIndex_Seg - 1].iIndex_Data_Min == 0)))
			queueUp.push({ iNext ,tNow.iIndex_Data_Min, tNow.iIndex_Data_Max, tNow.llAnswer });
	}

	for (long long i = 0; i < iWrite + iQuery; ++i)
	{
		long long iInput[3] = { 0,0,0 };
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 1)
		{
			long long iNow = vecData[iInput[1]].iIndex_Seg;
			long long iGap = iInput[2] - vecData[iInput[1]].llAnswer;
			vecData[iInput[1]].llAnswer += iGap;

			while (iNow)
			{
				vecSeg[iNow].llAnswer += iGap;
				iNow /= 2;
			}
		}
		else
		{
			queue<long long> queueNext;
			queueNext.push(1);

			long long iAnswer = 0;

			while (!queueNext.empty())
			{
				long long iNow = queueNext.front();
				queueNext.pop();

				if ((vecSeg[iNow].iIndex_Data_Min >= iInput[1]) && (vecSeg[iNow].iIndex_Data_Max <= iInput[2]))
					iAnswer += vecSeg[iNow].llAnswer;
				else if ((vecSeg[iNow].iIndex_Data_Min > iInput[2]) || (vecSeg[iNow].iIndex_Data_Max < iInput[1]))
					continue;
				else 
				{
					queueNext.push(iNow * 2);
					queueNext.push((iNow * 2) + 1);
				}
					
			}

			cout << iAnswer << "\n";
		}
	}

	vecSeg.clear();
	vecData.clear();

	return 0;
}
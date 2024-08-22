#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	long long iIndex_Seg;
	long long iIndex_Data_Min;
	long long iIndex_Data_Max;
	long long iAnswer = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iDays = 0;
	long long iQuery = 0;
	cin >> iDays >> iQuery;

	vector<NODE> vecData;
	vector<NODE> vecSeg;

	vecData.resize(iDays + 1);
	vecSeg.resize(iDays * 5);

	queue<NODE> queueMake;
	queueMake.push({ 1,1,iDays ,0 });

	while (!queueMake.empty())
	{
		NODE tNow = queueMake.front();
		vecSeg[tNow.iIndex_Seg] = tNow;
		queueMake.pop();

		if (tNow.iIndex_Data_Min == tNow.iIndex_Data_Max)
		{
			vecData[tNow.iIndex_Data_Min].iIndex_Seg = tNow.iIndex_Seg;
			continue;
		}

		long long iNext = tNow.iIndex_Seg * 2;
		long long iGap = (tNow.iIndex_Data_Max - tNow.iIndex_Data_Min) / 2;

		queueMake.push({ iNext , tNow.iIndex_Data_Min , tNow.iIndex_Data_Min + iGap , 0 });
		queueMake.push({ iNext+1 , tNow.iIndex_Data_Min + iGap + 1 ,  tNow.iIndex_Data_Max, 0 });
	}

	for (long long i = 0; i < iQuery; ++i)
	{
		long long iOrder = 0;
		long long iInput[2] = { 0,0 };

		cin >> iOrder >> iInput[0] >> iInput[1];

		if (iOrder == 1)
		{
			long long iNow = 1;
			vecData[iInput[0]].iAnswer = iInput[1];

			while ((vecSeg[iNow].iIndex_Data_Min == iInput[0]) + (vecSeg[iNow].iIndex_Data_Max == iInput[0]) < 2)
			{
				vecSeg[iNow].iAnswer += iInput[1];
				if ((vecSeg[iNow].iIndex_Data_Min + (vecSeg[iNow].iIndex_Data_Max - vecSeg[iNow].iIndex_Data_Min) / 2) < iInput[0])
					iNow = (iNow * 2) + 1;
				else
					iNow = (iNow * 2);
			}
			vecSeg[iNow].iAnswer += iInput[1];
		}
		else
		{
			queue<long long> queueSerach;
			queueSerach.push(1);
			long long iAnswer = 0;

			while (!queueSerach.empty())
			{
				long long iNow = queueSerach.front();
				queueSerach.pop();

				if ((vecSeg[iNow].iIndex_Data_Min > iInput[1]) || (vecSeg[iNow].iIndex_Data_Max < iInput[0]))
					continue;
				if ((vecSeg[iNow].iIndex_Data_Min >= iInput[0]) && (vecSeg[iNow].iIndex_Data_Max <= iInput[1]))
					iAnswer += vecSeg[iNow].iAnswer;
				else
				{
					queueSerach.push(iNow * 2);
					queueSerach.push((iNow * 2) + 1);
				}
			}

			cout << iAnswer << "\n";
		}
	}

	vecData.clear();
	vecSeg.clear();

	return 0;
}
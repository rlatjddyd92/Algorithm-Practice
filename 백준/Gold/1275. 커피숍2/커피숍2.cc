#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	long long iIndex_Seg;
	long long iIndex_Data_Min = 0;
	long long iIndex_Data_Max = 0;
	long long iAnswer;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;
	long long iQuery = 0;

	cin >> iNum >> iQuery;

	vector<NODE> vecSeg;
	vector<NODE> vecData;
	vecSeg.resize(iNum * 5);
	vecData.resize(iNum + 1);

	for (long long i = 1; i <= iNum; ++i)
		cin >> vecData[i].iAnswer;

	queue<NODE> queueDown;
	queue<long long> queueUp;

	queueDown.push({ 1,1,iNum, 0 });

	while (!queueDown.empty())
	{
		NODE tNow = queueDown.front();
		vecSeg[tNow.iIndex_Seg] = tNow;
		queueDown.pop();

		if (tNow.iIndex_Data_Min == tNow.iIndex_Data_Max)
		{
			vecSeg[tNow.iIndex_Seg].iAnswer = vecData[tNow.iIndex_Data_Min].iAnswer;
			vecData[tNow.iIndex_Data_Min].iIndex_Seg = tNow.iIndex_Seg;
			queueUp.push(tNow.iIndex_Seg);
		}
		else
		{
			long long iNext = tNow.iIndex_Seg * 2;
			long long iGap = (tNow.iIndex_Data_Max - tNow.iIndex_Data_Min) / 2;

			queueDown.push({ iNext , tNow.iIndex_Data_Min , tNow.iIndex_Data_Min + iGap , 0 });
			queueDown.push({ iNext + 1 , tNow.iIndex_Data_Min + iGap + 1, tNow.iIndex_Data_Max , 0 });
		}
	}

	while (!queueUp.empty())
	{
		long long iNow = queueUp.front();
		queueUp.pop();

		if ((iNow % 2 == 0) && (iNow > 1))
			queueUp.push(iNow / 2);

		vecSeg[iNow / 2].iAnswer += vecSeg[iNow].iAnswer;
	}

	for (long long i = 0; i < iQuery; ++i)
	{
		long long iInput[4] = { 0, };
		for (long long j = 0; j < 4; ++j)
			cin >> iInput[j];

		if (iInput[0] > iInput[1])
		{
			long long iTemp = iInput[0];
			iInput[0] = iInput[1];
			iInput[1] = iTemp;
		}

		queue<long long> queueSearch;
		queueSearch.push(1);
		long long iAnswer = 0;

		while (!queueSearch.empty())
		{
			long long iNow = queueSearch.front();
			queueSearch.pop();

			if ((vecSeg[iNow].iIndex_Data_Min >= iInput[0]) && (vecSeg[iNow].iIndex_Data_Max <= iInput[1]))
				iAnswer += vecSeg[iNow].iAnswer;
			else if ((vecSeg[iNow].iIndex_Data_Min > iInput[1]) || (vecSeg[iNow].iIndex_Data_Max < iInput[0]))
				continue;
			else
			{
				queueSearch.push(iNow * 2);
				queueSearch.push((iNow * 2) + 1);
			}
		}

		cout << iAnswer << "\n";

		long long iNow = vecData[iInput[2]].iIndex_Seg;
		long long iGap = iInput[3] - vecData[iInput[2]].iAnswer;
		vecData[iInput[2]].iAnswer += iGap;

		while (iNow > 0)
		{
			vecSeg[iNow].iAnswer += iGap;
			iNow /= 2;
		}
	}

	vecSeg.clear();
	vecData.clear();

	return 0;
}
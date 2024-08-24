#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	int iIndex_Seg;
	int iIndex_Data_Min;
	int iIndex_Data_Max;
	long long llAnswer = 1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iChange = 0;
	int iQuery = 0;

	vector<NODE> vecData;
	vector<NODE> vecSeg;

	cin >> iNum >> iChange >> iQuery;

	vecData.resize(iNum + 1);
	vecSeg.resize(iNum * 5);

	for (int i = 1; i <= iNum; ++i)
		cin >> vecData[i].llAnswer;

	queue<NODE> queueDown;
	queue<int> queueUp;

	queueDown.push({ 1,1,iNum,1 });

	while (!queueDown.empty())
	{
		NODE tNow = queueDown.front();
		queueDown.pop();
		vecSeg[tNow.iIndex_Seg] = tNow;

		if (tNow.iIndex_Data_Min == tNow.iIndex_Data_Max)
		{
			tNow.llAnswer = vecData[tNow.iIndex_Data_Min].llAnswer;
			vecData[tNow.iIndex_Data_Min].iIndex_Seg = tNow.iIndex_Seg;
			vecSeg[tNow.iIndex_Seg].llAnswer = tNow.llAnswer;
			queueUp.push(tNow.iIndex_Seg);
		}
		else
		{
			int iNext = tNow.iIndex_Seg * 2;
			int iGap = (tNow.iIndex_Data_Max - tNow.iIndex_Data_Min) / 2;

			queueDown.push({ iNext ,  tNow.iIndex_Data_Min ,  tNow.iIndex_Data_Min + iGap , 1 });
			queueDown.push({ iNext + 1 , tNow.iIndex_Data_Min + iGap + 1 ,  tNow.iIndex_Data_Max , 1 });
		}
	}

	while (!queueUp.empty())
	{
		int iNow = queueUp.front();
		queueUp.pop();

		if (iNow / 2 == 0) continue;
		
		vecSeg[iNow / 2].llAnswer *= vecSeg[iNow].llAnswer;
		vecSeg[iNow / 2].llAnswer %= (long long)1000000007;

		if ((iNow % 2 == 0) || ((iNow % 2 == 1) && (vecSeg[iNow - 1].iIndex_Data_Min == 0)))
			queueUp.push(iNow / 2);
	}

	for (int i = 0; i < iChange + iQuery; ++i)
	{
		int iInput[3] = { 0,0,0 };
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 1)
		{
			int iNow = vecData[iInput[1]].iIndex_Seg;
			long long iValue = iInput[2];

			while (iNow > 0)
			{
				vecSeg[iNow].llAnswer = iValue;
				if ((iNow % 2 == 0) && (vecSeg[iNow + 1].iIndex_Data_Min != 0))
					iValue *= vecSeg[iNow + 1].llAnswer;
				else if ((iNow % 2 == 1) && (vecSeg[iNow - 1].iIndex_Data_Min != 0))
					iValue *= vecSeg[iNow - 1].llAnswer;

				iValue %= (long long)1000000007;

				iNow /= 2;
			}
		}
		else
		{
			queue<int> queueSearch;
			queueSearch.push(1);
			long long iAnswer = 1;

			while (!queueSearch.empty())
			{
				int iNow = queueSearch.front();
				queueSearch.pop();

				if ((vecSeg[iNow].iIndex_Data_Min >= iInput[1]) && (vecSeg[iNow].iIndex_Data_Max <= iInput[2]))
				{
					iAnswer *= vecSeg[iNow].llAnswer;
					iAnswer %= (long long)1000000007;
				}
				else if ((vecSeg[iNow].iIndex_Data_Min > iInput[2]) || (vecSeg[iNow].iIndex_Data_Max < iInput[1]))
					continue;
				else
				{
					queueSearch.push(iNow * 2);
					queueSearch.push((iNow * 2) + 1);
				}
			}
			iAnswer %= (long long)1000000007;
			cout << iAnswer << "\n";
		}
	}

	vecData.clear();
	vecSeg.clear();

	return 0;
}
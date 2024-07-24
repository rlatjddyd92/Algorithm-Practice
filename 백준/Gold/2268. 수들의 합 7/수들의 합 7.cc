#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct SEG
{
	long long iIndex;
	long long iStart;
	long long iEnd;
	long long iSum;
};

long long CheckSum(vector<SEG>& vecSegment, long long iStart, long long iEnd);
void ModifyNum(vector<SEG>* pSeg, long long iIndex, long long iNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;
	long long iCom = 0;

	cin >> iNum >> iCom;

	long long iMax = 1;

	while (iMax < iNum)
		iMax *= 4;

	iMax *= 2;
	++iMax;

	vector<SEG> vecSeg;
	vecSeg.resize(iMax);

	queue<SEG> queueMake;
	queueMake.push({ 1, 1,iNum,0 });

	while (!queueMake.empty())
	{
		SEG tTemp = queueMake.front();
		queueMake.pop();
		vecSeg[tTemp.iIndex] = tTemp;

		if (tTemp.iStart != tTemp.iEnd)
		{
			long long iHarf = (tTemp.iEnd - tTemp.iStart) / 2;
			queueMake.push({ tTemp.iIndex * 2,tTemp.iStart, tTemp.iStart + iHarf, 0 });
			queueMake.push({ (tTemp.iIndex * 2) + 1,(tTemp.iStart + iHarf) + 1, tTemp.iEnd, 0 });
		}
	}

	for (long long i = 0; i < iCom; ++i)
	{
		long long iInput[3] = {0,};

		for (long long j = 0; j < 3; ++j)
			cin >> iInput[j];

		if (iInput[0] == 0)
		{
			if (iInput[1] <= iInput[2])
				cout << CheckSum(vecSeg, iInput[1], iInput[2]) << "\n";
			else
				cout << CheckSum(vecSeg, iInput[2], iInput[1]) << "\n";
		}
			
		else
			ModifyNum(&vecSeg, iInput[1], iInput[2]);
	}

	vecSeg.clear();

	return 0;
}

long long CheckSum(vector<SEG>& vecSegment, long long iStart, long long iEnd)
{
	long long iSum = 0;
	vector<SEG>::iterator iter = vecSegment.begin();

	queue<long long> queueIndex;
	queueIndex.push(1);

	while (!queueIndex.empty())
	{
		long long iNow = queueIndex.front();
		queueIndex.pop();

		if (((iter + iNow)->iStart >= iStart) && ((iter + iNow)->iEnd <= iEnd))
			iSum += (iter + iNow)->iSum;
		else if (((iter + iNow)->iStart <= iEnd) && ((iter + iNow)->iEnd >= iStart))
		{
			queueIndex.push(iNow * 2);
			queueIndex.push((iNow * 2) + 1);
		}
	}

	return iSum;
}

void ModifyNum(vector<SEG>* pSeg, long long iIndex, long long iNum)
{
	long long iNow = 1;
	vector<SEG>::iterator iter = pSeg->begin();

	while (((iter + iNow)->iStart != iIndex) || ((iter + iNow)->iEnd != iIndex))
	{
		iNow *= 2;
		if ((iter + iNow)->iEnd < iIndex)
			++iNow;
	}

	long long iGap = iNum - (iter + iNow)->iSum;
	(iter + iNow)->iSum += iGap;

	while (iNow > 1)
	{
		iNow /= 2;
		(iter + iNow)->iSum += iGap;
	}
}

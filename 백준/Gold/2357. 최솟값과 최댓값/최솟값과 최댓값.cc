#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
	int iIndex;
	int iStart;
	int iEnd;
	int iMin;
	int iMax;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iCommand = 0;

	cin >> iNum >> iCommand;

	vector<int> vecNum;
	vector<NODE> vecNode;

	int iNodNum = 1;

	while (iNodNum < iNum)
		iNodNum *= 2;

	vecNum.resize(iNum);
	vecNode.resize(iNodNum * 2);

	int iAllMin = 0;
	int iAllMax = 0;

	for (int i = 0; i < iNum; ++i)
	{
		cin >> vecNum[i];
		if (vecNum[i] > iAllMax)
			iAllMax = vecNum[i];
		
		if ((iAllMin == 0) || (iAllMin > vecNum[i]))
			iAllMin = vecNum[i];
	}
		

	queue<NODE> queueNode;
	queueNode.push({ 1,0,iNum - 1,0 , 0 });

	queue<NODE> queueAnswer;

	while (!queueNode.empty())
	{
		NODE tNow = queueNode.front();
		queueNode.pop();

		vecNode[tNow.iIndex] = tNow;

		if (tNow.iStart == tNow.iEnd)
		{
			queueAnswer.push({ tNow.iIndex,-1,-1,vecNum[tNow.iStart],vecNum[tNow.iStart] });
		}
		else
		{
			int iHarf = (tNow.iEnd - tNow.iStart) / 2;

			queueNode.push({ tNow.iIndex * 2, tNow.iStart ,tNow.iStart + iHarf, 0,0 });
			queueNode.push({ tNow.iIndex * 2 + 1, tNow.iStart + iHarf + 1 , tNow.iEnd, 0,0 });
		}
	}

	while (!queueAnswer.empty())
	{
		NODE tNow = queueAnswer.front();
		queueAnswer.pop();

		if ((vecNode[tNow.iIndex].iMin == 0) || (vecNode[tNow.iIndex].iMin > tNow.iMin))
			vecNode[tNow.iIndex].iMin = tNow.iMin;

		if (vecNode[tNow.iIndex].iMax < tNow.iMax)
			vecNode[tNow.iIndex].iMax = tNow.iMax;

		if (tNow.iIndex != 1)
			queueAnswer.push({ tNow.iIndex / 2,-1,-1,vecNode[tNow.iIndex].iMin,vecNode[tNow.iIndex].iMax});
	}

	for (int i = 0; i < iCommand; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iMin = 0;
		int iMax = 0;

		cin >> iStart >> iEnd;

		--iStart;
		--iEnd;

		queue<int> queueSerach; 
		queueSerach.push(1);
		
		while (!queueSerach.empty())
		{
			int iNow = queueSerach.front();
			queueSerach.pop();

			if ((vecNode[iNow].iStart > iEnd) || (vecNode[iNow].iEnd < iStart))
				continue;
			else if ((vecNode[iNow].iStart >= iStart) && (vecNode[iNow].iEnd <= iEnd))
			{
				if ((iMin == 0) || (vecNode[iNow].iMin < iMin))
					iMin = vecNode[iNow].iMin;

				if (vecNode[iNow].iMax > iMax)
					iMax = vecNode[iNow].iMax;
			}
			else
			{
				queueSerach.push(iNow * 2);
				queueSerach.push(iNow * 2 + 1);
			}
		}

		cout << iMin << " "<< iMax << "\n";
	}

	vecNum.clear();
	vecNode.clear();

	return 0;
}
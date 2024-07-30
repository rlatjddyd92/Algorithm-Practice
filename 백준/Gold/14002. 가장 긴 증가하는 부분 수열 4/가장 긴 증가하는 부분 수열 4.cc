#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct NUMBER
{
	int iNum;
	int iBefore;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iCount = 0;

	cin >> iNum;

	vector<NUMBER> vecNum;
	vector<NUMBER> vecLIS;
	vecNum.resize(iNum + 1);
	vecLIS.resize(iNum + 1);

	for (int i = 1; i <= iNum; ++i)
		cin >> vecNum[i].iNum;

	for (int i = 1; i <= iNum; ++i)
	{
		int iIndex = lower_bound(vecLIS.begin(), vecLIS.begin() + iCount, vecNum[i].iNum, [](NUMBER tNow, int iNow) {return tNow.iNum < iNow; }) - vecLIS.begin();

		if (vecLIS[iIndex].iNum < vecNum[i].iNum)
		{
			++iIndex;
			++iCount;
		}
			

		vecNum[i].iBefore = vecLIS[iIndex - 1].iBefore;
		vecLIS[iIndex] = { vecNum[i].iNum ,i };
	}

	stack<int> stackAnswer;
	int iNext = vecLIS[iCount].iBefore;
	while (iNext != 0)
	{
		stackAnswer.push({ vecNum[iNext].iNum });
		iNext = vecNum[iNext].iBefore;
	}

	cout << iCount << "\n";

	while (!stackAnswer.empty())
	{
		cout << stackAnswer.top() << " ";
		stackAnswer.pop();
	}

	vecNum.clear();
	vecLIS.clear();

	return 0;
}
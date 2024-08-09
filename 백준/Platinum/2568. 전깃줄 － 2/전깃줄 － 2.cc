#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct NUMBER
{
	int iNum;
	int iIndex;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iPole = 0;

	cin >> iPole;

	vector<NUMBER> vecInput;
	vector<int> vecLis;
	vector<int> vecBefore;
	vecInput.resize(500001);
	vecLis.resize(iPole + 3);
	vecBefore.resize(iPole + 3);

	int iIndex = 0;

	for (int i = 1; i <= iPole; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		cin >> iStart >> iEnd;
		vecInput[iStart].iNum = iEnd;
	}

	for (int i = 1; i < 500001; ++i)
	{
		if (vecInput[i].iNum == 0) continue;

		int iNow = lower_bound(vecLis.begin(), vecLis.begin() + iIndex, vecInput[i].iNum) - vecLis.begin();
		if (iNow > 0)
			vecInput[i].iIndex = vecBefore[iNow - 1];
		vecLis[iNow] = vecInput[i].iNum;
		vecBefore[iNow] = i;
		if (iNow == iIndex)
			++iIndex;
	}

	cout << iPole - iIndex << "\n";

	if ((iIndex > 0) && (vecLis[iIndex] == 0))
		--iIndex;

	stack<int> stackAnswer;
	int iNext = vecBefore[iIndex];
	stackAnswer.push(iNext);

	while (vecInput[iNext].iIndex != 0)
	{
		stackAnswer.push(vecInput[iNext].iIndex);
		iNext = vecInput[iNext].iIndex;
	}

	for (int i = 1; i < 500001; ++i)
	{
		if (iPole <= 0)
			break;

		if ((!stackAnswer.empty()) && (i == stackAnswer.top()))
		{
			--iPole;
			stackAnswer.pop();
		}
		else if (vecInput[i].iNum != 0)
		{
			--iPole;
			cout << i << "\n";
		}
			

		
	}

	vecInput.clear();
	vecLis.clear();
	vecBefore.clear();

	return 0;
}
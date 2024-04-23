#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Number
{
	int iBeforeIndex;
	int iNumber;
	int iNextIndex;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iLastIndex = 0;

	cin >> iNum;

	vector<Number> vecNum;
	vector<int> vecLIS;
	vector<int> vecIndex;
	vecNum.resize(iNum + 1);
	vecNum[0] = { 0,0 };
	vecLIS.push_back(0);
	vecIndex.push_back(0);

	for (int i = 1; i <= iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		vecNum[i].iNumber = iInput;

		int iIndex = 0;

		if (i == 1)
			iIndex = 1;
		else
			iIndex = upper_bound(vecLIS.begin() + 1, vecLIS.end(), iInput) - vecLIS.begin();

		if (iIndex == vecLIS.size())
		{
			if (vecLIS[iIndex-1] == iInput) continue;

			vecLIS.push_back(iInput);
			vecIndex.push_back(i);
		}
		else if ((iIndex == 1) || (vecLIS[iIndex-1] < iInput))
		{
			vecLIS[iIndex] = iInput;
			vecIndex[iIndex] = i;
		}
		else
			continue;

		vecNum[vecIndex[iIndex]].iBeforeIndex = vecIndex[iIndex - 1];
	}

	cout << vecLIS.size() - 1 << "\n";

	int iNow = vecIndex.back();
	stack<int> AnswerStack;

	while (1)
	{
		AnswerStack.push(vecNum[iNow].iNumber);

		if (vecNum[iNow].iBeforeIndex)
			iNow = vecNum[iNow].iBeforeIndex;
		else
			break;
	}

	while (!AnswerStack.empty())
	{
		cout << AnswerStack.top() << " ";
		AnswerStack.pop();
	}

	
	vecNum.clear();
	vecLIS.clear();
	vecIndex.clear();

	return 0;
}
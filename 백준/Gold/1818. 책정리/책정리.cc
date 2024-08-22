#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	int iAnswer = 0;
	int iEnd = 1;
	vector<int> vecLIS;
	vecLIS.resize(iNum + 1);

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		int iIndex = lower_bound(vecLIS.begin(), vecLIS.begin() + iEnd, iInput) - vecLIS.begin();
		vecLIS[iIndex] = iInput;
		if (iIndex == iEnd)
			++iEnd;
		else
			++iAnswer;
	}

	cout << iAnswer;

	vecLIS.clear();

	return 0;
}
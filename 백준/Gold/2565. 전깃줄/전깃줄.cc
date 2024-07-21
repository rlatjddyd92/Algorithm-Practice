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

	vector<int> vecNum;
	vecNum.resize(501);

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		vecNum[iStart] = iEnd;
	}

	vector<int> vecLIS;
	vecLIS.push_back(0);

	for (int i = 0; i <= 500; ++i)
	{
		int iIndex = lower_bound(vecLIS.begin(), vecLIS.end(), vecNum[i]) - vecLIS.begin();

		if (iIndex >= vecLIS.size())
			vecLIS.push_back(vecNum[i]);
		else
			vecLIS[iIndex] = vecNum[i];
	}

	cout << iNum - vecLIS.size() + 1;

	vecNum.clear();
	vecLIS.clear();

	return 0;
}
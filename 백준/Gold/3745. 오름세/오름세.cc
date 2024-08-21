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

	while (cin >> iNum)
	{
		vector<int> vecLIS;
		vecLIS.resize(iNum + 1);
		int iEnd = 1;

		for (int i = 0; i < iNum; ++i)
		{
			int iInput = 0;
			cin >> iInput;

			int iIndex = lower_bound(vecLIS.begin(), vecLIS.begin() + iEnd, iInput) - vecLIS.begin();
			vecLIS[iIndex] = iInput;
			if (iIndex == iEnd)
				++iEnd;
		}

		cout << iEnd - 1 << "\n";

		vecLIS.clear();
	}

	return 0;
}
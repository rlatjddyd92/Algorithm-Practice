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
	int iIndex = 0;

	cin >> iNum;

	vector<int> vecLis;
	vecLis.resize(iNum + 2);

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		int iNow = lower_bound(vecLis.begin(), vecLis.begin() + iIndex, iInput) - vecLis.begin();
		vecLis[iNow] = iInput;
		if (iIndex == iNow)
			++iIndex;
	}

	if (vecLis[iIndex] == 0)
		--iIndex;

	cout << iIndex + 1;

	vecLis.clear();

	return 0;
}
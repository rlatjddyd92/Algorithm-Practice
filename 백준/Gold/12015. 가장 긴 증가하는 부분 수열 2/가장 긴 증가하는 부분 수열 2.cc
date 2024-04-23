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

	vector<int> vecLast;
	vecLast.resize(iNum);

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		if ((!iIndex) || (vecLast[iIndex-1] < iInput))
		{
			vecLast[iIndex] = iInput;
			++iIndex;
			continue;
		}

		vector<int>::iterator iter = lower_bound(vecLast.begin(), vecLast.begin() + iIndex, iInput);

		if (*iter == iInput)
			continue;

		*iter = iInput;
	}

	cout << iIndex;

	vecLast.clear();

	return 0;
}
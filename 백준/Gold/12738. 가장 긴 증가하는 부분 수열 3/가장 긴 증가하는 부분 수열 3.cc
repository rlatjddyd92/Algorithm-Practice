#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;

	cin >> iNum;

	vector<long long> vecLIS;
	vecLIS.push_back(-1000000001);

	for (long long i = 0; i < iNum; ++i)
	{
		long long iInput = 0;

		cin >> iInput;

		long long iIndex = lower_bound(vecLIS.begin(), vecLIS.end(), iInput) - vecLIS.begin();

		if (iIndex == vecLIS.size())
			vecLIS.push_back(iInput);
		else if (vecLIS[iIndex] > iInput)
			vecLIS[iIndex] = iInput;
	}

	cout << vecLIS.size() - 1;

	vecLIS.clear();

	return 0;
}
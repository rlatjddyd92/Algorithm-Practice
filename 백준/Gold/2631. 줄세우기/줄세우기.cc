#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecInput;
	vector<int> vecLIS;

	int iNumber = 0;

	cin >> iNumber;

	vecInput.resize(iNumber);
	vecLIS.push_back(0);

	for (int i = 0; i < iNumber; ++i)
		cin >> vecInput[i];

	for (int i = 0; i < iNumber; ++i)
	{
		int iIndex = lower_bound(vecLIS.begin(), vecLIS.end(), vecInput[i]) - vecLIS.begin();

		if (iIndex == vecLIS.size())
			vecLIS.push_back(vecInput[i]);
		else
			vecLIS[iIndex] = vecInput[i];
	}

	cout << iNumber - (vecLIS.size() - 1);

	vecInput.clear();
	vecLIS.clear();

	return 0;
}
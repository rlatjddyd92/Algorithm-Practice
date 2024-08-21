#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;
	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		vector<int> vecLIS;

		int iNum = 0;
		cin >> iNum;

		for (int j = 0; j < iNum; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			if (vecLIS.empty())
			{
				vecLIS.push_back(iInput);
				continue;
			}

			int iIndex = lower_bound(vecLIS.begin(), vecLIS.end(), iInput) - vecLIS.begin();
			if (iIndex == vecLIS.size())
				vecLIS.push_back(iInput);
			else
				vecLIS[iIndex] = iInput;
		}

		cout << vecLIS.size() << "\n";

		vecLIS.clear();
	}

	return 0;
}
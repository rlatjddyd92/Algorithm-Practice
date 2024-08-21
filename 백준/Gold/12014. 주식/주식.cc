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

	for (int i = 1; i <= iCase; ++i)
	{
		int iDays = 0;
		int iMin = 0;

		cin >> iDays >> iMin;

		vector<int> vecLIS;
		vecLIS.resize(iDays + 1);

		int iEnd = 1;

		for (int j = 0; j < iDays; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			int Iindex = lower_bound(vecLIS.begin(), vecLIS.begin() + iEnd, iInput) - vecLIS.begin();
			vecLIS[Iindex] = iInput;
			if (Iindex == iEnd)
				++iEnd;
		}

		cout << "Case #" << i << "\n";
		if (iEnd > iMin)
			cout << 1 << "\n";
		else 
			cout << 0 << "\n";

		vecLIS.clear();
	}

	return 0;
}
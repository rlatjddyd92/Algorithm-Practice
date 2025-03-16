#include <iostream>
#include <queue>
#include <vector>

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
		string strInput = {};
		int iNumber = 0;

		cin >> strInput >> iNumber;

		int iMin = 100000;
		int iMax = -1;

		vector<queue<int>> vecAlpha;

		vecAlpha.resize('z' - 'a' + 1);

		for (int j = 0; j < strInput.size(); ++j)
		{
			vecAlpha[strInput[j] - 'a'].push(j);
			if (vecAlpha[strInput[j] - 'a'].size() == iNumber)
			{
				int iNow = j - vecAlpha[strInput[j] - 'a'].front() + 1;
				iMin = min(iNow, iMin);
				iMax = max(iNow, iMax);
				vecAlpha[strInput[j] - 'a'].pop();
			}
		}

		if ((iMin == 100000) || (iMax == -1))
			cout << "-1" << "\n";
		else
			cout << iMin << " " << iMax << "\n";

		vecAlpha.clear();
	}

	return 0;
}

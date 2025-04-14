#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iTree = 0;
	int iWalk = 0;

	cin >> iTree >> iWalk;

	vector<vector<int>> vecDp;
	vector<int> vecStart;
	vecStart.resize(iWalk + 1);
	vecDp.push_back(vecStart);

	for (int i = 0; i < iTree; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		vector<int> vecNow;
		vecNow.resize(iWalk + 1);

		vecNow[0] = vecDp.back()[0] + (iInput == 1);

		for (int j = 1; j <= iWalk; ++j)
		{
			if ((j + 1) % 2 == (iInput) % 2)
				vecNow[j] = max(vecDp.back()[j - 1] + 1, vecDp.back()[j] + 1);
			else
				vecNow[j] = max(vecDp.back()[j - 1] + 1, vecDp.back()[j]);
		}

		vecDp.push_back(vecNow);
	}

	int iAnswer = 0;

	for (auto& iter : vecDp.back())
		if (iAnswer < iter)
			iAnswer = iter;

	cout << iAnswer;

	for (auto& iter : vecDp)
		iter.clear();

	vecDp.clear();

	return 0;
}
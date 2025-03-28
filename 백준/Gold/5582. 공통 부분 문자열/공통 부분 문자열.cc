#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vecCount;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strA;
	string strB;

	cin >> strA >> strB;

	int iAnswer = 0;

	vecCount.resize(strA.size() + 1);

	for (int i = 0; i <= strA.size(); ++i)
	{
		vecCount[i].resize(strB.size() + 1);
		if (i == 0) continue;
		for (int j = 1; j <= strB.size(); ++j)
		{
			if (strA[i - 1] == strB[j - 1])
				vecCount[i][j] = vecCount[i - 1][j - 1] + 1;

			//vecCount[i][j] = max(vecCount[i][j], max(vecCount[i][j - 1], vecCount[i - 1][j]));

			if (iAnswer < vecCount[i][j])
				iAnswer = vecCount[i][j];
		}
	}
		
	cout << iAnswer;

	for (auto& iter : vecCount)
		iter.clear();

	vecCount.clear();
	return 0;
}
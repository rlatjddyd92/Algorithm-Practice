#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strA = "0";
	string strB = "0";
	string strC = "0";
	string strInput = {};
	cin >> strInput;
	strA += strInput;
	cin >> strInput;
	strB += strInput;
	cin >> strInput;
	strC += strInput;

	vector<vector<vector<int>>> vecCount;
	vecCount.resize(strA.size());

	int iAnswer = 0;

	for (int i = 0; i < strA.size(); ++i)
	{
		vecCount[i].resize(strB.size());
		for (int j = 0; j < strB.size(); ++j)
		{
			vecCount[i][j].resize(strC.size());
			if (i * j == 0) continue;
			for (int k = 1; k < strC.size(); ++k)
			{
				
				if ((strA[i] == strB[j]) && (strA[i] == strC[k]))
					vecCount[i][j][k] = vecCount[i - 1][j - 1][k - 1] + 1;

				vecCount[i][j][k] = max(vecCount[i][j][k], max(vecCount[i][j][k - 1], max(vecCount[i][j - 1][k], vecCount[i - 1][j][k])));
				iAnswer = max(vecCount[i][j][k], iAnswer);
			}
		}
	}

	cout << iAnswer;

	for (auto& iter : vecCount)
	{
		for (auto& iteriter : iter)
			iteriter.clear();
		iter.clear();
	}
		
	vecCount.clear();

	return 0;
}
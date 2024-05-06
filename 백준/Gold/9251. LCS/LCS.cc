#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string strA = {};
	string strB = {};

	cin >> strA;
	cin >> strB;

	int iAnswer = 0;

	vector<vector<int>> vecLCS;

	vecLCS.resize(strA.size() + 1);

	for (int i = 0; i <= strA.size(); ++i)
	{
		vecLCS[i].resize(strB.size() + 1);
	}

	for (int i = 1; i <= strA.size(); ++i)
		for (int j = 1; j <= strB.size(); ++j)
		{
			vecLCS[i][j] = max(vecLCS[i - 1][j], vecLCS[i][j - 1]);

			if (strA[i - 1] == strB[j - 1])
				vecLCS[i][j] = vecLCS[i-1][j-1] + 1;

			if (vecLCS[i][j] > iAnswer)
				iAnswer = vecLCS[i][j];
		}

	cout << iAnswer;

	return 0;
}
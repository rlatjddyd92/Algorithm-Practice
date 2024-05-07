#include <iostream>
#include <vector>
#include <stack>

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
	/*
	for (int i = 1; i <= strA.size(); ++i)
	{
		for (int j = 1; j <= strB.size(); ++j)
			cout << vecLCS[i][j];

		cout << "\n";
	}
	*/
	stack<char> stackLCS;

	int iRow = strA.size();
	int iCol = strB.size();

	
	while (stackLCS.size() < iAnswer)
	{
		while (1)
		{
			if (vecLCS[iRow][iCol] == vecLCS[iRow - 1][iCol])
				--iRow;
			else
				break;
		}

		while (1)
		{
			if (vecLCS[iRow][iCol] == vecLCS[iRow][iCol - 1])
				--iCol;
			else
				break;
		}

		stackLCS.push(strA[iRow - 1]);

		--iRow;
		--iCol;
	}

	cout << iAnswer <<'\n';

	while (stackLCS.size())
	{
		cout << stackLCS.top();
		stackLCS.pop();
	}

	for (int i = 0; i <= strA.size(); ++i)
		vecLCS[i].clear();

	vecLCS.clear();

	return 0;
}
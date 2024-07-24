#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecCount;

	vecCount.resize(9);

	for (int i = 0; i <= 8; ++i)
		vecCount[i].resize('Z' - 'A' + 1);

	int iNum = 0;
	int iAnswer = 0;
	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		string strInput = {};
		cin >> strInput;

		for (int j = strInput.size() - 1; j >= 0; --j)
			++vecCount[strInput.size() - 1 - j][strInput[j] - 'A'];
	}

	for (int i = 0; i <= 'Z' - 'A'; ++i)
		for (int j = 0; j < 8; ++j)
		{
			if ((j < 7)&&(vecCount[j][i] >= 10))
			{
				vecCount[j + 1][i] += vecCount[j][i] / 10;
				vecCount[j][i] %= 10;
			}

			vecCount[8][i] += pow(10, j) * vecCount[j][i];
		}

	priority_queue<int> queueNum;

	for (auto& iter : vecCount[8])
		if (iter > 0)
			queueNum.push(iter);

	int iComplex = 9;

	while (!queueNum.empty())
	{
		iAnswer += queueNum.top() * iComplex;
		queueNum.pop();
		--iComplex;
	}

	cout << iAnswer;

	vecCount.clear();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct NUMBER
{
	bool bHead;
	long long llSum;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	long long iAnswer = 0;

	cin >> iNum;

	vector<NUMBER> vecSum;
	vecSum.resize(10);

	for (int i = 0; i < iNum; ++i)
	{
		string strInput = {};
		cin >> strInput;

		long long iProduct = 1;
		for (int j = strInput.size() - 1; j >= 0; --j)
		{
			vecSum[strInput[j] - 'A'].llSum += iProduct;
			iProduct *= 10;
			if (j == 0)
				vecSum[strInput[j] - 'A'].bHead = true;
		}
	}

	stable_sort(vecSum.begin(), vecSum.end(), [](NUMBER first, NUMBER second) {return first.llSum > second.llSum; });

	int iProduct = 9;
	int iSkip = 0;

	for (int i = 9; i >= 0; --i)
		if (vecSum[i].bHead == false)
		{
			iSkip = i;
			break;
		}


	for (int i = 9; i >= 0; --i)
	{
		if (iSkip == 9 - i)
			continue;
		iAnswer += vecSum[9 -i].llSum * iProduct;
		--iProduct;
	}

	cout << iAnswer;

	vecSum.clear();

	return 0;
}

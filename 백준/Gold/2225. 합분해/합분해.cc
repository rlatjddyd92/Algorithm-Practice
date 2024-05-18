#include <iostream>
#include <vector>

#define MAX 1000*1000*1000

using namespace std;

int main()
{
	int iSum = 0;
	int iNum = 0;

	cin >> iSum >> iNum;

	vector<int> vecSum;
	vecSum.push_back(0);

	for (int i = 1; i <= iNum; ++i)
		vecSum.push_back(1);

	for (int i = 1; i <= iSum; ++i)
	{
		for (int j = 1; j <= iNum; ++j)
		{
			vecSum[j] = vecSum[j - 1] + vecSum[j];
			if (vecSum[j] >= MAX)
				vecSum[j] %= MAX;
		}
	}
		
	cout << vecSum[iNum];

	vecSum.clear();

	return 0;
}
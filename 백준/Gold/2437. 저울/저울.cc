#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;

	cin >> iNum;

	vector<long long> vecWeight;
	vecWeight.resize(iNum);

	for (long long i = 0; i < iNum; ++i)
		cin >> vecWeight[i];

	sort(vecWeight.begin(), vecWeight.end());

	long long iSum = 0;

	for (long long i = 0; i < iNum; ++i)
	{
		if (iSum + 1 < vecWeight[i])
			break;

		iSum += vecWeight[i];
	}

	cout << iSum + 1;

	return 0;
}
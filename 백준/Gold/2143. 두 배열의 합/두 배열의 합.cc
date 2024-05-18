#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iSum = 0;
	long long iArr = 0;
	long long iBrr = 0;
	long long iAnswer = 0;

	vector<long long> vecASum;
	vector<long long> vecBSum;
	map<long long, long long> mapASum;
	map<long long, long long> mapBSum;

	cin >> iSum;
	cin >> iArr;

	for (long long i = 0; i < iArr; ++i)
	{
		long long iInput = 0;
		cin >> iInput;

		if (i)
			iInput += vecASum[i - 1];

		vecASum.push_back(iInput);
		if (mapASum.find(iInput) == mapASum.end())
			mapASum.insert({ iInput, 1 });
		else
			++mapASum.find(iInput)->second;
	}

	for (long long i = 0; i < iArr; ++i)
		for (long long j = i+1; j < iArr; ++j)
		{
			long long iKey = vecASum[j] - vecASum[i];

			if (mapASum.find(iKey) == mapASum.end())
				mapASum.insert({ iKey, 1 });
			else
				++mapASum.find(iKey)->second;
		}

	cin >> iBrr;

	for (long long i = 0; i < iBrr; ++i)
	{
		long long iInput = 0;
		cin >> iInput;

		if (i)
			iInput += vecBSum[i - 1];

		vecBSum.push_back(iInput);
		if (mapBSum.find(iInput) == mapBSum.end())
			mapBSum.insert({ iInput, 1 });
		else
			++mapBSum.find(iInput)->second;
	}

	for (long long i = 0; i < iBrr; ++i)
		for (long long j = i + 1; j < iBrr; ++j)
		{
			long long iKey = vecBSum[j] - vecBSum[i];

			if (mapBSum.find(iKey) == mapBSum.end())
				mapBSum.insert({ iKey, 1 });
			else
				++mapBSum.find(iKey)->second;
		}

	for (auto& pair : mapASum)
	{
		if (mapBSum.find(iSum - pair.first) != mapBSum.end())
		{
			iAnswer += mapBSum.find(iSum - pair.first)->second * pair.second;
		}
	}

	cout << iAnswer;

	vecASum.clear();
	vecBSum.clear();
	mapASum.clear();
	mapBSum.clear();

	return 0;
}
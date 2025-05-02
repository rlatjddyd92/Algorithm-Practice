#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> vecAPizza;
vector<pair<long long, long long>> vecBPizza;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iSize = 0;
	long long iInputPiece[2] = {0,0};

	cin >> iSize;
	cin >> iInputPiece[0] >> iInputPiece[1];

	vector<long long> vecInputA;
	vector<long long> vecInputB;

	vecAPizza.push_back({ 0,1 });
	vecBPizza.push_back({ 0,1 });
	vecAPizza.push_back({ 0,1 });
	vecBPizza.push_back({ 0,1 });

	for (long long i = 0; i < iInputPiece[0]; ++i)
	{
		long long iInput = 0;
		cin >> iInput;
		vecInputA.push_back(iInput);
		vecAPizza[0].first += iInput;
	}

	for (long long i = 0; i < iInputPiece[1]; ++i)
	{
		long long iInput = 0;
		cin >> iInput;
		vecInputB.push_back(iInput);
		vecBPizza[0].first += iInput;
	}

	for (long long i = 0; i < iInputPiece[0]; ++i)
	{
		long long iSum = 0;
		for (long long j = i; j < iInputPiece[0] + i - 1; ++j)
		{
			iSum += vecInputA[j % iInputPiece[0]];
			vecAPizza.push_back({ iSum, 1 });
		}
	}
		
	for (long long i = 0; i < iInputPiece[1]; ++i)
	{
		long long iSum = 0;
		for (long long j = i; j < iInputPiece[1] + i - 1; ++j)
		{
			iSum += vecInputB[j % iInputPiece[1]];
			vecBPizza.push_back({ iSum, 1 });
		}
	}

	sort(vecAPizza.begin(), vecAPizza.end());
	sort(vecBPizza.begin(), vecBPizza.end());

	for (long long i = vecAPizza.size() - 2; i >= 0; --i)
		if (vecAPizza[i + 1].first == vecAPizza[i].first)
			vecAPizza[i].second += vecAPizza[i + 1].second;

	for (long long i = vecBPizza.size() - 2; i >= 0; --i)
		if (vecBPizza[i + 1].first == vecBPizza[i].first)
			vecBPizza[i].second += vecBPizza[i + 1].second;


	long long iCount = 0;
	long long iBefore = -1;

	for (auto& iter : vecAPizza)
	{
		if (iBefore == iter.first)
			continue;

		iBefore = iter.first;

		const pair<long long, long long> Now( iSize - iter.first, iter.second );

		long long iIndex = lower_bound(vecBPizza.begin(), vecBPizza.end(), Now, [](const pair<long long, long long> APizza, const pair<long long, long long> BPizza) {return APizza.first < BPizza.first;}) - vecBPizza.begin();

		if ((iIndex < vecBPizza.size()) && (vecBPizza[iIndex].first == iSize - iter.first))
			iCount += iter.second * vecBPizza[iIndex].second;
	}

	cout << iCount;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> vecTown;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNumber = (long long)0;

	cin >> iNumber;

	long long iPeople = (long long)0;

	for (long long i = 0; i < iNumber; ++i)
	{
		long long iInput[2] = { (long long)0,(long long)0 };
		cin >> iInput[0] >> iInput[1];
		vecTown.push_back({ iInput[0] , iInput[1] });
		iPeople += iInput[1];
	}

	stable_sort(vecTown.begin(), vecTown.end(), [](pair<long long, long long> First, pair<long long, long long> Second) {return First.first < Second.first; });

	long long llNowPeople = 0;

	for (long long i = 0; i < iNumber; ++i)
	{
		llNowPeople += vecTown[i].second;

		if (llNowPeople >= (iPeople / 2) + (iPeople % 2))
		{
			cout << vecTown[i].first;
			break;
		}

	}

	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		vector<long long> Distancelist;
		vector<pair<long long, long long>> Pointlist;

		long long llMin = -1;
		long long llMax = -1;

		for (int j = 0; j < 4; ++j)
		{
			long long llInput[2] = { 0,0 };
			cin >> llInput[0] >> llInput[1];
			Pointlist.push_back({ llInput[0], llInput[1] });
		}

		for (int j = 0; j < 4; ++j)
			for (int k = j + 1; k < 4; ++k)
			{
				Distancelist.push_back(pow(Pointlist[j].first - Pointlist[k].first, 2) + pow(Pointlist[j].second - Pointlist[k].second, 2));
				if ((llMin == -1) || (llMin > Distancelist.back()))
					llMin = Distancelist.back();
				if ((llMax == -1) || (llMax < Distancelist.back()))
					llMax = Distancelist.back();
			}

		int iCountMin = 0;
		int iCountMax = 0;

		for (int j = 0; j < 6; ++j)
		{
			if (Distancelist[j] == llMin)
				++iCountMin;

			if (Distancelist[j] == llMax)
				++iCountMax;
		}
		
		if ((iCountMin == 4) && (iCountMax == 2))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}
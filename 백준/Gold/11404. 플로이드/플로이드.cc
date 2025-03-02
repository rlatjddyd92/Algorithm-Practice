#include <iostream>
#include <vector>

#define MAX 100 * 100 * 100000

using namespace std;

vector<vector<int>> vecPloyde;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCity = 0;
	int iBus = 0;

	cin >> iCity >> iBus;


	vecPloyde.resize(iCity + 1);

	for(auto& iter : vecPloyde)
		iter.resize(iCity + 1, MAX);

	for (int i = 0; i < iBus; ++i)
	{
		int iInput[3] = { 0, };
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		vecPloyde[iInput[0]][iInput[1]] = min(vecPloyde[iInput[0]][iInput[1]], iInput[2]);
	}

	for (int i = 1; i <= iCity; ++i)
	{
		// 각 도시를 거쳐 가는 경로를 찾아 최소값 갱신할 것 
		// 갱신할 값(a->b) = min(a->b, a->i + i->b)

		for (int j = 1; j <= iCity; ++j)
			for (int k = 1; k <= iCity; ++k)
			{
				if (j == k) continue;
				if ((j == i) || (k == i)) continue;

				vecPloyde[j][k] = min(vecPloyde[j][k], vecPloyde[j][i] + vecPloyde[i][k]);
			}
	}

	for (int j = 1; j <= iCity; ++j)
	{
		for (int k = 1; k <= iCity; ++k)
		{
			if (vecPloyde[j][k] == MAX)
				cout << 0 << " ";
			else
				cout << vecPloyde[j][k] << " ";
		}

		cout << "\n";
	}
		
	for (auto& iter : vecPloyde)
		iter.clear();

	vecPloyde.clear();

	return 0;
}
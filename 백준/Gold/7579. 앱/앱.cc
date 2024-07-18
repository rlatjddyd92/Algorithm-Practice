#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct APP
{
	int iMemory;
	int iCost;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iApps = 0;
	int iNeed = 0;
	int iMax = 0;
	int iAnswer = -1;

	cin >> iApps >> iNeed;

	vector<APP> vecApp;
	vecApp.resize(iApps + 1);

	for (int i = 1; i <= iApps; ++i)
		cin >> vecApp[i].iMemory;

	for (int i = 1; i <= iApps; ++i)
	{
		cin >> vecApp[i].iCost;
		iMax += vecApp[i].iCost;
	}
		

	vector<vector<int>> vecMemory;
	vecMemory.resize(iApps + 1);

	for (int i = 0; i <= iApps; ++i)
		vecMemory[i].resize(iMax + 1);

	for (int i = 0; i <= iMax; ++i)
	{
		for (int j = 1; j <= iApps; ++j)
		{
			if (vecApp[j].iCost > i)
				vecMemory[j][i] = vecMemory[j - 1][i];
			else if (i == 0)
				vecMemory[j][i] = vecApp[j].iMemory + vecMemory[j - 1][i];
			else if (vecApp[j].iCost == 0)
				vecMemory[j][i] = max(vecApp[j].iMemory + vecMemory[j - 1][i], vecMemory[j][i - 1]);
			else
				vecMemory[j][i] = max(vecApp[j].iMemory + vecMemory[j - 1][i - vecApp[j].iCost], vecMemory[j- 1][i]);

			if (vecMemory[j][i] >= iNeed)
			{
				iAnswer = i;
				break;
			}
		}
		if (iAnswer != -1)
			break;
	}
		
	cout << iAnswer;

	for (auto& iter : vecMemory)
		iter.clear();

	vecApp.clear();
	vecMemory.clear();

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<bool> vecExist(1000001);
vector<int> vecScore(1000001);

int main()
{
	int iPlayer = 0;

	cin >> iPlayer;

	vector<int> vecOrder;

	for (int i = 0; i < iPlayer; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecExist[iInput] = true;
		vecOrder.push_back(iInput);
	}

	for (int i = 1; i <= 1000000; ++i)
	{
		if (vecExist[i])
		{
			int iIndex = i*2;
			while (iIndex <= 1000000)
			{
				if (vecExist[iIndex])
				{
					++vecScore[i];
					--vecScore[iIndex];
				}
				iIndex += i;
			}
		}
	}

	for (int i = 0; i < iPlayer; ++i)
		cout << vecScore[vecOrder[i]] << " ";

	vecExist.clear();
	vecScore.clear();

	return 0;
}
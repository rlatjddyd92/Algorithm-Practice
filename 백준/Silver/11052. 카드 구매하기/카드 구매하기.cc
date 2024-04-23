#include <iostream>
#include <vector>

using namespace std;

struct CardPack
{
	int iCount;
	int iPrice;
};

int main()
{
	int iCard = 0;
	int iAnswer = 0;

	cin >> iCard;

	vector<CardPack> vecPack(iCard);
	vector<int> vecDp(iCard+1);

	for (int i = 0; i < iCard; ++i)
	{
		vecPack[i].iCount = i + 1;
		cin >> vecPack[i].iPrice;
	}

	for (int i = 1; i <= iCard; ++i)
	{
		int iMax = 0;

		for (int j = 0; j < iCard; ++j)
		{
			if (i < vecPack[j].iCount)
				continue;

			int iTemp = vecPack[j].iPrice + vecDp[i - vecPack[j].iCount];
			
			if (iMax < iTemp)
				iMax = iTemp;
		}

		vecDp[i] = iMax;
	}

	cout << vecDp[iCard];

	vecPack.clear();
	vecDp.clear();

	return 0;
}
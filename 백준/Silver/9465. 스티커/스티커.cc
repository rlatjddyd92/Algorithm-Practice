#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct StickerInfo
{
	int Upper;
	int Lower;
};

int main()
{
	int iCase = 0;
	
	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iNum = 0;

		cin >> iNum;

		vector<StickerInfo> vecInfo(iNum+1);

		for (int j = 1; j <= iNum; ++j)
		{
			cin >> vecInfo[j].Upper;
		}

		for (int j = 1; j <= iNum; ++j)
		{
			cin >> vecInfo[j].Lower;
		}

		for (int j = 2; j <= iNum; ++j)
		{
			vecInfo[j].Upper += max(max(vecInfo[j - 2].Upper, vecInfo[j - 2].Lower), vecInfo[j - 1].Lower);
			vecInfo[j].Lower += max(max(vecInfo[j - 2].Lower, vecInfo[j - 2].Upper), vecInfo[j - 1].Upper);
		}

		cout << max(vecInfo[iNum].Upper, vecInfo[iNum].Lower) << "\n";

		vecInfo.clear();
	}

	return 0;
}
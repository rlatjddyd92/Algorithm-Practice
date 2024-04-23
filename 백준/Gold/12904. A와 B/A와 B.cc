#include <iostream>

using namespace std;

int main()
{
	string sS = {};
	string sT = {};

	cin >> sS;
	cin >> sT;

	int iCount = 0;
	int iStart = 0;
	int iEnd = sT.size() - 1;
	bool bReverse = false;

	while (iCount != sT.size() - sS.size())
	{
		if (!bReverse)
		{
			if (sT[iEnd] == 'B')
				bReverse = true;

			--iEnd;
		}
		else
		{
			if (sT[iStart] == 'B')
				bReverse = false;

			++iStart;
		}

		++iCount;
	}

	if (bReverse)
	{
		for (int i = 0; i < sS.size() / 2; ++i)
		{
			char szTemp = sS[i];
			sS[i] = sS[sS.size() - 1 - i];
			sS[sS.size() - 1 - i] = szTemp;
		}
	}

	for (int i = 0; i < sS.size(); ++i)
	{
		if (sS[i] != sT[iStart + i])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}
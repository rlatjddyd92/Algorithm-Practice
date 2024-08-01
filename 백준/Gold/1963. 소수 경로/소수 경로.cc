#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecNum;

	vecNum.resize(10000);

	for (int i = 2; i <= 9999; ++i)
	{
		if (vecNum[i] == true)
			continue;

		int iCheck = i;

		while (iCheck + i < 10000)
		{
			iCheck += i;
			vecNum[iCheck] = true;
		}
	}

	int iCase = 0;

	cin >> iCase;


	for (int i = 0; i < iCase; ++i)
	{
		int iStart = 0;
		int iEnd = 0;
		int iAnswer = -1;

		vector<int> vecVisit;
		vecVisit.resize(10000);

		cin >> iStart >> iEnd;

		queue<int> queueNext;
		queueNext.push(iStart);

		while (!queueNext.empty())
		{
			int iNow = queueNext.front();
			
			queueNext.pop();

			if (iNow == iEnd)
			{
				if ((iAnswer == -1) || (vecVisit[iNow] < iAnswer))
					iAnswer = vecVisit[iNow];

				continue;
			}

			for (int j = 0; j < 4; ++j)
			{
				int iNum = int(iNow / pow(10, j)) % 10;
				iNum *= pow(10, j);
				int iTemp = iNow - iNum;

				for (int k = 1; k < 10; ++k)
				{
					iNum +=pow(10, j);
					iNum %= int(pow(10, j + 1));

					if ((iTemp + iNum) / 1000 == 0)
						continue;
					
					if ((vecVisit[iTemp + iNum] == 0) || (vecVisit[iTemp + iNum] > vecVisit[iNow] + 1))
						if (vecNum[iTemp + iNum]==false)
					{
						vecVisit[iTemp + iNum] = vecVisit[iNow] + 1;
						queueNext.push(iTemp + iNum);
					}
				}
			}
		}
		if (iAnswer == -1)
			cout << "Impossible" << "\n";
		else
			cout << iAnswer << "\n";

		vecVisit.clear();
	}

	vecNum.clear();

	return 0;
}
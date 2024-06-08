#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define HOUSE 0
#define PENTA 1
#define MAX 50*20

using namespace std;

struct POINT
{
	int iX;
	int iY;
	bool bVisit;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iPoint = 0; 
		cin >> iPoint;

		vector<POINT> vecPoint;
		vecPoint.resize(iPoint + 2);

		cin >> vecPoint[HOUSE].iX >> vecPoint[HOUSE].iY;

		for (int j = 2; j <= iPoint + 1; ++j)
		{
			cin >> vecPoint[j].iX >> vecPoint[j].iY;
		}

		cin >> vecPoint[PENTA].iX >> vecPoint[PENTA].iY;

		queue<int> queueNext;
		queueNext.push(HOUSE);
		vecPoint[HOUSE].bVisit = true;
		string strAnswer = "sad";

		while (!queueNext.empty())
		{
			int iNow = queueNext.front();
			queueNext.pop();

			for (int j = PENTA; j < iPoint + 2; ++j)
			{
				if (vecPoint[j].bVisit) continue;

				if (abs(vecPoint[j].iX - vecPoint[iNow].iX) + abs(vecPoint[j].iY - vecPoint[iNow].iY) <= MAX)
				{
					vecPoint[j].bVisit = true;
					queueNext.push(j);
				}
			}

			if (vecPoint[PENTA].bVisit)
			{
				strAnswer = "happy";
				break;
			}
		}

		cout << strAnswer << "\n";
	}

	return 0;
}

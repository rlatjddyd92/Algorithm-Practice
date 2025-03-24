#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct POINT
{
	double dX = (double)0;
	double dY = (double)0;
	double dRadius = 0;

	bool Check_Collision(const POINT Opponent)
	{
		double dDistance = ((dX - Opponent.dX) * (dX - Opponent.dX)) + ((dY - Opponent.dY) * (dY - Opponent.dY));
		dDistance = sqrt(dDistance);
		return !(dDistance > dRadius + Opponent.dRadius);
	}
};

vector<POINT> vecPoint;
vector<int> vecHead;

int Find_Head(int iNumber);
void Merge_Group(int iFirst, int iSecond);

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

		vecPoint.resize(iPoint);
		vecHead.resize(iPoint);

		for (int j = 0; j < iPoint; ++j)
		{
			cin >> vecPoint[j].dX >> vecPoint[j].dY >> vecPoint[j].dRadius;
			vecHead[j] = j;
		}

		for (int j = 0; j < iPoint; ++j)
			for (int k = 0; k < iPoint; ++k)
			{
				if (vecPoint[j].Check_Collision(vecPoint[k]) == true)
					Merge_Group(j, k);
			}

		int iCount = iPoint;

		for (int j = 0; j < iPoint; ++j)
		{
			if (vecHead[j] != j)
				--iCount;
		}

		cout << iCount << "\n";

		vecPoint.clear();
		vecHead.clear();
	}

	return 0;
}

int Find_Head(int iNumber)
{
	if (vecHead[iNumber] != iNumber)
		vecHead[iNumber] = Find_Head(vecHead[iNumber]);

	return vecHead[iNumber];
}

void Merge_Group(int iFirst, int iSecond)
{
	int iNewHead = min(Find_Head(iFirst), Find_Head(iSecond));
	vecHead[vecHead[iFirst]] = vecHead[vecHead[iSecond]] = iNewHead;
}

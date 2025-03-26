#include <iostream>
#include <vector>

using namespace std;

struct SQURE
{
	int iLeft = 0;
	int iBottom = 0;
	int iRight = 0;
	int iTop = 0;

	bool Check_Collision(const SQURE Opponent) const
	{
		if (iLeft > Opponent.iRight)
			return false;

		if (iBottom > Opponent.iTop)
			return false;

		if (iRight < Opponent.iLeft)
			return false;

		if (iTop < Opponent.iBottom)
			return false;

		if ((iLeft < Opponent.iLeft) && (iBottom < Opponent.iBottom))
			if ((iRight > Opponent.iRight) && (iTop > Opponent.iTop))
				return false;

		if ((iLeft > Opponent.iLeft) && (iBottom > Opponent.iBottom))
			if ((iRight < Opponent.iRight) && (iTop < Opponent.iTop))
				return false;

		return true;
	}
};

vector<SQURE> vecSqure;
vector<int> vecHead;

int Find_Head(int iIndex)
{
	if (vecHead[iIndex] != iIndex)
		vecHead[iIndex] = Find_Head(vecHead[iIndex]);

	return vecHead[iIndex];
}

void Merge_Head(int iFirst, int iSecond)
{
	int iNewHead = min(Find_Head(iFirst), Find_Head(iSecond));
	vecHead[vecHead[iFirst]] = iNewHead;
	vecHead[vecHead[iSecond]] = iNewHead;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCount = 0;

	cin >> iCount;

	SQURE Zero({ 0,0,0,0 });
	vecSqure.push_back(Zero);
	vecHead.push_back(0);

	for (int i = 0; i < iCount; ++i)
	{
		SQURE New{};
		cin >> New.iLeft >> New.iBottom >> New.iRight >> New.iTop;

		vecSqure.push_back(New);
		vecHead.push_back(i + 1);
	}

	for (int i = 0; i <= iCount; ++i)
		for (int j = 0; j <= iCount; ++j)
		{
			if (i == j) continue;
			if (vecSqure[i].Check_Collision(vecSqure[j]) == true)
				Merge_Head(i, j);
		}

	int iAnswer = iCount;
			
	for (int i = 0; i <= iCount; ++i)
		if (vecHead[i] != i)
			--iAnswer;

	cout << iAnswer;

	return 0;
}

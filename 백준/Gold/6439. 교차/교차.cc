#include <iostream>
#include <vector>

using namespace std;

struct Vector2D
{
	long long lX = 0;
	long long lY = 0;

	Vector2D operator - (const Vector2D Opponent) const
	{
		Vector2D Return{};
		Return.lX = lX - Opponent.lX;
		Return.lY = lY - Opponent.lY;
		return Return;
	}
};

long long CCW(Vector2D vA, Vector2D vB, Vector2D vC);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	vector<Vector2D> vecSqure;
	vector<Vector2D> vecLine;

	for (int k = 0; k < iCase; ++k)
	{
		vecSqure.resize(4);
		vecLine.resize(2);

		long long LLInput[8] = { 0, };
		
		for (int i = 0; i < 8; ++i)
			cin >> LLInput[i];

		vecLine[0].lX = LLInput[0];
		vecLine[0].lY = LLInput[1];
		vecLine[1].lX = LLInput[2];
		vecLine[1].lY = LLInput[3];

		vecSqure[0].lX = min(LLInput[4], LLInput[6]);
		vecSqure[0].lY = min(LLInput[5], LLInput[7]);

		vecSqure[1].lX = max(LLInput[4], LLInput[6]);
		vecSqure[1].lY = max(LLInput[5], LLInput[7]);

		vecSqure[2].lX = vecSqure[0].lX;
		vecSqure[2].lY = vecSqure[1].lY;

		vecSqure[3].lX = vecSqure[1].lX;
		vecSqure[3].lY = vecSqure[0].lY;

		bool bIsOk = false;

		if ((vecLine[0].lX >= vecSqure[0].lX) && (vecLine[0].lX <= vecSqure[1].lX))
			if ((vecLine[0].lY >= vecSqure[0].lY) && (vecLine[0].lY <= vecSqure[1].lY))
				bIsOk = true;

		if ((vecLine[1].lX >= vecSqure[0].lX) && (vecLine[1].lX <= vecSqure[1].lX))
			if ((vecLine[1].lY >= vecSqure[0].lY) && (vecLine[1].lY <= vecSqure[1].lY))
				bIsOk = true;

		if (bIsOk == false)
			for (int i = 0; i < 4; ++i)
			{
				if ((vecSqure[i].lX >= min(vecLine[0].lX, vecLine[1].lX)) && (vecSqure[i].lX <= max(vecLine[0].lX, vecLine[1].lX)))
					if ((vecSqure[i].lY >= min(vecLine[0].lY, vecLine[1].lY)) && (vecSqure[i].lY <= max(vecLine[0].lY, vecLine[1].lY)))
					{
						Vector2D vBig{};
						Vector2D vSmall{};

						vBig = vecLine[1] - vecLine[0];
						vSmall = vecSqure[i] - vecLine[0];

						if (vBig.lX * vSmall.lY == vBig.lY * vSmall.lX)
							bIsOk = true;
					}
				

				if (bIsOk == false)
				for (int j = 0; j < 4; ++j)
				{
					if (CCW(vecLine[0], vecLine[1], vecSqure[i]) * CCW(vecLine[0], vecLine[1], vecSqure[j]) < 0)
						if (CCW(vecSqure[i], vecSqure[j], vecLine[0]) * CCW(vecSqure[i], vecSqure[j], vecLine[1]) < 0)
							bIsOk = true;
				}

				if (bIsOk == true)
					break;
			}
				

		if (bIsOk == true)
			cout << 'T' << '\n';
		else
			cout << 'F' << '\n';

		vecSqure.clear();
		vecLine.clear();
	}

	return 0;
}

long long CCW(Vector2D vA, Vector2D vB, Vector2D vC)
{
	long long llReturn = (vA.lX * vB.lY) + (vB.lX * vC.lY) + (vC.lX * vA.lY);
	llReturn -= (vB.lX * vA.lY) + (vC.lX * vB.lY) + (vA.lX * vC.lY);
	return llReturn;
}

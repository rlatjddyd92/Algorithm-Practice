#include <iostream>

using namespace std;

struct Vector2D
{
	long long iX = 0;
	long long iY = 0;

	Vector2D operator + (const Vector2D Opponent) const
	{
		Vector2D Return{};
		Return.iX = iX + Opponent.iX;
		Return.iY = iY + Opponent.iY;
		return Return;
	}
};

long long CCW(Vector2D vA, Vector2D vB, Vector2D vC);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Vector2D First_Start{};
	Vector2D First_End{};
	Vector2D Second_Start{};
	Vector2D Second_End{};

	cin >> First_Start.iX >> First_Start.iY >> First_End.iX >> First_End.iY;
	cin >> Second_Start.iX >> Second_Start.iY >> Second_End.iX >> Second_End.iY;

	long long iAnswer = 0;

	if (CCW(First_Start, First_End, Second_Start) * CCW(First_Start, First_End, Second_End) == -1)
		if (CCW(Second_Start, Second_End, First_Start) * CCW(Second_Start, Second_End, First_End) == -1)
			iAnswer = 1;

	cout << iAnswer;

	return 0;
}

long long CCW(Vector2D vA, Vector2D vB, Vector2D vC)
{
	long long iResult = 0;
	iResult = (vA.iX * vB.iY) + (vB.iX * vC.iY) + (vC.iX * vA.iY);
	iResult -= (vB.iX * vA.iY) + (vC.iX * vB.iY) + (vA.iX * vC.iY);
	return iResult / abs(iResult);
}

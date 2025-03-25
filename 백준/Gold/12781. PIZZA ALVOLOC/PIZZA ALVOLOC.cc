#include <iostream>

using namespace std;

struct Vector2D
{
	double dX = 0;
	double dY = 0;
};

int CCW(Vector2D vA, Vector2D vB, Vector2D vC);

int main()
{
	Vector2D First_Start;
	Vector2D First_End;
	Vector2D Second_Start;
	Vector2D Second_End;

	cin >> First_Start.dX >> First_Start.dY >> First_End.dX >> First_End.dY;
	cin >> Second_Start.dX >> Second_Start.dY >> Second_End.dX >> Second_End.dY;

	int iResult = 0;

	if (CCW(First_Start, First_End, Second_Start) * CCW(First_Start, First_End, Second_End) == -1)
		if (CCW(Second_Start, Second_End, First_Start) * CCW(Second_Start, Second_End, First_End) == -1)
			iResult = 1;

	cout << iResult;

	return 0;

}

int CCW(Vector2D vA, Vector2D vB, Vector2D vC)
{
	double dCCW = (vA.dX * vB.dY) + (vB.dX * vC.dY) + (vC.dX * vA.dY);
	dCCW -= (vB.dX * vA.dY) + (vC.dX * vB.dY) + (vA.dX * vC.dY);

	if (dCCW > 0)
		return 1;
	else if (dCCW < 0)
		return -1;
	else
		return 0;
}

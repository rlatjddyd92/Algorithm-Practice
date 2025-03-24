#include <iostream>

#define DOUBLE double
#define LONG long long

using namespace std;

struct Vector2D
{
	LONG llX = (LONG)0;
	LONG llY = (LONG)0;

	Vector2D operator - (const Vector2D Opponent) const
	{
		Vector2D Result{};
		Result.llX = llX - Opponent.llX;
		Result.llY = llY - Opponent.llY;
		return Result;
	}
};

int CCW(Vector2D vA, Vector2D vB, Vector2D vC);
bool IsOnLine(Vector2D vStart, Vector2D vEnd, Vector2D vDot);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Vector2D First_Start{};
	Vector2D First_End{};
	Vector2D Second_Start{};
	Vector2D Second_End{};

	cin >> First_Start.llX >> First_Start.llY >> First_End.llX >> First_End.llY;
	cin >> Second_Start.llX >> Second_Start.llY >> Second_End.llX >> Second_End.llY;

	int iAnswer = 0;

	if (CCW(First_Start, First_End, Second_Start) * CCW(First_Start, First_End, Second_End) == -1)
		if (CCW(Second_Start, Second_End, First_Start) * CCW(Second_Start, Second_End, First_End) == -1)
			iAnswer = 1;

	if (iAnswer == 0)
	{
		if (IsOnLine(First_Start, First_End, Second_Start) == true)
			iAnswer = 1;
		else if (IsOnLine(First_Start, First_End, Second_End) == true)
			iAnswer = 1;
		else if (IsOnLine(Second_Start, Second_End, First_Start) == true)
			iAnswer = 1;
		else if (IsOnLine(Second_Start, Second_End, First_End) == true)
			iAnswer = 1;
	}

	cout << iAnswer;

	return 0;
}

int CCW(Vector2D vA, Vector2D vB, Vector2D vC)
{
	LONG Result = (LONG)0;
	Result = (vA.llX * vB.llY) + (vB.llX * vC.llY) + (vC.llX * vA.llY);
	Result -= (vB.llX * vA.llY) + (vC.llX * vB.llY) + (vA.llX * vC.llY);

	if (Result > 0)
		return 1;
	else if (Result < 0)
		return -1;
	else
		return 0;
}

bool IsOnLine(Vector2D vStart, Vector2D vEnd, Vector2D vDot)
{
	if ((min(vStart.llX, vEnd.llX) > vDot.llX) || (min(vStart.llY, vEnd.llY) > vDot.llY))
		return false;

	if ((max(vStart.llX, vEnd.llX) < vDot.llX) || (max(vStart.llY, vEnd.llY) < vDot.llY))
		return false;

	Vector2D vDirec = vEnd - vStart;
	Vector2D vDotOnLine = vDot - vStart;
	
	if (vDirec.llX * vDotOnLine.llY == vDirec.llY * vDotOnLine.llX)
		return true;
	else
		return false;
}

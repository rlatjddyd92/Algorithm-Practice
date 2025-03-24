#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Vector2D
{
	double dX = (double)0;
	double dY = (double)0;
	double dZ = (double)0;

	Vector2D operator + (const Vector2D Opponent) const
	{
		Vector2D Return{};
		Return.dX = dX + Opponent.dX;
		Return.dY = dY + Opponent.dY;
		Return.dZ = dZ + Opponent.dZ;
		return Return;
	}

	Vector2D operator - (const Vector2D Opponent) const
	{
		Vector2D Return{};
		Return.dX = dX - Opponent.dX;
		Return.dY = dY - Opponent.dY;
		Return.dZ = dZ - Opponent.dZ;
		return Return;
	}

	Vector2D operator * (const Vector2D Opponent) const
	{
		Vector2D Return{};
		Return.dX = (dY * Opponent.dZ) - (dZ * Opponent.dY);
		Return.dY = (dZ * Opponent.dX) - (dX * Opponent.dZ);
		Return.dZ = (dX * Opponent.dY) - (dY * Opponent.dX);
		return Return;
	}

	double Product(const Vector2D Opponent)
	{
		return dX * Opponent.dX + dY * Opponent.dY + dZ * Opponent.dZ;
	}

	double Scalar_Squre()
	{
		return (dX * dX) + (dY * dY) + (dZ * dZ);
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Vector2D vStart{};
	Vector2D vEnd{};
	Vector2D vDot{};

	double dAnswer = (double)0;

	cin >> vStart.dX >> vStart.dY >> vStart.dZ;
	cin >> vEnd.dX >> vEnd.dY >> vEnd.dZ;
	cin >> vDot.dX >> vDot.dY >> vDot.dZ;

	Vector2D vToEnd{};
	Vector2D vToDot{};
	Vector2D vDotToStart{};
	Vector2D vEndToDot{};
	Vector2D vEndToStart{};

	vToEnd = vEnd - vStart;
	vToDot = vDot - vStart;
	vEndToDot = vDot - vEnd;
	vDotToStart = vStart - vDot;
	vEndToStart = vStart - vEnd;


	Vector2D vCross = vToEnd * vToDot;

	dAnswer = sqrt(vCross.Scalar_Squre()) / sqrt(vToEnd.Scalar_Squre());

	double dRatio = vDotToStart.Product(vEndToStart) / vEndToStart.Scalar_Squre();

	if (dRatio > (double)1)
		dAnswer = sqrt(vEndToDot.Scalar_Squre());
	else if (dRatio < (double)0)
		dAnswer = sqrt(vToDot.Scalar_Squre());

	cout << std::setprecision(10) << (dAnswer);

	return 0;
}
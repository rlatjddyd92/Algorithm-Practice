#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long double dDistance = (long double)0;
	long double dX = (long double)0;
	long double dY = (long double)0;
	long double dTime = (long double)0;
	long double dJump = (long double)0;
	long double dAnswer = (long double)0;
	long double dRemain = (long double)0;
	long double dRRemain = (long double)0;

	cin >> dX >> dY >> dJump >> dTime;

	dDistance = sqrt((dX * dX) + (dY * dY));
	dRemain = dDistance - ((long long)(dDistance / dJump) * dJump);
	dRRemain = dJump - dRemain;

	dAnswer = (long long)(dDistance / dJump) * dTime;

	if (dAnswer == (long double)0.0)
	{
		dAnswer = min(dTime + dRRemain, dDistance);
		dAnswer = min(dTime + dTime, dAnswer);
	}
	else
	{
		dAnswer += dRemain > (long double)0 ? min(dRemain, dTime) : (long double)0;
	}

	dAnswer = min(dDistance, dAnswer);

	cout << setprecision(20) << fixed << dAnswer;

	return 0;
}
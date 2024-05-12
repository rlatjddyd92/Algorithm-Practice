#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Vector2D
{
	Vector2D operator- (Vector2D &VInput)
	{
		return { iX - VInput.iX, iY - VInput.iY };
	}

	Vector2D operator+ (Vector2D& VInput)
	{
		return { iX + VInput.iX, iY + VInput.iY };
	}

	double operator* (Vector2D VInput)
	{
		return ( iX * VInput.iY - iY * VInput.iX );
	}

	double iX;
	double iY;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	double dAnswer = 0.f;
	vector<Vector2D> vec2D;

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		double iInputX = 0;
		double iInputY = 0;

		cin >> iInputX >> iInputY;

		vec2D.push_back({ iInputX ,iInputY });

		if (vec2D.size() == 3)
		{
			dAnswer += (vec2D[0] - vec2D[1]) * (vec2D[0] - vec2D[2]) / 2.f;
			vector<Vector2D>::iterator iter = vec2D.begin() + 1;
			vec2D.erase(iter);
		}
	}

	dAnswer = abs(dAnswer);
	dAnswer *= 10.f;
	dAnswer = round(dAnswer);
	dAnswer /= 10.f;

	cout << fixed;
	cout.precision(1);

	cout << dAnswer;

	vec2D.clear();

	return 0;
}
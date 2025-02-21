#include <iostream>
#include <vector>

using namespace std;

struct DATE
{
	int iTime = 0;
	int iPay = 0;
	int iPaySum = 0;
};

vector<DATE> vecDate;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iDayLimit = 0;
	int iAnswer = 0;

	cin >> iDayLimit;

	vecDate.resize(iDayLimit + 1);

	for (int i = 0; i < iDayLimit; ++i)
	{
		cin >> vecDate[i].iTime >> vecDate[i].iPay;
	}

	for (int i = 0; i < iDayLimit; ++i)
	{
		if (vecDate[i].iTime + i <= iDayLimit)
		{
			int iNextDay = vecDate[i].iTime + i;
			int iDeposit = vecDate[i].iPay + vecDate[i].iPaySum;

			if (vecDate[iNextDay].iPaySum < iDeposit)
				vecDate[iNextDay].iPaySum = iDeposit;
		}

		if (vecDate[i].iPaySum > vecDate[i + 1].iPaySum)
			vecDate[i + 1].iPaySum = vecDate[i].iPaySum;
	}

	cout << vecDate[iDayLimit].iPaySum;

	vecDate.clear();

	return 0;
}
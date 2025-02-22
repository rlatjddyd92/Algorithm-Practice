#include <iostream>
#include <vector>

using namespace std;

vector<int> vecCity;

// union find
// 1. 병합 
// 2. 추적 

void SetRoot(int iFirst, int iSecond);
int FindHead(int iCity);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCityNum = 0;
	int iDestination = 0;

	cin >> iCityNum;
	cin >> iDestination;

	vecCity.resize(iCityNum + 1);

	for (int i = 1; i <= iCityNum; ++i)
		vecCity[i] = i;

	for(int i = 1; i <= iCityNum; ++i)
		for (int j = 1; j <= iCityNum; ++j)
		{
			int iIsRoute = 0;
			cin >> iIsRoute;

			if (iIsRoute == 1)
				SetRoot(i, j);
		}

	int iHead = 0;
	bool bIsFail = false;

	for (int i = 0; i < iDestination; ++i)
	{
		int iDestNow = 0;
		cin >> iDestNow;

		if (iHead == 0)
			iHead = FindHead(iDestNow);
		else if (iHead != FindHead(iDestNow))
		{
			bIsFail = true;
			break;
		}
	}

	if (bIsFail == false)
		cout << "YES";
	else
		cout << "NO";

	vecCity.clear();

	return 0;
}

void SetRoot(int iFirst, int iSecond)
{
	int iRootFirst = FindHead(iFirst);
	int iRootSecond = FindHead(iSecond);

	if (iRootFirst <= iRootSecond)
		vecCity[iRootSecond] = iRootFirst;
	else 
		vecCity[iRootFirst] = iRootSecond;
}

int FindHead(int iCity)
{
	int iRoot = vecCity[iCity];
	int iNowCity = iCity;

	while (iNowCity != iRoot)
	{
		iNowCity = iRoot;
		iRoot = vecCity[iNowCity];
	}

	return iRoot;
}

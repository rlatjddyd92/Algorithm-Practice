#include <iostream>
#include <vector>

using namespace std;

struct XY
{
	int iNum[2] = { 0, };
};

vector<XY> vecRoute;
vector<int> vecGroup;

int FindHead(int iNode);
void MergeGroup(int iFirst, int iSecond);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumbers = 0;
	int iRoute = 0;
	int iAnswer = 0;

	cin >> iNumbers >> iRoute;

	vecRoute.resize(iRoute);
	vecGroup.resize(iNumbers);

	for (int i = 0; i < iNumbers; ++i)
		vecGroup[i] = i;

	for (int i = 0; i < iRoute; ++i)
		cin >> vecRoute[i].iNum[0] >> vecRoute[i].iNum[1];

	int iPlayer = 1;

	for (int i = 0; i < iRoute; ++i)
	{
		iPlayer = iPlayer == 0 ? 1 : 0;
		iAnswer = i + 1;

		int iFirst = FindHead(vecRoute[i].iNum[0]);
		int iSecond = FindHead(vecRoute[i].iNum[1]);

		if (iFirst == iSecond)
			break;
		else if (i == iRoute - 1)
			iAnswer = 0;
		else
			MergeGroup(iFirst, iSecond);
	}

	cout << iAnswer;

	vecRoute.clear();
	vecGroup.clear();

	return 0;
}

int FindHead(int iNode)
{
	int iHead = vecGroup[iNode];
	
	if (iHead != iNode)
		vecGroup[iNode] = FindHead(iHead);

	return vecGroup[iNode];
}

void MergeGroup(int iFirst, int iSecond)
{
	int iFHead = FindHead(iFirst);
	int iSHead = FindHead(iSecond);

	vecGroup[iFHead] = min(iFHead, iSHead);
	vecGroup[iSHead] = min(iFHead, iSHead);
}

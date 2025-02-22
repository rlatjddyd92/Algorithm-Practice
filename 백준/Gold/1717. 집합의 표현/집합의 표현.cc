#include <iostream>
#include <vector>

using namespace std;

vector<int> vecNum;

int FindHead(int iNum);
void MergeGroup(int iFirst, int iSecond);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumbers = 0;
	int iQuery = 0;

	cin >> iNumbers >> iQuery;

	vecNum.resize(iNumbers + 1);

	for (int i = 0; i <= iNumbers; ++i)
		vecNum[i] = i;

	for (int i = 0; i < iQuery; ++i)
	{
		int iCommand = 0;
		int iNum[2] = { 0, };

		cin >> iCommand >> iNum[0] >> iNum[1];

		if (iCommand == 0)
			MergeGroup(iNum[0], iNum[1]);
		else if (FindHead(iNum[0]) == FindHead(iNum[1]))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	vecNum.clear();
	return 0;
}

int FindHead(int iNum)
{
	int iHead = vecNum[iNum];

	if (iHead != iNum)
		vecNum[iNum] = FindHead(iHead);

	return vecNum[iNum];
}

void MergeGroup(int iFirst, int iSecond)
{
	int iHead[2] = { FindHead(iFirst), FindHead(iSecond) };
	int iNewHead = min(iHead[0], iHead[1]);

	vecNum[iHead[0]] = iNewHead;
	vecNum[iHead[1]] = iNewHead;
}

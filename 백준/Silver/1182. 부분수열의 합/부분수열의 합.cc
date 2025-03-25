#include <iostream>
#include <vector>

using namespace std;

int iNumber = 0;
int iAnswer = 0;
int iSize = 0;
vector<int> vecNumber;

void SelectNumber(int iStart, int iSum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iSize >> iNumber;

	vecNumber.resize(iSize);

	for (int i = 0; i < iSize; ++i)
		cin >> vecNumber[i];

	for (int i = 0; i < iSize; ++i)
		SelectNumber(i, 0);

	cout << iAnswer;

	vecNumber.clear();

	return 0;
}

void SelectNumber(int iStart, int iSum)
{
	int iNowSum = iSum + vecNumber[iStart];

	if (iNowSum == iNumber)
		++iAnswer;

	for (int i = iStart + 1; i < iSize; ++i)
		SelectNumber(i, iNowSum);
}

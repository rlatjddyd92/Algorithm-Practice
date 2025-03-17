#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecNumber;
vector<int> vecAnswer;

int iNumber = 0;
int iSelect = 0;

void Backtraking(int iStart, int iCount);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> iNumber >> iSelect;

	vecNumber.resize(iNumber);
	vecAnswer.resize(iSelect);

	for (int i = 0; i < iNumber; ++i)
		cin >> vecNumber[i];

	sort(vecNumber.begin(), vecNumber.end(), [](int iFirst, int iSecond) {return iFirst < iSecond;});

	Backtraking(0, 0);

	vecNumber.clear();
	vecAnswer.clear();

	return 0;
}

void Backtraking(int iStart, int iCount)
{
	if (iCount == iSelect)
	{
		for (int i = 0; i < iSelect; ++i)
			cout << vecAnswer[i] << " ";

		cout << "\n";
		return;
	}

	for (int i = iStart; i < iNumber; ++i)
	{
		vecAnswer[iCount] = vecNumber[i];
		Backtraking(i + 1, iCount + 1);
	}
}

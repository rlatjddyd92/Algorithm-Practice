#include <iostream>
#include <vector>

using namespace std;

vector<int> vecCount;

int main()
{
	int iCount = 0;
	int iCountTie = 0;

	string strInput = {};
	string strAnswer = {};

	cin >> strInput;

	vecCount.resize('z' - 'a' + 1);

	for (int i = 0; i < strInput.size(); ++i)
	{
		int iIndex = (strInput[i] - 'a');

		if ((iIndex < 0) || (iIndex >= vecCount.size()))
			iIndex = (strInput[i] - 'A');

		++vecCount[iIndex];
	}

	for (int i = 0; i < vecCount.size(); ++i)
	{
		if (iCount < vecCount[i])
		{
			iCount = vecCount[i];
			strAnswer = i + 'A';
			iCountTie = 0;
		}
		else if (iCount == vecCount[i])
		{
			++iCountTie;
		}
	}

	if (iCountTie > 0)
		cout << "?";
	else
		cout << strAnswer;

	vecCount.clear();

    return 0;
}
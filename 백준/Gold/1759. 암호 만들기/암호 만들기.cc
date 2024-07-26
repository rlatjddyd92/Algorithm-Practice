#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckAeiou(char szInput);

char szAeiou[5] = { 'a','e','i','o','u' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iPassword = 0;
	int iWord = 0;

	cin >> iPassword >> iWord;

	vector<int> vecIndex;
	vector<char> vecWord;

	vecIndex.resize(iPassword);
	vecWord.resize(iWord);

	for (int i = 0; i < iWord; ++i)
		cin >> vecWord[i];

	stable_sort(vecWord.begin(), vecWord.end());
	vecIndex[0] = -1;

	int iIndex = 0;
	int iAeiou = 0;

	while (iIndex >= 0)
	{
		++vecIndex[iIndex];

		if (vecIndex[iIndex] < iWord)
		{
			if (CheckAeiou(vecWord[vecIndex[iIndex]]))
				++iAeiou;

			/*for (auto& iter : vecIndex)
				cout << iter;

			cout << "\n";*/

			if ((vecIndex[0] == 1) && (vecIndex[1] + vecIndex[2] + vecIndex[3] == 0))
				int iCheck = 1;

			if ((iAeiou > 0) && (iAeiou <= iPassword - 2))
			{
				if (iIndex + 1 == iPassword)
				{
					for (auto& iter : vecIndex)
						cout << vecWord[iter];

					cout << "\n";
				}
			}
			
			if ((iIndex + 1 < iPassword) && (vecIndex[iIndex] + 1 < iWord))
			{
				vecIndex[iIndex + 1] = (vecIndex[iIndex]);
				++iIndex;
				continue;
			}
		}

		if ((vecIndex[iIndex] < iWord) && (CheckAeiou(vecWord[vecIndex[iIndex]])))
			--iAeiou;

		if (vecIndex[iIndex] + 1 >= iWord)
		{
			vecIndex[iIndex] = 0;
			--iIndex;
			if ((iIndex >= 0) && (CheckAeiou(vecWord[vecIndex[iIndex]])))
				--iAeiou;
		}
	}

	vecIndex.clear();
	vecWord.clear();

	return 0;
}

bool CheckAeiou(char szInput)
{
	for (auto& iter : szAeiou)
		if (iter == szInput)
			return true;

	return false;
}

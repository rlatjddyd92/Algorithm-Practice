#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	char szINput[51] = {};
	bool bSorry = 0;
	char szCenter = {};
	vector<int> vecCount(26);

	cin >> szINput;

	for (int i =0; i < strlen(szINput);++i)
	{
		++vecCount[szINput[i] - 65];
	}

	for (int i = 0; i < 26; ++i)
	{
		if ((0 == bSorry) && (1 == vecCount[i] % 2))
			bSorry = 1;
		else if ((1 == bSorry) && (1 == vecCount[i] % 2))
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (0 != vecCount[i])
			for (int j = 0; j < vecCount[i] / 2; ++j)
				cout << char(i + 65);

		if (1 == vecCount[i] % 2)
			szCenter = char(i + 65);
	}

	if (*"" != szCenter)
		cout << szCenter;

	for (int i = 25; i >=0; --i)
	{
		if (0 != vecCount[i])
			for (int j = 0; j < vecCount[i] / 2; ++j)
				cout << char(i + 65);
	}

	vecCount.clear();
	vector<int>().swap(vecCount);

	return 0;
}
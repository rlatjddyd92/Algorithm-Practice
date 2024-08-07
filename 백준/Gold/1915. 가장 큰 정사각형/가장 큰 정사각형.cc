#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iRow = 0;
	int iCol = 0;
	int iAnswer = 0;

	cin >> iRow >> iCol;

	list<int> Numlist;

	for (int i = 0; i <= iCol; ++i)
		Numlist.push_back(0);

	for (int i = 0; i < iRow; ++i)
	{
		string strInput = {};
		cin >> strInput;

		list<int> Templist;
		list<int>::iterator iter = Numlist.begin();
		Templist.push_back(0);

		for (int j = 0; j < iCol; ++j)
		{
			int iMin = 1001;

			if (*iter < iMin)
				iMin = *iter;
			++iter;
			if (*iter < iMin)
				iMin = *iter;
			if (Templist.back() < iMin)
				iMin = Templist.back();

			if (strInput[j] == '1')
				Templist.push_back(iMin + 1);
			else
				Templist.push_back(0);

			if (iAnswer < Templist.back())
				iAnswer = Templist.back();
		}

		Numlist.clear();
		Numlist = Templist;
		Templist.clear();
	}

	cout << iAnswer * iAnswer;

	Numlist.clear();

	return 0;
}
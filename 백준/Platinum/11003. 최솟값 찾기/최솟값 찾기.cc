#include <iostream>
#include <list>

using namespace std;

struct MINIMUM
{
	int iNum;
	int iStart;
	int iEnd;
};

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumbers = 0;
	int iLength = 0;

	cin >> iNumbers >> iLength;

	list<MINIMUM> Minlist;

	for (int i = 0; i < iNumbers; ++i)
	{
		int iInput = 0;

		cin >> iInput;

		while (!Minlist.empty())
		{
			if ((Minlist.back().iNum > iInput) && (Minlist.back().iEnd >= i))
			{
				Minlist.back().iEnd = i - 1;
				if (Minlist.back().iEnd < Minlist.back().iStart)
					Minlist.pop_back();
			}
			else
				break;
		}

		int iEndNum = i + iLength - 1;

		if (iEndNum >= iNumbers)
			iEndNum = iNumbers - 1;

		if (Minlist.empty())
			Minlist.push_back({ iInput , i, iEndNum });
		else if (Minlist.back().iNum == iInput)
			Minlist.back().iEnd = iEndNum;
		else if (Minlist.back().iNum < iInput)
			Minlist.push_back({ iInput , Minlist.back().iEnd + 1, iEndNum });
		else if (Minlist.back().iNum > iInput)
			Minlist.push_back({ iInput , i, iEndNum });


	}

	while (!Minlist.empty())
	{
		for (int i = Minlist.front().iStart; i <= Minlist.front().iEnd; ++i)
			cout << Minlist.front().iNum << " ";

		Minlist.pop_front();
	}

	Minlist.clear();

	return 0;
}
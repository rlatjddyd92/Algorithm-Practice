#include <iostream>
#include <list>

using namespace std;

struct CELL
{
	bool bIsBot;
	int iHp;
};

int main()
{
	int iNum = 0;
	int iLimit = 0;
	int iAnswer = 0;

	cin >> iNum >> iLimit;

	list<CELL> Uplist;
	list<CELL> Downlist;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		Uplist.push_back({ false,iInput });
	}

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		Downlist.push_front({ false,iInput });
	}

	while (iLimit > 0)
	{
		++iAnswer;
		 
		Downlist.push_back(Uplist.back());
		Downlist.back().bIsBot = false;
		Uplist.pop_back();
		Uplist.push_front(Downlist.front());
		Downlist.pop_front();

		for (list<CELL>::iterator iter = Uplist.end(); iter != Uplist.begin(); )
		{
			list<CELL>::iterator iterNext = iter;
			--iter;

			if ((iterNext == Uplist.end()) && ((*iter).bIsBot == true))
				(*iter).bIsBot = false;
			else if ((iterNext != Uplist.end()) && ((*iter).bIsBot == true))
			{
				if (((*iterNext).bIsBot == false) && ((*iterNext).iHp > 0))
				{
					(*iterNext).bIsBot = true;
					(*iter).bIsBot = false;
					--(*iterNext).iHp;
					if ((*iterNext).iHp <= 0)
						--iLimit;
				}
			}
		}

		if (Uplist.front().iHp > 0)
		{
			Uplist.front().bIsBot = true;
			--Uplist.front().iHp;
			if (Uplist.front().iHp <= 0)
				--iLimit;
		}
	}

	cout << iAnswer;

	Uplist.clear();
	Downlist.clear();

	return 0;
}
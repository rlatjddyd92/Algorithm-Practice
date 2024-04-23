#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void BackTraking(list<int>* list, int Start, int Num, int Index);

int main()
{
	int iNum = 0;
	int iIndex = 0;
	list<int> Numlist;

	cin >> iNum >> iIndex;

	BackTraking(&Numlist, 1, iNum, iIndex);

	Numlist.clear();
	list<int>().swap(Numlist);

	return 0;
}

void BackTraking(list<int>* list, int Start, int Num, int Index)
{
	for (int i = Start; i <= Num; ++i)
	{
		list->push_back(i);
		
		if (Index == list->size())
		{
			for_each(list->begin(), list->end(), [](int Dest) {cout << Dest << " "; });
			cout << "\n";
			list->pop_back();
			continue;
		}

		BackTraking(list, i + 1, Num, Index);
	}

	if (!list->empty())
		list->pop_back();
}

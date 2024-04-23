#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void BackTraking(list<int>* OutList, vector<int>* vecNum, int Num, int Index);

int main()
{
	int iNum = 0;
	int iIndex = 0;
	vector<int> vecNum;
	list<int> OutList;

	cin >> iNum >> iIndex;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecNum.push_back(iInput);
	}
	
	stable_sort(vecNum.begin(), vecNum.end(), [](int Dest, int Sorc) {return Dest < Sorc; });

	BackTraking(&OutList, &vecNum, iNum, iIndex);

	vecNum.clear();
	OutList.clear();

	vector<int>().swap(vecNum);
	list<int>().swap(OutList);

	return 0;
}

void BackTraking(list<int>* OutList, vector<int>* vecNum, int Num, int Index)
{

	for (vector<int>::iterator iter = vecNum->begin(); iter != vecNum->end(); ++iter)
	{
		bool bContinue = 0;
		for (list<int>::iterator iterList = OutList->begin(); iterList != OutList->end(); ++iterList)
			if (*iterList == *iter)
				bContinue = 1;
				
		if (1 == bContinue)
			continue;

		if (iter == vecNum->end())
			break;

		OutList->push_back(*iter);

		if (Index == OutList->size())
		{
			for_each(OutList->begin(), OutList->end(), [](int Dest) {cout << Dest << " "; });
			cout << "\n";
			OutList->pop_back();
			continue;
		}

		BackTraking(OutList, vecNum, Num, Index);
	}

	if (!OutList->empty())
		OutList->pop_back();
}

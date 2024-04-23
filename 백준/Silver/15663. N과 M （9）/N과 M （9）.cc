#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct NumInfo
{
	int iNum;
	int iCanUse;
};

void BackTraking(vector<NumInfo>* vecNum, list<int>* UseList, int iNum, int iIndex);

int main()
{
	int iNum = 0; 
	int iIndex = 0;

	cin >> iNum >> iIndex;

	vector<NumInfo> vecNum;
	list<int> UseList;

	for (int i = 0; i < iNum; ++i)
	{
		bool bNext = 0;
		int iInput = 0;
		cin >> iInput;

		for_each(vecNum.begin(), vecNum.end(), [&bNext, iInput](NumInfo &Dest) {if (Dest.iNum == iInput) { Dest.iCanUse += 1; bNext = 1; }});

		if (0 == bNext)
			vecNum.push_back({ iInput,1 });
	}

	stable_sort(vecNum.begin(), vecNum.end(), [](NumInfo Dest, NumInfo Sorc) {return Dest.iNum < Sorc.iNum; });

	BackTraking(&vecNum, &UseList, iNum, iIndex);

	vecNum.clear();
	UseList.clear();

	vector<NumInfo>().swap(vecNum);
	list<int>().swap(UseList);

	return 0;
}

void BackTraking(vector<NumInfo>* vecNum, list<int>* UseList, int iNum, int iIndex)
{
	for (vector<NumInfo>::iterator iter = vecNum->begin(); iter != vecNum->end(); ++iter)
	{
		if (0 == iter->iCanUse)
			continue;

		UseList->push_back(iter->iNum);
		--iter->iCanUse;

		if (iIndex == UseList->size())
		{
			for_each(UseList->begin(), UseList->end(), [](int Dest){cout << Dest << " "; });
			cout << "\n";
			UseList->pop_back();
			++iter->iCanUse;
			continue;
		}

		BackTraking(vecNum, UseList, iNum, iIndex);
	}

	if (!UseList->empty())
	{
		for (vector<NumInfo>::iterator iter = vecNum->begin(); iter != vecNum->end(); ++iter)
		{
			if (UseList->back() == iter->iNum)
			{
				UseList->pop_back();
				++iter->iCanUse;
				break;
			}
		}
	}
}

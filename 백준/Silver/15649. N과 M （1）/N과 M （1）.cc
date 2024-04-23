#include <iostream>
#include <list>

using namespace std;

void BackTraking(list<int>* coutlist, int* iUseNum, int iNum, int iIndex);

int main()
{
	int iNum = 0; 
	int iIndex = 0;

	cin >> iNum >> iIndex;

	int* iUseNum = new int[iNum + 1];
	for (int i = 0; i <= iNum;++i)
		iUseNum[i] = 0;

	list<int> Coutlist;

	BackTraking(&Coutlist, iUseNum, iNum, iIndex);

	Coutlist.clear();
	delete[]iUseNum;
	iUseNum = nullptr;

	return 0;
}

void BackTraking(list<int>* coutlist, int* iUseNum, int iNum, int iIndex)
{
	for (int i = 1; i <= iNum;++i)
	{
		if (1 == iUseNum[i])
			continue;

		coutlist->push_back(i);
		iUseNum[i] = 1;

		if (coutlist->size() == iIndex)
		{
			for (list<int>::iterator iter = coutlist->begin(); iter != coutlist->end(); ++iter)
				cout << *iter << " ";

			cout << "\n";

			iUseNum[coutlist->back()] = 0;
			coutlist->pop_back();
		}
		else
			BackTraking(coutlist, iUseNum, iNum, iIndex);
	}

	if (!coutlist->empty())
	{
		iUseNum[coutlist->back()] = 0;
		coutlist->pop_back();
	}
}

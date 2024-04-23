#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int iNum = 0;

	cin >> iNum;

	vector<int> vecOrigin(iNum);
	vector<int> vecSort(iNum);
	map<int, int> mapOrder;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		vecOrigin[i] = iInput;
		vecSort[i] = iInput;
	}

	stable_sort(vecSort.begin(), vecSort.end(), [](int Dest, int Sorc) {return Dest < Sorc; });

	int iOrder = 0;
	mapOrder.insert({ vecSort.front(), 0 });

	for (int i = 1; i < iNum; ++i)
	{
		if (mapOrder.end() == mapOrder.find(vecSort[i]))
		{
			++iOrder;
			mapOrder.insert({ vecSort[i] ,iOrder });
		}
	}

	for (int i = 0; i < iNum; ++i)
	{
		cout << mapOrder.find(vecOrigin[i])->second << " ";
	}

	vecOrigin.clear();
	vecSort.clear();
	mapOrder.clear();

	vector<int>().swap(vecOrigin);
	vector<int>().swap(vecSort);
	map<int, int>().swap(mapOrder);

	return 0;
}
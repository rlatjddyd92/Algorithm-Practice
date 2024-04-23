#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Answer
{
	int iNum;
	int iSame;
	vector<int> vecEnd;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	vector<Answer> vecAns(iNum + 1);
	list<int> Checklist;

	for (int i = 1; i <= iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		for (list<int>::iterator iter = Checklist.begin(); iter != Checklist.end();)
		{
			if (vecAns[(*iter)].iNum == iInput)
			{
				vecAns[(*iter)].vecEnd.push_back(i);

				if (*iter != 1)
				{
					--*iter;
					++iter;
					continue;
				}
			}
				
			iter = Checklist.erase(iter);
		}

		vecAns[i] = { iInput, i};
		vecAns[i].vecEnd.push_back(i);

		if (i != 1)
			Checklist.push_back(i - 1);
	}

	for (int i = iNum - 1; i > 0; --i)
		if (vecAns[i].iNum == vecAns[i + 1].iNum)
			vecAns[i].iSame = vecAns[i + 1].iSame;

	int iQuestion = 0;

	cin >> iQuestion;

	for (int i = 0; i < iQuestion; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		if (iEnd <= vecAns[iStart].iSame)
			cout << 1 << "\n";
		else
			cout << int(binary_search(vecAns[iStart].vecEnd.begin(), vecAns[iStart].vecEnd.end(), iEnd)) << "\n";
	}

	vecAns.clear();
	Checklist.clear();

	return 0;
}
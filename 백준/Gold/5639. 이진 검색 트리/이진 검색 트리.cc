#include <iostream>
#include <vector>
#include <list>

#define MAX 1000000 + 1

using namespace std;
list<int> Inputlist;
list<int> Answerlist;

int iStart = 0;

int SearchNode(int iBefore, int iMaxRight);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iInput = 0;

	while (1)
	{
		cin >> iInput;
		if (cin.fail() == true)
			break;
		Inputlist.push_back(iInput);
	}

	int iStart = Inputlist.front();
	Inputlist.pop_front();

	SearchNode(iStart, MAX);

	while (Answerlist.empty() == false)
	{
		cout << Answerlist.front() << "\n";
		Answerlist.pop_front();
	}

	Inputlist.clear();
	Answerlist.clear();

	return 0;
}

int SearchNode(int iParent, int iMaxRight)
{
	if (Inputlist.empty() == true)
	{
		Answerlist.push_back(iParent);
		return MAX;
	}
		
	int iNow = Inputlist.front();
	Inputlist.pop_front();

	if (iNow < iParent)
		iNow = SearchNode(iNow, iParent);
	
	if (iNow < iMaxRight)
		iNow = SearchNode(iNow, iMaxRight);

	Answerlist.push_back(iParent);
	return iNow;
}

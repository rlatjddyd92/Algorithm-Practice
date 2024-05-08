#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main()
{
	int iPeople = 0;
	int iParty = 0;
	int iNumTrue = 0;
	vector<list<int>> vecParty;
	vector<bool> vecVisited;
	vector<list<int>> vecPeople;
	vector<bool> vecKnown;
	int iCount = 0;
	int iAnswer = 0;
	bool bIsParty = false;
	queue<int> queueNext;

	cin >> iPeople >> iParty;

	vecParty.resize(iParty + 1);
	vecPeople.resize(iPeople + 1);
	vecVisited.resize(iParty + 1);
	vecKnown.resize(iPeople + 1);

	cin >> iNumTrue;

	for (int i = 0; i < iNumTrue; ++i)
	{
		int iTrue = 0;
		cin >> iTrue;
		queueNext.push(iTrue);
		vecKnown[iTrue] = true;
	}

	iCount = queueNext.size();

	for (int i = 1; i <= iParty; ++i)
	{
		int iNum = 0;
		cin >> iNum;

		for (int j = 0; j < iNum; ++j)
		{
			int iVisitor = 0;
			cin >> iVisitor;
			vecParty[i].push_back(iVisitor);
			vecPeople[iVisitor].push_back(i);
			
		}
	}

	while (!queueNext.empty())
	{
		if (!iCount)
		{
			if (bIsParty) bIsParty = false;
			else bIsParty = true;
			iCount = queueNext.size();
		}

		int iNow = queueNext.front();
		queueNext.pop();

		if (bIsParty)
		{
			vecVisited[iNow] = true;

			while (!vecParty[iNow].empty())
			{
				if (!vecKnown[vecParty[iNow].front()])
				{
					vecKnown[vecParty[iNow].front()] = true;
					queueNext.push(vecParty[iNow].front());
				}

				vecParty[iNow].pop_front();
			}
		}
		else
		{
			while (!vecPeople[iNow].empty())
			{
				if (!vecVisited[vecPeople[iNow].front()])
				{
					vecVisited[vecPeople[iNow].front()] = true;
					queueNext.push(vecPeople[iNow].front());
				}

				vecPeople[iNow].pop_front();
			}
		}

		--iCount;
	}

	for (int i = 1; i < vecVisited.size(); ++i)
		if (!vecVisited[i]) ++iAnswer;

	cout << iAnswer;

	for (int i = 0; i <= iParty; ++i)
		vecParty[i].clear();

	for (int i = 0; i <= iPeople; ++i)
		vecPeople[i].clear();

	vecParty.clear();
	vecPeople.clear();
	vecVisited.clear();
	vecKnown.clear();

	return 0;
}
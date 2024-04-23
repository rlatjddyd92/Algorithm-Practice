#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(list<int>* Linklist, vector<int>* vecRoot, int Root);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	list<int>* pLinklist = new list<int>[iNum + 1];
	vector<int> vecRoot(iNum + 1);

	for (int i = 0; i < iNum - 1;++i)
	{
		int iA = 0;
		int iB = 0;

		cin >> iA >> iB;

		pLinklist[iA].push_back(iB);
		pLinklist[iB].push_back(iA);
	}

	BFS(pLinklist, &vecRoot, 1);

	for (int i = 2; i <= iNum; ++i)
		cout << vecRoot[i] << "\n";

	for (int i = 0; i <= iNum; ++i)
		pLinklist[i].clear();

	vecRoot.clear();

	delete[]pLinklist;
	pLinklist = nullptr;

	return 0;
}

void BFS(list<int>* Linklist, vector<int>* vecRoot, int Root)
{
	queue<int> queueVisit;

	for (list<int>::iterator iter = Linklist[Root].begin(); iter != Linklist[Root].end();++iter)
	{
		vector<int>::iterator itervec = vecRoot->begin();
		itervec += Root;

		if (*itervec != *iter)
		{
			queueVisit.push(*iter);
			itervec = vecRoot->begin();
			itervec += *iter;
			*itervec = Root;
		}
	}

	while (!queueVisit.empty())
	{
		int iTemp = queueVisit.front();
		queueVisit.pop();
		BFS(Linklist, vecRoot, iTemp);
	}
}

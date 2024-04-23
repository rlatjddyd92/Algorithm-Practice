#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStudent = 0;
	int iRoute = 0;

	cin >> iStudent >> iRoute;

	vector<list<int>> vecNum;
	vector<int> vecFront;
	vecNum.resize(iStudent + 1);
	vecFront.resize(iStudent + 1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		++vecFront[iEnd];

		vecNum[iStart].push_back(iEnd);
	}

	queue<int> Nextqueue;

	for (int i = 1; i <= iStudent; ++i)
		if (!vecFront[i]) { Nextqueue.push(i); }

	while (!Nextqueue.empty())
	{
		int iVisit = Nextqueue.front();
		Nextqueue.pop();

		cout << iVisit << " ";

		while (!vecNum[iVisit].empty())
		{
			--vecFront[vecNum[iVisit].front()];

			if (!vecFront[vecNum[iVisit].front()])
				Nextqueue.push(vecNum[iVisit].front());

			vecNum[iVisit].pop_front();
		}
	}

	for (int i = 0; i <= iStudent; ++i)
		vecNum[i].clear();

	vecNum.clear();
	vecFront.clear();
	
	return 0;
}
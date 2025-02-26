#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct NODE
{
	queue<int> Nextlist;
	int iCheck = 0;
};

vector<NODE> vecNode;
queue<int> queueBFS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iNode = 0;
		int iRoute = 0;
		bool bIsFail = false;

		cin >> iNode >> iRoute;
		vecNode.resize(iNode + 1);
		for (int j = 0; j < iRoute; ++j)
		{
			int iStart = 0;
			int iEnd = 0;

			cin >> iStart >> iEnd;

			vecNode[iStart].Nextlist.push(iEnd);
			vecNode[iEnd].Nextlist.push(iStart);
		}

		for (int j = 1; j <= iNode; ++j)
		{
			if (vecNode[j].iCheck != 0)
				continue;

			queueBFS.push(j);
			vecNode[j].iCheck = 1;

			while (queueBFS.empty() == false)
			{
				int Now = queueBFS.front();
				queueBFS.pop();

				while (vecNode[Now].Nextlist.empty() == false)
				{
					int iNext = vecNode[Now].Nextlist.front();
					vecNode[Now].Nextlist.pop();

					if (vecNode[iNext].iCheck == 0)
					{
						vecNode[iNext].iCheck = vecNode[Now].iCheck * -1;
						queueBFS.push(iNext);
					}
					else if (vecNode[iNext].iCheck == vecNode[Now].iCheck)
					{
						bIsFail = true;
						break;
					}
				}
			}

			while (queueBFS.empty() == false)
				queueBFS.pop();

			if (bIsFail == true)
				break;
		}

		vecNode.clear();

		if (bIsFail == false)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}

	return 0;
}
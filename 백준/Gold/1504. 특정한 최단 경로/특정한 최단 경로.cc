#include <iostream>
#include <vector>
#include <queue>
#include <list>


using namespace std;

vector<list<pair<int, int>>> vecNode; // -비용, 목적지 
priority_queue<pair<int, int>> queueRoute; // -비용, 목적지 
vector<int> vecVisit; // 각 노드까지 최소비용

void FindRoute(int iStart);

int iNode = 0;
int iRoute = 0;

int iStartToA = 0;
int iStartToB = 0;
int iEndToA = 0;
int iEndToB = 0;
int iAToB = 0;

int iAnswer[2] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNode >> iRoute;

	vecNode.resize(iNode + 1);

	for (int i = 0; i < iRoute; ++i)
	{
		int iInput[3] = { 0, };
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		vecNode[iInput[0]].push_back({ -iInput[2],  iInput[1] });
		vecNode[iInput[1]].push_back({ -iInput[2],  iInput[0] });
	}

	int iA = 0;
	int iB = 0;

	cin >> iA >> iB;

	FindRoute(iA);
	iStartToA = vecVisit[1];
	iAToB = vecVisit[iB];
	iEndToA = vecVisit[iNode];

	

	vecVisit.clear();

	FindRoute(iB);
	iStartToB = vecVisit[1];
	iEndToB = vecVisit[iNode];

	


	if (iAToB == -1)
		iAnswer[0] = -1;
	else if ((iStartToA == -1) || (iEndToB == -1))
		iAnswer[0] = -1;
	else
		iAnswer[0] = iStartToA + iAToB + iEndToB;

	if (iAToB == -1)
		iAnswer[1] = -1;
	else if ((iStartToB == -1) || (iEndToA == -1))
		iAnswer[1] = -1;
	else
		iAnswer[1] = iStartToB + iAToB + iEndToA;

	if ((iAnswer[0] == -1) && (iAnswer[1] == -1))
		cout << -1;
	else if (iAnswer[0] == -1)
		cout << iAnswer[1];
	else if (iAnswer[1] == -1)
		cout << iAnswer[0];
	else
		cout << min(iAnswer[0], iAnswer[1]);

	for (auto& iter : vecNode)
		iter.clear();

	vecNode.clear();
	vecVisit.clear();

	return 0;
}

void FindRoute(int iStart)
{
	queueRoute.push({ 0, iStart });
	vecVisit.resize(iNode + 1, -1);
	vecVisit[iStart] = 0;

	while (queueRoute.empty() == false)
	{
		int iNow = queueRoute.top().second;
		queueRoute.pop();

		for (auto& iter : vecNode[iNow])
		{
			if ((vecVisit[iter.second] == -1) || (vecVisit[iter.second] > vecVisit[iNow] - iter.first))
			{
				vecVisit[iter.second] = vecVisit[iNow] - iter.first;
				queueRoute.push(iter);
			}
		}
	}
}

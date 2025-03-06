#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 크루스칼 

struct NODE
{
	int iCost = 0;
	pair<int, int> Path;

	bool operator < (const NODE Next) const
	{
		return iCost > Next.iCost;
	}
};

priority_queue<NODE> queueNext; // -비용, 노드 
vector<int> vecHead; // 부모 기록 

int FindHead(int iNode); 
void MergeGroup(int iFirst, int iSecond);
void MakePath();

int iNode = 0;
int iRoute = 0;
int iAnswer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNode;
	cin >> iRoute;

	for (int i = 0; i <= iNode; ++i)
		vecHead.push_back(i);

	for (int i = 0; i < iRoute; ++i)
	{
		int iInput[3] = { 0, };
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		queueNext.push({ iInput[2], {iInput[0], iInput[1]} });
	}

	MakePath();

	cout << iAnswer;

	return 0;
}

int FindHead(int iNode)
{
	if (vecHead[iNode] != iNode)
		vecHead[iNode] = FindHead(vecHead[iNode]);

	return vecHead[iNode];
}

void MergeGroup(int iFirst, int iSecond)
{
	vecHead[iFirst] = min(vecHead[iFirst], vecHead[iSecond]);
	vecHead[iSecond] = min(vecHead[iFirst], vecHead[iSecond]);
}

void MakePath()
{
	while ((queueNext.empty() == false) && (iNode > 1))
	{
		NODE Now = queueNext.top();
		queueNext.pop();

		if (FindHead(Now.Path.first) != FindHead(Now.Path.second))
		{
			MergeGroup(FindHead(Now.Path.first), FindHead(Now.Path.second));
			--iNode;
			iAnswer += Now.iCost;
		}
	}
}

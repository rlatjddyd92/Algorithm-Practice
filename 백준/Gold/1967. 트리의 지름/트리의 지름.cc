#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<priority_queue<pair<int, int>>> vecNode;
vector<int> vecMax;

int iAnswer = 0;

int DFSSerach(int iNext);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNode = 0;

	cin >> iNode;

	vecNode.resize(iNode + 1);
	vecMax.resize(iNode + 1, -1);

	for (int i = 1; i < iNode; ++i)
	{
		int iInput[3] = { 0, };

		cin >> iInput[0] >> iInput[1] >> iInput[2];
		vecNode[iInput[0]].push({ iInput[1] , iInput[2] });
		vecNode[iInput[1]].push({ iInput[0] , iInput[2] });
	}

	DFSSerach(1);

	cout << iAnswer;

	vecNode.clear();
	vecMax.clear();

	return 0;
}

int DFSSerach(int iNext)
{
	vecMax[iNext] = 0;

	while (vecNode[iNext].empty() == false)
	{
		pair<int, int> Next = vecNode[iNext].top();
		vecNode[iNext].pop();

		while (vecNode[iNext].empty() == false)
		{
			if (Next.first == vecNode[iNext].top().first)
				vecNode[iNext].pop();
			else
				break;
		}
			
		if (vecMax[Next.first] != -1)
			continue;

		Next.second += DFSSerach(Next.first);
		iAnswer = max(iAnswer, vecMax[iNext] + Next.second);
		vecMax[iNext] = max(vecMax[iNext], Next.second);
	}

	return vecMax[iNext];
}

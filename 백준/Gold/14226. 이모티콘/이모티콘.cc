#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> vecNode;

const int iMax = 10000;

struct BFS
{
	int iNow = -1;
	int iSecond = -1;
	int iDeposit = -1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iGoal = 0;
	int iAnswer = iMax;

	cin >> iGoal;

	vecNode.resize(iGoal + 1);

	for(auto& iter : vecNode)
		iter.resize(iGoal + 1, iMax);

	queue<BFS> queueBFS;

	queueBFS.push({ 1,0,0 });

	while (queueBFS.empty() == false)
	{
		BFS Now = queueBFS.front();
		queueBFS.pop();

		if (Now.iNow == iGoal)
			iAnswer = min(iAnswer, vecNode[Now.iNow][Now.iDeposit]);

		if (Now.iNow > 0)
			if (vecNode[Now.iNow - 1][Now.iDeposit] > Now.iSecond + 1)
			{
				vecNode[Now.iNow - 1][Now.iDeposit] = Now.iSecond + 1;
				queueBFS.push({ Now.iNow - 1, Now.iSecond + 1, Now.iDeposit });
			}

		if (vecNode[Now.iNow][Now.iNow] > Now.iSecond + 1)
		{
			vecNode[Now.iNow][Now.iNow] = Now.iSecond + 1;
			queueBFS.push({ Now.iNow, Now.iSecond + 1, Now.iNow });
		}
		
		if (Now.iNow + Now.iDeposit < iGoal + 1)
			if (vecNode[Now.iNow + Now.iDeposit][Now.iDeposit] > Now.iSecond + 1)
			{
				vecNode[Now.iNow + Now.iDeposit][Now.iDeposit] = Now.iSecond + 1;
				queueBFS.push({ Now.iNow + Now.iDeposit, Now.iSecond + 1, Now.iDeposit });
			}
	}

	cout << iAnswer;





	return 0;
}


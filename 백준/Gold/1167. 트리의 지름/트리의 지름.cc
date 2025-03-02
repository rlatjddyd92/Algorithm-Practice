#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct NODE
{
	priority_queue<pair<int, int>> queueRoute; // 넘버, 거리 
	priority_queue<pair<int, int>> queueDelete; // 넘버, 거리
	int iMax = 0; // 연결된 정점들 중 가장 먼 것 
};

queue<int> queueNext;
vector<NODE> vecNode;

int iAnswer = 0;

void CheckAnswer();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNodeNum = 0;

	cin >> iNodeNum;

	vecNode.resize(iNodeNum + 1);

	for (int i = 1; i <= iNodeNum; ++i)
	{
		bool bIsNode = true;
		int iHead = -1;
		int iNow = 0;

		while (1)
		{
			int iInput = 0;
			
			cin >> iInput;

			if (iInput == -1)
				break;
			
			if (iHead == -1)
			{
				iHead = iInput;
				continue;
			}

			if (bIsNode == true)
			{
				iNow = iInput;
			}
			else
			{
				vecNode[iHead].queueRoute.push({ iNow , iInput });
				vecNode[iNow].queueRoute.push({ iHead , iInput });
			}
				
			bIsNode = !bIsNode;
		}
	}

	for (int i = 1; i <= iNodeNum; ++i)
	{
		priority_queue<pair<int, int>> queueBuffer;


		while (vecNode[i].queueRoute.size() > 1)
		{
			pair<int, int> Now = vecNode[i].queueRoute.top();
			vecNode[i].queueRoute.pop();

			if (Now.first == vecNode[i].queueRoute.top().first)
				vecNode[i].queueRoute.pop();

			queueBuffer.push(Now);
		}

		while (queueBuffer.empty() == false)
		{
			vecNode[i].queueRoute.push(queueBuffer.top());
			queueBuffer.pop();
		}
	}

	for (int i = 1; i <= iNodeNum; ++i)
		if (vecNode[i].queueRoute.size() - vecNode[i].queueDelete.size() == 1)
			queueNext.push(i);

	while (queueNext.empty() == false)
		CheckAnswer();

	cout << iAnswer;

	vecNode.clear();

	return 0;
}

void CheckAnswer()
{
	int iMax[2] = { 0,0 };

	// queueRoute의 top과 queueDelete의 front가 같음 : 삭제 
	// queueRoute의 top과 queueDelete의 front가 다르다 OR queueRoute만 남음 : 거기로 가야 함 queueRoute가 2개 이상 남으면 이상한 것 

	NODE Now = vecNode[queueNext.front()];

	pair<int, int> Buffer = { -1,-1 };

	while ((Now.queueRoute.empty() == false) && (Now.queueDelete.empty() == false))
	{
		if (Now.queueRoute.top().first == Now.queueDelete.top().first)
		{
			if (iMax[0] <= Now.queueDelete.top().second)
			{
				iMax[1] = iMax[0];
				iMax[0] = Now.queueDelete.top().second;
			}
			else if (iMax[1] < Now.queueDelete.top().second)
				iMax[1] = Now.queueDelete.top().second;

			Now.queueRoute.pop();
			Now.queueDelete.pop();
		}
		else
		{
			Buffer = Now.queueRoute.top();
			Now.queueRoute.pop();
		}
	}

	if (Buffer.first != -1)
		Now.queueRoute.push(Buffer);
		

	if (Now.queueRoute.empty() == false)
	{
		vecNode[Now.queueRoute.top().first].queueDelete.push({ queueNext.front(), Now.queueRoute.top().second + iMax[0] });

		if (vecNode[Now.queueRoute.top().first].queueRoute.size() - vecNode[Now.queueRoute.top().first].queueDelete.size() == 1)
			queueNext.push(Now.queueRoute.top().first);
	}

	queueNext.pop();

	if (iMax[0] + iMax[1] > iAnswer)
		iAnswer = iMax[0] + iMax[1];
}

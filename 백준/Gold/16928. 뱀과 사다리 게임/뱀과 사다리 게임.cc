#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct BFS
{
	BFS(int Next, int Count) :
		iNext(0)
		, iCount(0)
	{
		iNext = Next;
		iCount = Count;
	}

	int iNext;
	int iCount;
};

struct CELL
{
	int iLadder; 
	int iSnake;
	int iCount;
};

int main()
{
	int iLadder = 0;
	int iSnake = 0;

	vector<CELL> vecCell;
	vecCell.resize(101);

	cin >> iLadder >> iSnake;

	for (int i = 0; i < iLadder; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		vecCell[iStart].iLadder = iEnd;
	}

	for (int i = 0; i < iSnake; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		vecCell[iStart].iSnake = iEnd;
	}

	queue<BFS> queueBFS;
	BFS tNew(1, 0);
	queueBFS.push(tNew);

	while (!queueBFS.empty())
	{
		int iNow = queueBFS.front().iNext;
		int iNowCount = queueBFS.front().iCount;

		queueBFS.pop();

		if (iNow == 100)
			continue;

		for (int i = 1; i <= 6; ++i)
		{
			if (iNow + i > 100)
				break;

			if (iNow + i == 100) 
				if ((!vecCell[iNow + i].iCount) || (vecCell[iNow + i].iCount > iNowCount + 1))
				{
					vecCell[iNow + i].iCount = iNowCount + 1;
					BFS tNew(iNow + i, iNowCount + 1);
					queueBFS.push(tNew);
					continue;
				}

			if (vecCell[iNow + i].iLadder + vecCell[iNow + i].iSnake)
			{
				int iJump = max(vecCell[iNow + i].iLadder, vecCell[iNow + i].iSnake);
				if ((!vecCell[iJump].iCount) || (vecCell[iJump].iCount > iNowCount + 1))
				{
					vecCell[iJump].iCount = iNowCount + 1;
					BFS tNew(iJump, iNowCount + 1);
					queueBFS.push(tNew);
					
				}
				
				continue;
			}

			if ((!vecCell[iNow + i].iCount) || (vecCell[iNow + i].iCount > iNowCount + 1))
			{
				vecCell[iNow + i].iCount = iNowCount + 1;
				BFS tNew(iNow + i, iNowCount + 1);
				queueBFS.push(tNew);
				continue;
			}
		}
	}

	cout << vecCell[100].iCount;

	vecCell.clear();
	
	return 0;
}
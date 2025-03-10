#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [브루트 포스 - 시뮬레이션 & BFS]
/*
1. 칸 수가 20*20까지이다 전체 칸 수 400 -> 모든 칸을 N 번 순회해도 16만번으로 충분 
2. 물고기는 작은 것만 먹을 수 있다 
3. 작은 것들 중 거리 우선 -> 열 인덱스 -> 행 인덱스 순으로 오름차순으로 먹는다 
4. 큰 물고기 지날 수 없다 -> 이거 떄문에 BFS
5. 더 먹을 것이 없으면 GG

필요한 것 


1. 아기 상어의 상태를 관리할 구조체 
2. 먹을 수 있는 물고기를 우선순위별로 저장하는 힙 
3. 바다 상태 표시하는 2차원 vector


순서 
1. 바다 초기 상태 입력 + 물고기를 사이즈 순 큐에 넣는다 
2. 매 턴마다 다음 진행 
 1) BFS를 돌리면서 최소 거리의 물고기만 취합해 큐에 넣는다 
 2) 큐가 비었으면 정지
 3) top을 먹는다 (top으로 상어 위치 이동 및 크기 연산)  
 4) 큐는 매 턴 리셋
*/


struct FISH_INFO
{
	int iSize = 0;
	int iDistance = 0;
	int iRow = 0;
	int iCol = 0;
};


struct SHARK_INFO
{
	int iRow = 0;
	int iCol = 0;
	int iSize = 2;
	int iExp = 2;

	void Eat_Fish(FISH_INFO Fish)
	{
		--iExp;

		if (iExp == 0)
		{
			++iSize;
			iExp = iSize;
		}

		iRow = Fish.iRow;
		iCol = Fish.iCol;

		//cout << Fish.iSize << " " << Fish.iDistance << " " << Fish.iRow << " " << Fish.iCol << " " << "\n";
	}
};

struct COMPARE_EAT_ORDER
{
	bool operator() (FISH_INFO First, FISH_INFO Second)
	{
		if (First.iRow > Second.iRow)
			return true;
		else if (First.iRow < Second.iRow)
			return false;

		if (First.iCol > Second.iCol)
			return true;
		else if (First.iCol < Second.iCol)
			return false;

		return false;
	}
};

vector<vector<int>> vecWater;
priority_queue<FISH_INFO, vector<FISH_INFO>, COMPARE_EAT_ORDER> queueNextEatFish;
vector<vector<int>> vecVisit;

SHARK_INFO BabyShark;

int iWaterSize = 0;
int iSecond = 0;

void Move_Shark();
pair<int,int> Check_Cell(int iRow, int iCol, int iDistance);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iWaterSize;

	vecWater.resize(iWaterSize);
	for (auto& iter : vecWater)
		iter.resize(iWaterSize);

	for (int i = 0; i < iWaterSize; ++i)
		for (int j = 0; j < iWaterSize; ++j)
		{
			cin >> vecWater[i][j];

			if (vecWater[i][j] == 9)
			{
				BabyShark.iRow = i;
				BabyShark.iCol = j;
				vecWater[i][j] = 0;
			}
		}
			
	Move_Shark();

	cout << iSecond;

	for (auto& iter : vecWater)
		iter.clear();

	vecWater.clear();


	return 0;
}

void Move_Shark()
{
	while (1)
	{
		queue<pair<int,int>> queueBFSSearch;

		queueBFSSearch.push({ BabyShark.iRow, BabyShark.iCol });

		vecVisit.resize(iWaterSize);
		for (auto& iter : vecVisit)
			iter.resize(iWaterSize, -1);

		vecVisit[BabyShark.iRow][BabyShark.iCol] = 0;

		while (queueBFSSearch.empty() == false)
		{
			pair<int, int> Now = queueBFSSearch.front();
			queueBFSSearch.pop();

			if ((queueNextEatFish.empty() == false) && (queueNextEatFish.top().iDistance < vecVisit[Now.first][Now.second]))
				break;

			if ((vecWater[Now.first][Now.second] > 0) && (vecWater[Now.first][Now.second] < BabyShark.iSize))
			{
				FISH_INFO NextFish = { vecWater[Now.first][Now.second], vecVisit[Now.first][Now.second], Now.first, Now.second };
				queueNextEatFish.push(NextFish);
			}

			pair<int, int> Next = { 0,0 };
				
			Next = Check_Cell(Now.first - 1, Now.second, vecVisit[Now.first][Now.second] + 1);
			if (Next.first != -1) queueBFSSearch.push(Next);

			Next = Check_Cell(Now.first + 1, Now.second, vecVisit[Now.first][Now.second] + 1);
			if (Next.first != -1) queueBFSSearch.push(Next);

			Next = Check_Cell(Now.first, Now.second - 1, vecVisit[Now.first][Now.second] + 1);
			if (Next.first != -1) queueBFSSearch.push(Next);

			Next = Check_Cell(Now.first, Now.second + 1, vecVisit[Now.first][Now.second] + 1);
			if (Next.first != -1) queueBFSSearch.push(Next);
		}

		for (auto& iter : vecVisit)
			iter.clear();

		vecVisit.clear();

		if (queueNextEatFish.empty() == true)
			return;

		FISH_INFO NextFish = queueNextEatFish.top();
		
		while(queueNextEatFish.empty() == false)
			queueNextEatFish.pop();

		BabyShark.Eat_Fish(NextFish);
		vecWater[NextFish.iRow][NextFish.iCol] = 0;
		iSecond += NextFish.iDistance;

		//cout << iSecond << "\n";
	}
}

pair<int, int> Check_Cell(int iRow, int iCol, int iDistance)
{
	pair<int, int> Return = { -1,-1 };

	if ((iRow < 0) || (iRow >= iWaterSize))
		return  { -1,-1 };

	if ((iCol < 0) || (iCol >= iWaterSize))
		return  { -1,-1 };

	if (vecVisit[iRow][iCol] != -1)
		return  { -1,-1 };

	if (vecWater[iRow][iCol] > BabyShark.iSize)
		return  { -1,-1 };

	vecVisit[iRow][iCol] = iDistance;

	return { iRow, iCol };
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
[아이디어] 

그리디 접근 + 크루스칼 

x,y,z 어느 쪽이던지 값만 비숫하면 된다 

1. x,y,z 별로 좌표값에 따라 정렬 
2. x->z까지 다음 작업 수행 
 1) [i], [i+1]의 차이 구하기 
 2) 1)에서 구한 것이 곧 해당 행성에 연결된 경로 중 최단 경로 후보이다 
 3) 만일 차이가 0이면 이미 연결된 것으로 보고 union_find로 묶어버린다 
 4) 1) 에서 구한 내용을 경로 목록에 저장한다 
3. 경로 목록을 거리에 때라 정렬한다 
4. 크루스칼 수행 


*/

struct ROUTE
{
	int iStart = 0;
	int iEnd = 0;
	long long llDistance = (long long)0;
};

vector<ROUTE> vecRoute; // 루트 목록 저장 
vector<vector<pair<int, long long>>> vecPlanet; //x,y,z 좌표 별로 (행성 인덱스, 좌표) 저장
vector<int> vecHead; // 유니온 파인드용 그룹 헤더 저장 
int iCount_ConnentedPlanet = 0;
int iAll_Planet = 0;
long long llAnswer = (long long)0;

int Find_Head(int iPlanet);
void Merge_Group(int iFirst, int iSecond);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iAll_Planet;

	vecPlanet.resize(3);
	vecHead.resize(iAll_Planet);

	for (int i = 0; i < iAll_Planet; ++i)
		vecHead[i] = i;

	for (auto& iter : vecPlanet)
		iter.resize(iAll_Planet);

	for (int i = 0; i < iAll_Planet; ++i)
	{
		cin >> vecPlanet[0][i].second >> vecPlanet[1][i].second >> vecPlanet[2][i].second;
		vecPlanet[0][i].first = vecPlanet[1][i].first = vecPlanet[2][i].first = i;
	}

	for (int i = 0; i < 3; ++i)
	{
		stable_sort(vecPlanet[i].begin(), vecPlanet[i].end(), [](pair<int, long long> iFirst, pair<int, long long> iSecond) { return iFirst.second < iSecond.second; });

		for (int j = 1; j < iAll_Planet; ++j)
		{
			long long llNowDistance = abs(vecPlanet[i][j - 1].second - vecPlanet[i][j].second);

			if (llNowDistance == 0)
			{
				Find_Head(vecPlanet[i][j - 1].first);
				Find_Head(vecPlanet[i][j].first);
				Merge_Group(vecPlanet[i][j - 1].first, vecPlanet[i][j].first);
			}
			else
			{
				vecRoute.push_back({ vecPlanet[i][j - 1].first , vecPlanet[i][j].first, llNowDistance });
			}
		}
	}
		

	stable_sort(vecRoute.begin(), vecRoute.end(), [](ROUTE First, ROUTE Second) { return First.llDistance < Second.llDistance; });

	for (int j = 0; j < vecRoute.size(); ++j)
	{
		if (Find_Head(vecRoute[j].iStart) != Find_Head(vecRoute[j].iEnd))
		{
			Merge_Group(vecRoute[j].iStart, vecRoute[j].iEnd);
			llAnswer += vecRoute[j].llDistance;
		}
	}
	
		
	cout << llAnswer;

	vecRoute.clear();
	vecHead.clear();

	for (auto& iter : vecPlanet)
		iter.clear();

	vecPlanet.clear();

	return 0;
}

int Find_Head(int iPlanet)
{
	if (vecHead[iPlanet] != iPlanet)
		vecHead[iPlanet] = Find_Head(vecHead[iPlanet]);

	return vecHead[iPlanet];
}

void Merge_Group(int iFirst, int iSecond)
{
	vecHead[vecHead[iFirst]] = min(vecHead[iFirst], vecHead[iSecond]);
	vecHead[vecHead[iSecond]] = vecHead[vecHead[iFirst]];
}

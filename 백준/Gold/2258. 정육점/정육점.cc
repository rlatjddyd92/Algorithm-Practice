#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 
/*
[아이디어] 

1. 가격 오름 순 -> 묶음 내림 순
 -> 가장 유리한 것 먼저 보기 

2. 연속으로 동일한 무게일 경우 
 -> 계속 가격과 무게를 더한다 
 -> 무게가 목표치를 초과하면 답 갱신 

3. 다음 무게가 나오면 
 -> 가격은 0으로 갱신
 2번을 다시 반복 

4. 최적의 답을 도출 


*/

vector<pair<int, int>> vecMeat; // 무게 가격 

int iNowMeat = 0;
int iNowCost = 0;
int iAnswer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;
	int iNeed = 0;

	cin >> iNumber >> iNeed;

	vecMeat.resize(iNumber);

	for (int i = 0; i < iNumber; ++i)
	{
		cin >> vecMeat[i].first >> vecMeat[i].second;
		iAnswer += vecMeat[i].second;
	}
		
	stable_sort(vecMeat.begin(), vecMeat.end(), [](pair<int, int> First, pair<int, int> Second)
		{
			if (First.second < Second.second)
				return true;
			else if (First.second > Second.second)
				return false;

			if (First.first > Second.first)
				return true;
			else if (First.first < Second.first)
				return false;

			return false;
		});
	
	iNowMeat = vecMeat[0].first;
	iNowCost = vecMeat[0].second;

	for (int i = 1; i < iNumber; ++i)
	{
		if (vecMeat[i - 1].second == vecMeat[i].second)
		{
			iNowMeat += vecMeat[i].first;
			iNowCost += vecMeat[i].second;
		}
		else
		{
			iNowMeat += vecMeat[i].first;
			iNowCost = vecMeat[i].second;
		}

		if ((iNowMeat >= iNeed) && (iAnswer > iNowCost))
		{
			iAnswer = iNowCost;
		}
			
	}

	if (iNowMeat < iNeed)
		cout << -1;
	else
		cout << iAnswer;

	vecMeat.clear();



	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

/*
힙 2개 사용 

1. 모든 강연 (일자 -> 페이 순) 
2. 선택 강연 (페이 순) 

1) 모든 강연을 1번 힙에 넣는다 
2) top을 빼서 선택 강연의 size보다 일자가 큰 지 확인 
3) 일자 크면 그대로 추가 
4) 일자 같거나 작으면 12번 힙의 페이 중 작은 것 빼기 
5) 2)번 부터 반복 

-> 2번 힙의 모든 페이 더하기 



*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iClass = 0;

	cin >> iClass;

	priority_queue<pair<int, int>> queueAllClass; // (-일자, 페이) 
	priority_queue<pair<int, int>> queueSelectedClass; // (-페이, 일자) 

	for (int i = 0; i < iClass; ++i)
	{
		pair<int, int> New = { 0,0 };
		cin >> New.second >> New.first;

		New.first *= -1;

		queueAllClass.push(New);
	}

	while (queueAllClass.empty() == false)
	{
		if (queueSelectedClass.size() < -queueAllClass.top().first)
		{
			pair<int, int> New = { 0,0 };
			New.first = -queueAllClass.top().second;
			New.second = queueAllClass.top().first;
			queueSelectedClass.push(New);
			queueAllClass.pop();
		}
		else
		{
			if (-queueSelectedClass.top().first < queueAllClass.top().second)
				queueSelectedClass.pop();
			else if (-queueSelectedClass.top().first >= queueAllClass.top().second)
				queueAllClass.pop();
		}
	}

	int iAnswer = 0;

	while (queueSelectedClass.empty() == false)
	{
		iAnswer -= queueSelectedClass.top().first;
		queueSelectedClass.pop();
	}

	cout << iAnswer;

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vecDate; // 월 별 누적 날짜 

pair<int, int> pairPrincess; // 시작일, 종료일 

priority_queue<pair<int, int>> queueFlower; // 꽃 정보 (-시작일, 종료일)
priority_queue<pair<int, int>> queueSelect; // 꽃 정보 (-선택수, 종료일)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vecDate.push_back(0);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 28);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 30);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 30);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 30);
	vecDate.push_back(vecDate.back() + 31);
	vecDate.push_back(vecDate.back() + 30);
	vecDate.push_back(vecDate.back() + 31);

	pairPrincess.first = vecDate[2] + 1; // 3월 1일
	pairPrincess.second = vecDate[11]; // 11월 30일

	int iFlowers = 0;
	cin >> iFlowers;

	for (int i = 0; i < iFlowers; ++i)
	{
		int iInput[4] = { 0,0,0,0 };
		pair<int, int> Input = { 0,0 };
		cin >> iInput[0] >> iInput[1];
		Input.first = -1 * (vecDate[iInput[0] - 1] + iInput[1]);
		cin >> iInput[2] >> iInput[3];
		Input.second = (vecDate[iInput[2] - 1] + iInput[3]);

		queueFlower.push(Input);
	}

	int iAnswer = iFlowers + 1;

	queueSelect.push({ 0, pairPrincess.first});

	while (queueFlower.empty() == false)
	{
		pair<int, int> Now = queueFlower.top();
		queueFlower.pop();

		while ((queueSelect.empty() == false) && ((queueSelect.top().second) < -Now.first))
				queueSelect.pop();

		if (queueSelect.empty() == true)
			break;

		if (queueSelect.top().second >= Now.second) // <- 이번에 살펴 보는 꽃이 지는 시점 보다 선택된 조합이 더 나중OR같은 시기에 지는 경우 
			continue; // 유리하지 않으므로 제외

		pair<int, int> Select = queueSelect.top();

		Select.second = Now.second;
		--Select.first;

		if (Select.second > pairPrincess.second)
		{
			if (-Select.first < iAnswer)
				iAnswer = -Select.first;
		}
		else 	
			queueSelect.push(Select);
	}

	if (iAnswer == iFlowers + 1)
		iAnswer = 0;

	cout << iAnswer;

	vecDate.clear();


	return 0;
}
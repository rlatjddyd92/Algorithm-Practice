#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct BALL
{
	int iOwner = 0;
	int iColor = 0;
	int iSize = 0;
};

vector<BALL> vecBall; // 공 정보, 정렬 대상 
vector<int> vecCount; // 현재까지 확인된 색깔 별 공의 크기 합산 
queue<pair<int, int>> queueBuffer; // 크기 같은 거 임시 저장 
vector<int> vecScore; // 공 별로 먹을 수 있는 크기 

int iNumber = 0;
int iSumSize = 0;
int iSumBuffer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNumber;
	vecBall.resize(iNumber);
	vecCount.resize(iNumber + 1);
	vecScore.resize(iNumber);

	for (int i = 0; i < iNumber; ++i)
	{
		vecBall[i].iOwner = i;
		cin >> vecBall[i].iColor >> vecBall[i].iSize;
	}

	stable_sort(vecBall.begin(), vecBall.end(), [](BALL First, BALL Second)
		{
			if (First.iSize < Second.iSize)
				return true;

			return false;
		});

	queueBuffer.push({ vecBall[0].iColor , vecBall[0].iSize });
	iSumBuffer += vecBall[0].iSize;

	for (int i = 1; i < iNumber; ++i)
	{
		if (vecBall[i - 1].iSize < vecBall[i].iSize)
		{
			while (queueBuffer.empty() == false)
			{
				vecCount[queueBuffer.front().first] += queueBuffer.front().second;
				queueBuffer.pop();
			}
			iSumSize += iSumBuffer;
			iSumBuffer = 0;
		}

		vecScore[vecBall[i].iOwner] = iSumSize - vecCount[vecBall[i].iColor];

		queueBuffer.push({ vecBall[i].iColor , vecBall[i].iSize });
		iSumBuffer += vecBall[i].iSize;
	}

	while (queueBuffer.empty() == false)
	{
		vecCount[queueBuffer.front().first] += queueBuffer.front().second;
		queueBuffer.pop();
	}

	for (auto& iter : vecScore)
		cout << iter << '\n';

	vecBall.clear();
	vecCount.clear();


	return 0;
}
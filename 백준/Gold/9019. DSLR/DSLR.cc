#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<pair<int, int>> vecNum;
vector<int> vecBefore;
queue<pair<int, int>> queueBFS;

void Make_Next(pair<int, int> Now, int DSLR);
void SearchNum();
void CheckConmmand();

int iStart = 0;
int iEnd = 0;
int iAnswer = -1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		iStart = 0;
		iEnd = 0;
		iAnswer = -1;

		vecNum.resize(10000);
		vecBefore.resize(10000);
		while (queueBFS.empty() == false)
			queueBFS.pop();

		cin >> iStart >> iEnd;
		queueBFS.push({ iStart , 0 });

		SearchNum();
		CheckConmmand();

		vecNum.clear();
		vecBefore.clear();
	}

	return 0;
}

void Make_Next(pair<int, int> Now, int DSLR)
{
	int iNext = 0;

	if (DSLR == 0) iNext = (Now.first * 2) % 10000;
	else if (DSLR == 1) iNext = (Now.first - 1) == -1 ? 9999 : (Now.first - 1);
	else if (DSLR == 2) iNext = ((Now.first * 10) % 10000) + (Now.first / 1000);
	else if (DSLR == 3) iNext = (Now.first / 10) + ((Now.first % 10) * 1000);

	if ((vecNum[iNext].first == 0) || (vecNum[iNext].first > Now.second + 1))
	{
		vecNum[iNext].first = Now.second + 1;
		vecNum[iNext].second = DSLR;
		vecBefore[iNext] = Now.first;
		queueBFS.push({ iNext , Now.second + 1 });
	}
}

void SearchNum()
{
	while (queueBFS.empty() == false)
	{
		pair<int,int> Now = queueBFS.front();
		queueBFS.pop();

		if (vecNum[Now.first].first < Now.second)
			continue;

		if (Now.first == iEnd)
		{
			if ((iAnswer != -1) && (iAnswer > Now.second))
				iAnswer = Now.second;
			continue;
		}

		for (int i = 0; i < 4; ++i)
			Make_Next(Now, i);
	}
}

void CheckConmmand()
{
	stack<char> stackAnswer;
	int iNow = iEnd;

	while (iNow != iStart)
	{
		char Command = {};

		if (vecNum[iNow].second == 0) Command = 'D';
		else if (vecNum[iNow].second == 1) Command = 'S';
		else if (vecNum[iNow].second == 2) Command = 'L';
		else if (vecNum[iNow].second == 3) Command = 'R';

		stackAnswer.push(Command);

		iNow = vecBefore[iNow];
	}

	while (stackAnswer.empty() == false)
	{
		cout << stackAnswer.top();
		stackAnswer.pop();
	}
		
	cout << "\n";
}

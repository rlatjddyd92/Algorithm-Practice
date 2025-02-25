#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

stack<pair<int, int>> stackAnswer;

vector<vector<pair<int, int>>> vecMap;
vector<vector<int>> vecDistance;
vector<vector<int>> vecVisit;

vector<stack<pair<int, int>>> vecHouse_MinDistance;

vector<pair<int, int>> vecShop;
vector<pair<int, int>> vecHouse;

void Initialize_Distance(int iShop);
bool Check_Cell(int iX, int iY, int iShopNum);

void StackCommand(int iStart);
void PushAnswerStack(int iShop);
void PopAnswerStack(int iShop);

int iGoal = 0;
int iAnswer = -1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSize = 0;
	

	int iShop = 0;
	int iHouse = 0;

	vecShop.push_back({ 0,0 });
	vecHouse.push_back({ 0,0 });

	cin >> iSize >> iGoal;

	vecMap.resize(iSize);
	vecVisit.resize(iSize);
	for (int i = 0; i < iSize; ++i)
	{
		vecMap[i].resize(iSize);
		vecVisit[i].resize(iSize);

		for (int j = 0; j < iSize; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			if (iInput == 1)
			{
				vecMap[i][j].first = ++iHouse;
				vecHouse.push_back({ i,j });
			}
			else if (iInput == 2)
			{
				vecMap[i][j].second = ++iShop;
				vecShop.push_back({ i,j });
			}
		}
	}

	vecDistance.resize(vecHouse.size());
	for (int i = 0; i < vecHouse.size(); ++i)
	{
		vecDistance[i].resize(vecShop.size());
	}
		

	vecHouse_MinDistance.resize(vecHouse.size());

	for (int i = 1; i < vecShop.size(); ++i)
		Initialize_Distance(i);

	StackCommand(1);

	cout << iAnswer;

	for (auto& iter : vecMap)
		iter.clear();

	for (auto& iter : vecDistance)
		iter.clear();

	vecMap.clear();
	vecDistance.clear();
	vecHouse_MinDistance.clear();
	vecShop.clear();
	vecHouse.clear();

	return 0;
}

void Initialize_Distance(int iShop)
{
	queue<pair<int, int>> queueBFS;
	queueBFS.push({ vecShop[iShop].first,  vecShop[iShop].second });
	pair<int, int> ShopLocation = queueBFS.front();

	int iCountHouse = 0;

	while ((queueBFS.empty() == false) && (iCountHouse < vecShop.size()))
	{
		pair<int, int> Now = queueBFS.front();
		queueBFS.pop();

		if (Check_Cell(Now.first - 1, Now.second, iShop))
			queueBFS.push({ Now.first - 1, Now.second });

		if (Check_Cell(Now.first, Now.second - 1, iShop))
			queueBFS.push({ Now.first, Now.second - 1 });

		if (Check_Cell(Now.first + 1, Now.second, iShop))
			queueBFS.push({ Now.first + 1, Now.second });

		if (Check_Cell(Now.first, Now.second + 1, iShop))
			queueBFS.push({ Now.first, Now.second + 1 });
	}
}

bool Check_Cell(int iX, int iY, int iShopNum)
{
	if ((iX < 0) || (iX >= vecMap.size()))
		return false;

	if ((iY < 0) || (iY >= vecMap.size()))
		return false;

	if (vecVisit[iX][iY] == iShopNum)
		return false;

	if (vecMap[iX][iY].first != 0)
	{
		pair<int, int> ShopLocation = vecShop[iShopNum];
		int iDistance = abs(ShopLocation.first - iX) + abs(ShopLocation.second - iY);
		vecDistance[vecMap[iX][iY].first][iShopNum] = iDistance;
	}

	vecVisit[iX][iY] = iShopNum;

	return true;
}

void StackCommand(int iStart)
{
	for (int i = iStart; i < vecShop.size(); ++i)
	{
		if (iGoal > stackAnswer.size())
		{
			int iRemain = iGoal - stackAnswer.size();
			if (i + iRemain <= vecShop.size())
			{
				PushAnswerStack(i);
				StackCommand(i + 1);
				PopAnswerStack(i);
			}
		}
	}
}

void PushAnswerStack(int iShop)
{
	int iDfference = 0;

	for (int i = 1; i < vecHouse_MinDistance.size(); ++i)
		if ((vecHouse_MinDistance[i].empty() == true) || (vecHouse_MinDistance[i].top().second >= vecDistance[i][iShop]))
		{
			iDfference += vecDistance[i][iShop];
			if (vecHouse_MinDistance[i].empty() == false) iDfference -= vecHouse_MinDistance[i].top().second;
			vecHouse_MinDistance[i].push({ iShop , vecDistance[i][iShop] });
		}
			
	if (stackAnswer.empty() == false)
		iDfference = stackAnswer.top().second + iDfference;

	stackAnswer.push({ iShop , iDfference });

	//if (stackAnswer.size() == iGoal)
		if ((iAnswer == -1) || (iAnswer > stackAnswer.top().second))
			iAnswer = stackAnswer.top().second;
}

void PopAnswerStack(int iShop)
{
	for (int i = 1; i < vecHouse_MinDistance.size(); ++i)
		if ((vecHouse_MinDistance[i].empty() == false) && (vecHouse_MinDistance[i].top().first == iShop))
			vecHouse_MinDistance[i].pop();

	if (stackAnswer.empty() == false)
		stackAnswer.pop();
}

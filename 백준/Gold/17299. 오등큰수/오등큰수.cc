#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vecCount;
vector<pair<int,int>> vecNum;

stack<pair<int, int>> stackCheck; // 숫자, 가져온 인덱스 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	vecCount.resize(1000001);
	vecNum.resize(1000001);

	vecCount[0] = 1000001;

	for (int i = 1; i <= iNum; ++i)
	{
		cin >> vecNum[i].first;
		++vecCount[vecNum[i].first];
	}
		
	stackCheck.push({ 0 , 0 });

	for (int i = 1; i <= iNum; ++i)
	{
		while ((stackCheck.empty() == false) && (vecCount[vecNum[i].first] > vecCount[stackCheck.top().first]))
		{
			vecNum[stackCheck.top().second].second = vecNum[i].first;
			stackCheck.pop();
		}

		stackCheck.push({ vecNum[i].first , i });
	}

	while (stackCheck.empty() == false)
	{
		vecNum[stackCheck.top().second].second = -1;
		stackCheck.pop();
	}

	for (int i = 1; i <= iNum; ++i)
		cout << vecNum[i].second << " ";

	vecCount.clear();
	vecNum.clear();

	return 0;
}
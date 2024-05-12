#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct SInfo
{
	int iBefore;
	map<int, int> mapNext;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSinger = 0;
	int iPD = 0;

	cin >> iSinger >> iPD;

	vector<SInfo> vecSinger;
	vecSinger.resize(iSinger + 1);

	for (int i = 1; i <= iSinger; ++i)
	{
		vecSinger[i].iBefore = 0;
	}
		
	for (int i = 0; i < iPD; ++i)
	{
		int iNumber = 0; 

		cin >> iNumber;

		int iBeforeNum = 0;

		for (int j = 0; j < iNumber; ++j)
		{
			int iNowNum = 0; 
			cin >> iNowNum;

			if (iBeforeNum)
			{
				if (vecSinger[iBeforeNum].mapNext.find(iNowNum) == vecSinger[iBeforeNum].mapNext.end())
				{
					vecSinger[iBeforeNum].mapNext.insert({ iNowNum ,iNowNum });
					++vecSinger[iNowNum].iBefore;
				}
			}
				
			iBeforeNum = iNowNum;
		}
	}

	queue<int> queueNext;

	for (int i = 1; i <= iSinger; ++i)
		if (!vecSinger[i].iBefore)
			queueNext.push(i);

	queue<int> queueAnswer;

	while (!queueNext.empty())
	{
		int iNowSinger = queueNext.front();
		queueAnswer.push(iNowSinger);
		queueNext.pop();

		for (auto& iter : vecSinger[iNowSinger].mapNext)
		{
			if (vecSinger[iter.first].iBefore == 1)
				queueNext.push(iter.first);

			--vecSinger[iter.first].iBefore;
		}
	}

	if (queueAnswer.size() != iSinger)
	{
		cout << 0;
	}
	else
	{
		while (!queueAnswer.empty())
		{
			cout << queueAnswer.front() << "\n";
			queueAnswer.pop();
		}
	}
	
	for (auto iter : vecSinger)
	{
		iter.mapNext.clear();
	}

	vecSinger.clear();

	return 0;
}
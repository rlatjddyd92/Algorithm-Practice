#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>

using namespace std;

struct PAL
{
	int iStart;
	int iEnd;
};

struct SERACH
{
	int iNow;
	int iCount;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strInput = {};
	cin >> strInput;

	int iAnswer = strInput.size();

	vector<list<int>> vecRoute;
	vecRoute.resize(strInput.size());
	vector<int> vecVisit;
	vecVisit.resize(strInput.size());

	for (int i = 0; i < strInput.size(); ++i)
	{
		int iStart = i;
		int iEnd = i;
		bool bCheckSame = true;
		while (1)
		{
			vecRoute[iStart].push_back(iEnd + 1);
			if (iEnd + 1 == strInput.size())
				break;

			++iEnd;
			if ((bCheckSame)&&(strInput[iEnd] == strInput[i]))
				continue;
			else if ((bCheckSame) && (strInput[iEnd] != strInput[i]))
				bCheckSame = false;
				
			if (iStart > 0)
			{
				--iStart;
				if (strInput[iEnd] == strInput[iStart])
					continue;
			}

			break;
		}
	}

	queue<SERACH> queueSerach;
	queueSerach.push({ 0,0 });

	while (!queueSerach.empty())
	{
		int iNow = queueSerach.front().iNow;
		int iNowCount = queueSerach.front().iCount;
		queueSerach.pop();

		if (iNowCount + 1 >= iAnswer)
			continue;

		for (auto& iter : vecRoute[iNow])
		{
			if (iter >= strInput.size())
			{
				if (iNowCount + 1 < iAnswer)
					iAnswer = iNowCount + 1;
			}
			else if ((vecVisit[iter] == 0) || (vecVisit[iter] > iNowCount + 1))
			{
				queueSerach.push({ iter ,iNowCount + 1 });
				vecVisit[iter] = iNowCount + 1;
			}
		}
	}

	cout << iAnswer;

	for (int i = 0; i < strInput.size(); ++i)
		vecRoute[i].clear();

	vecRoute.clear();
	vecVisit.clear();

	return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct CHANGE
{
	pair<int, int> Index;
	int iNum = 0;
};


vector<int> Alist;
vector<int> Blist;
vector<CHANGE> vecChange;
list<CHANGE> Answerlist;

vector<vector<int>> vecLCS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;
	Alist.push_back(-1);
	for (int i = 0; i < iNum; ++i)
	{
		int iInput;
		cin >> iInput;
		Alist.push_back(iInput);
	}

	cin >> iNum;
	Blist.push_back(-1);
	for (int i = 0; i < iNum; ++i)
	{
		int iInput;
		cin >> iInput;
		Blist.push_back(iInput);
	}

	vecLCS.resize(Alist.size());

	for(auto& iter : vecLCS)
		iter.resize(Blist.size());

	

	for (int i = 1; i < Alist.size(); ++i)
	{
		for (int j = 1; j < Blist.size(); ++j)
		{
			int iNew = max(vecLCS[i - 1][j], vecLCS[i][j - 1]);

			if (Alist[i] == Blist[j])
			{
				iNew = max(vecLCS[i - 1][j - 1] + 1, iNew);
				vecChange.push_back({ { i,j }, Alist[i] });
			}
				
			vecLCS[i][j] = iNew;			
		}
	}

	stable_sort(vecChange.begin(), vecChange.end(), [](CHANGE First, CHANGE Second)
		{
			if (First.iNum > Second.iNum)
				return true;
			else if (First.iNum == Second.iNum)
			{
				if ((First.Index.first < Second.Index.first) && (First.Index.second < Second.Index.second))
					return true;
				else 
					return false;
			}
				
			return false;
		});


	for (auto& iter : vecChange)
	{
		if (Answerlist.empty() == true)
			Answerlist.push_back(iter);
		else if (Answerlist.back().iNum == iter.iNum)
		{
			if ((Answerlist.back().Index.first < iter.Index.first) && ((Answerlist.back().Index.second < iter.Index.second)))
				Answerlist.push_back(iter);
		}
		else if ((Answerlist.back().Index.first < iter.Index.first)&&((Answerlist.back().Index.second < iter.Index.second)))
			Answerlist.push_back(iter);
	}

	cout << Answerlist.size() << "\n";

	while (Answerlist.empty() == false)
	{
		cout << Answerlist.front().iNum << " ";
		Answerlist.pop_front();
	}

	Alist.clear();
	Blist.clear();
	Answerlist.clear();

	return 0;
}
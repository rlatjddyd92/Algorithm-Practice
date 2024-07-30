#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCapacity = 0;
	int iNum = 0;
	int iAnswer = 0;

	cin >> iCapacity >> iNum;

	map<int, int> mapTap;
	vector<queue<int>> vecNum;
	vector<int> vecOrder;
	vecNum.resize(iNum + 1);
	vecOrder.resize(iNum);

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecNum[iInput].push(i);
		vecOrder[i] = iInput;
	}

	for (int i = 0; i < iNum; ++i)
	{
		if (mapTap.find(vecOrder[i]) == mapTap.end())
		{
			if (mapTap.size() >= iCapacity)
			{
				int iMin = 0;
				int iSelect = 0;
				for (auto& pair : mapTap)
				{
					if (vecNum[pair.second].empty())
					{
						iSelect = pair.second;
						break;
					}
					else if (vecNum[pair.second].front() > iMin)
					{
						iMin = vecNum[pair.second].front();
						iSelect = pair.second;
					}
				}

				mapTap.erase(iSelect);
				++iAnswer;
			}
			mapTap.insert({ vecOrder[i] ,vecOrder[i] });
		}
		vecNum[vecOrder[i]].pop();
	}

	cout << iAnswer;

	mapTap.clear();
	vecNum.clear();
	vecOrder.clear();

	return 0;
}
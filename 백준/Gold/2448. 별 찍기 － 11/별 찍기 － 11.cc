#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iSize = 0;
	int iRow = 0;

	cin >> iNum; 

	iSize = ((iNum / 3) * 5) + ((iNum / 3) - 1);

	vector<vector<bool>> vecDraw;

	vecDraw.resize(iNum);

	for (int i = 0; i < iNum; ++i)
		vecDraw[i].resize(iSize);

	list<int> Pointlist;

	Pointlist.push_back(iSize / 2);
	vecDraw[0][iSize / 2] = true;

	while (iRow < iNum - 1)
	{
		int iCount = Pointlist.size();
			
		for (int i = 0; i < iCount; ++i)
		{
			int iNow = Pointlist.front();
			Pointlist.pop_front();

			if (iRow % 3 == 1)
			{
				vecDraw[iRow + 1][iNow - 1] = true;
				vecDraw[iRow + 1][iNow] = true;
				vecDraw[iRow + 1][iNow + 1] = true;

				if (i % 2 == 1)
					Pointlist.push_back(iNow + 1);
				else 
					Pointlist.push_back(iNow - 1);
			}
			else if (iRow % 3 == 0)
			{
				vecDraw[iRow + 1][iNow - 1] = true;
				vecDraw[iRow + 1][iNow + 1] = true;
				Pointlist.push_back(iNow - 1);
				Pointlist.push_back(iNow + 1);
			}
			else if (iRow % 3 == 2)
			{
				if (i % 2 == 0)
				{
					if (Pointlist.back() != iNow - 1)
					{
						vecDraw[iRow + 1][iNow - 1] = true;
						Pointlist.push_back(iNow - 1);
					}
					else
					{
						vecDraw[iRow + 1][iNow - 1] = false;
						Pointlist.pop_back();
					}
				}
				else
				{
					vecDraw[iRow + 1][iNow + 1] = true;
					Pointlist.push_back(iNow + 1);
				}
			}
		}
		++iRow;
	}

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if (vecDraw[i][j] == true)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < iNum; ++i)
		vecDraw[i].clear();

	vecDraw.clear();

	return 0;
}
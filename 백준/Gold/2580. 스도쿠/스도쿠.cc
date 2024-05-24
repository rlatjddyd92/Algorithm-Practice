#include <iostream>
#include <vector>
#include <list>

#define ROWNUM 3
#define NUMBERS 9

using namespace std;

struct FINDER
{
	int iNowRow;
	int iNowCol;
	int iNumber = 1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<bool>> vecRow;
	vector<vector<bool>> vecCol;
	vector<vector<bool>> vecSqure;

	vector<vector<int>> vecAnswer;

	vecRow.resize(NUMBERS);
	vecCol.resize(NUMBERS);
	vecSqure.resize(NUMBERS);
	vecAnswer.resize(NUMBERS);

	for (int i = 0; i < NUMBERS; ++i)
	{
		vecRow[i].resize(NUMBERS + 1);
		vecCol[i].resize(NUMBERS + 1);
		vecSqure[i].resize(NUMBERS + 1);
		vecAnswer[i].resize(NUMBERS);
	}

	list<FINDER> Finderlist;

	for (int i = 0; i < NUMBERS; ++i)
	{
		for (int j = 0; j < NUMBERS; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			if (!iInput)
				Finderlist.push_back({ i,j,1 });

			vecRow[i][iInput] = true;
			vecCol[j][iInput] = true;
			vecSqure[(i / ROWNUM) * ROWNUM + (j / ROWNUM)][iInput] = true;

			vecAnswer[i][j] = iInput;
		}
	}

	list<FINDER>::iterator iter = Finderlist.begin();

	while(iter != Finderlist.end())
	{
		bool bSuccess = false;

		for (int i = iter->iNumber; i <= 9; ++i)
		{
			int iCheck = 0;
			iCheck += vecRow[iter->iNowRow][i];
			iCheck += vecCol[iter->iNowCol][i];
			iCheck += vecSqure[(iter->iNowRow / ROWNUM) * ROWNUM + (iter->iNowCol / ROWNUM)][i];

			if (!iCheck)
			{
				bSuccess = true;
				iter->iNumber = i;
				vecRow[iter->iNowRow][i] = true;
				vecCol[iter->iNowCol][i] = true;
				vecSqure[(iter->iNowRow / ROWNUM) * ROWNUM + (iter->iNowCol / ROWNUM)][i] = true;
				break;
			}
		}

		if (bSuccess)
		{
			++iter;
		}
		else
		{
			iter->iNumber = 1;
			--iter;
			vecRow[iter->iNowRow][iter->iNumber] = false;
			vecCol[iter->iNowCol][iter->iNumber] = false;
			vecSqure[(iter->iNowRow / ROWNUM)* ROWNUM + (iter->iNowCol / ROWNUM)][iter->iNumber] = false;
			++iter->iNumber;
		}
	}

	for (auto& iter : Finderlist)
		vecAnswer[iter.iNowRow][iter.iNowCol] = iter.iNumber;

	for (int i = 0; i < NUMBERS; ++i)
	{
		for (int j = 0; j < NUMBERS; ++j)
			cout << vecAnswer[i][j] << " ";

		cout << "\n";
	}
		
	for (int i = 0; i < NUMBERS; ++i)
	{
		vecRow[i].clear();
		vecCol[i].clear();
		vecSqure[i].clear();
		vecAnswer[i].clear();
	}

	vecRow.clear();
	vecCol.clear();
	vecSqure.clear();
	vecAnswer.clear();

	return 0;
}
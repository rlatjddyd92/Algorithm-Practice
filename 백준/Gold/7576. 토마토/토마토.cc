#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Location
{
	int iRow;
	int iCol;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCol = 0;
	int iRow = 0;
	int iRawTomato = 0;

	cin >> iCol >> iRow;

	vector<vector<int>> vecTomato;
	vecTomato.resize(iRow);

	queue<Location> Nextqueue;

	for (int i = 0; i < iRow; ++i)
	{
		vecTomato[i].resize(iCol);

		for (int j = 0; j < iCol; ++j)
		{
			cin >> vecTomato[i][j];
			if (vecTomato[i][j] == 1)
				Nextqueue.push({ i, j });
			if (vecTomato[i][j] == 0)
				++iRawTomato;
		}
	}

	int iDate = 0;
	
	while (!Nextqueue.empty())
	{
		int iCount = Nextqueue.size();

		for (int i = 0; i < iCount; ++i)
		{
			Location Next = Nextqueue.front();
			Nextqueue.pop();

			if ((Next.iRow > 0) && (!vecTomato[Next.iRow - 1][Next.iCol]))
			{
				Nextqueue.push({ Next.iRow - 1 , Next.iCol });
				vecTomato[Next.iRow - 1][Next.iCol] = 1;
			}
				

			if ((Next.iCol > 0) && (!vecTomato[Next.iRow][Next.iCol - 1]))
			{
				Nextqueue.push({ Next.iRow , Next.iCol - 1 });
				vecTomato[Next.iRow][Next.iCol - 1] = 1;
			}
				

			if ((Next.iRow < iRow - 1) && (!vecTomato[Next.iRow + 1][Next.iCol]))
			{
				Nextqueue.push({ Next.iRow + 1 , Next.iCol });
				vecTomato[Next.iRow + 1][Next.iCol] = 1;
			}
				

			if ((Next.iCol < iCol - 1) && (!vecTomato[Next.iRow][Next.iCol + 1]))
			{
				Nextqueue.push({ Next.iRow , Next.iCol + 1 });
				vecTomato[Next.iRow][Next.iCol + 1] = 1;
			}
				
		}

		iRawTomato -= Nextqueue.size();
		if (Nextqueue.size()) ++iDate;
	}

	if (iRawTomato != 0)
		cout << -1;
	else
		cout << iDate;

	for (int i = 0; i < iRow; ++i)
		vecTomato[i].clear();

	vecTomato.clear();

	return 0;
}
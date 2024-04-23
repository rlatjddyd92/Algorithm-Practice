#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Location
{
	int iFloor;
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
	int iFloor = 0;
	int iRawTomato = 0;

	cin >> iCol >> iRow >> iFloor;

	vector<vector<vector<int>>> vecTomato;
	vecTomato.resize(iFloor);

	queue<Location> Nextqueue;

	for (int i = 0; i < iFloor; ++i)
	{
		vecTomato[i].resize(iRow);

		for (int j = 0; j < iRow; ++j)
		{
			vecTomato[i][j].resize(iCol);

			for (int k = 0; k < iCol; ++k)
			{
				cin >> vecTomato[i][j][k];
				if (vecTomato[i][j][k] == 1)
					Nextqueue.push({ i, j, k });
				if (vecTomato[i][j][k] == 0)
					++iRawTomato;
			}
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

			if ((Next.iRow > 0) && (!vecTomato[Next.iFloor][Next.iRow - 1][Next.iCol]))
			{
				Nextqueue.push({ Next.iFloor, Next.iRow - 1 , Next.iCol });
				vecTomato[Next.iFloor][Next.iRow - 1][Next.iCol] = 1;
			}

			if ((Next.iCol > 0) && (!vecTomato[Next.iFloor][Next.iRow][Next.iCol - 1]))
			{
				Nextqueue.push({ Next.iFloor, Next.iRow , Next.iCol - 1 });
				vecTomato[Next.iFloor][Next.iRow][Next.iCol - 1] = 1;
			}

			if ((Next.iRow < iRow - 1) && (!vecTomato[Next.iFloor][Next.iRow + 1][Next.iCol]))
			{
				Nextqueue.push({ Next.iFloor, Next.iRow + 1 , Next.iCol });
				vecTomato[Next.iFloor][Next.iRow + 1][Next.iCol] = 1;
			}

			if ((Next.iCol < iCol - 1) && (!vecTomato[Next.iFloor][Next.iRow][Next.iCol + 1]))
			{
				Nextqueue.push({ Next.iFloor, Next.iRow , Next.iCol + 1 });
				vecTomato[Next.iFloor][Next.iRow][Next.iCol + 1] = 1;
			}
				
			if ((Next.iFloor > 0) && (!vecTomato[Next.iFloor -1][Next.iRow][Next.iCol]))
			{
				Nextqueue.push({ Next.iFloor -1, Next.iRow, Next.iCol });
				vecTomato[Next.iFloor -1][Next.iRow][Next.iCol] = 1;
			}

			if ((Next.iFloor < iFloor -1) && (!vecTomato[Next.iFloor +1][Next.iRow][Next.iCol]))
			{
				Nextqueue.push({ Next.iFloor +1, Next.iRow, Next.iCol });
				vecTomato[Next.iFloor +1][Next.iRow][Next.iCol] = 1;
			}
		}

		iRawTomato -= Nextqueue.size();
		if (Nextqueue.size()) ++iDate;
	}

	if (iRawTomato != 0)
		cout << -1;
	else
		cout << iDate;

	for (int i = 0; i < iFloor; ++i)
	{
		for (int j = 0; j < iRow; ++j)
			vecTomato[i][j].clear();

		vecTomato[i].clear();
	}

	vecTomato.clear();

	return 0;
}
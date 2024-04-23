#include <iostream>
#include <queue>

using namespace std;

struct Index
{
	int iRow;
	int iCol;
};

void BFS(int** Arr, bool** Visited, int* Answer, int Num, int Startrow, int Startcol);

int main()
{
	int iNum = 0;
	int iAnswer = 0;

	cin >> iNum;

	int** iArr = new int*[iNum];

	for (int i = 0; i < iNum; ++i)
		iArr[i] = new int[iNum];

	bool** bVisited = new bool* [iNum];

	for (int i = 0; i < iNum; ++i)
		bVisited[i] = new bool[iNum];

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
			bVisited[i][j] = false;

	for (int i = 0; i < iNum; ++i)
	{
		string sInput = {};
		cin >> sInput;

		for (int j = 0; j < iNum; ++j)
			iArr[i][j] = sInput[j];
	}

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
		{
			if (bVisited[i][j] == false)
				BFS(iArr, bVisited, &iAnswer, iNum, i, j);
			else
				continue;
		}
	

	cout << iAnswer << " ";

	iAnswer = 0;

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
			if (iArr[i][j] == 'G') { iArr[i][j] = 'R'; }

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
			bVisited[i][j] = false;

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
		{
			if (bVisited[i][j] == false)
				BFS(iArr, bVisited, &iAnswer, iNum, i, j);
			else
				continue;
		}

	cout << iAnswer;

	for (int i = 0; i < iNum; ++i)
	{
		delete iArr[i];
		delete bVisited[i];
		iArr[i] = nullptr;
		bVisited[i] = nullptr;
	}

	delete[]iArr;
	iArr = nullptr;
	delete[]bVisited;
	bVisited = nullptr;

	return 0;
}

void BFS(int** Arr, bool** Visited, int* Answer, int Num, int Startrow, int Startcol)
{
	queue<Index> Checkqueue;

	Checkqueue.push({ Startrow , Startcol });

	Visited[Startrow][Startcol] = true;

	while (1)
	{
		Index Start = Checkqueue.front();
		Checkqueue.pop();

		//cout << Start.iRow << Start.iCol<<" ";

		if (Start.iRow - 1 >= 0)
			if(!Visited[Start.iRow - 1][Start.iCol])
			if (Arr[Start.iRow - 1][Start.iCol] == Arr[Start.iRow][Start.iCol])
			{
				Checkqueue.push({ Start.iRow - 1 , Start.iCol });
				Visited[Start.iRow - 1][Start.iCol] = true;
			}

		if (Start.iRow + 1 < Num)
			if (!Visited[Start.iRow + 1][Start.iCol])
			if (Arr[Start.iRow + 1][Start.iCol] == Arr[Start.iRow][Start.iCol])
			{
				Checkqueue.push({ Start.iRow + 1 , Start.iCol });
				Visited[Start.iRow + 1][Start.iCol] = true;
			}

		if (Start.iCol - 1 >= 0)
			if (!Visited[Start.iRow][Start.iCol - 1])
			if (Arr[Start.iRow][Start.iCol -1] == Arr[Start.iRow][Start.iCol])
			{
				Checkqueue.push({ Start.iRow, Start.iCol -1 });
				Visited[Start.iRow][Start.iCol -1] = true;
			}

		if (Start.iCol + 1 < Num)
			if (!Visited[Start.iRow][Start.iCol + 1])
			if (Arr[Start.iRow][Start.iCol +1] == Arr[Start.iRow][Start.iCol])
			{
				Checkqueue.push({ Start.iRow, Start.iCol +1 });
				Visited[Start.iRow][Start.iCol +1] = true;
			}

		if (Checkqueue.empty())
			break;
	}

	//cout << endl << endl;

	++*Answer;
}
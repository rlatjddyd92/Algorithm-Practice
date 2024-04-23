#include <iostream>
#include <queue>

using namespace std;

enum class DIRECTION
{
	RIGHT,
	DIAGLONAL,
	DOWN,
	END
};

struct Location
{
	int iRow;
	int iCol;
	DIRECTION Direc;
};

void BFS(int** Map, int* Answer, int Num);

int main()
{
	int iNum = 0;
	int iAnswer = 0;

	cin >> iNum;

	int** iMap = new int*[iNum + 1];

	for (int i = 0; i <= iNum; ++i)
		iMap[i] = new int[iNum + 1];

	for (int i = 1; i <= iNum; ++i)
		for (int j = 1; j <= iNum; ++j)
			cin >> iMap[i][j];

	BFS(iMap, &iAnswer, iNum);

	cout << iAnswer;

	for (int i = 0; i <= iNum; ++i)
	{
		delete iMap[i];
		iMap[i] = nullptr;
	}

	delete[]iMap;
	iMap = nullptr;

	return 0;
}

void BFS(int** Map, int* Answer, int Num)
{
	queue<Location> queueLoca;
	queueLoca.push({ 1,2, DIRECTION::RIGHT });

	while (queueLoca.size())
	{
		Location Start = queueLoca.front();
		queueLoca.pop();

		//cout << Start.iRow << " " << Start.iCol << " " << int(Start.Direc) << endl;

		if ((Start.iCol == Num) &&(Start.iRow == Num))
		{
			++*Answer;
			continue;
		}

		if ((Start.Direc != DIRECTION::DOWN) && (Start.iCol < Num))
			if (!Map[Start.iRow][Start.iCol + 1])
				queueLoca.push({ Start.iRow,Start.iCol + 1, DIRECTION::RIGHT });

		if ((Start.iRow < Num) && (Start.iCol < Num))
			if (!Map[Start.iRow][Start.iCol + 1])
				if (!Map[Start.iRow + 1][Start.iCol + 1])
					if (!Map[Start.iRow + 1][Start.iCol])
						queueLoca.push({ Start.iRow + 1,Start.iCol + 1, DIRECTION::DIAGLONAL });

		if ((Start.Direc != DIRECTION::RIGHT) && (Start.iRow < Num))
			if (!Map[Start.iRow + 1][Start.iCol])
				queueLoca.push({ Start.iRow + 1,Start.iCol, DIRECTION::DOWN });
	}
}

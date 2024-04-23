#include <iostream>

using namespace std;

struct DiceInfo
{
	int iRow;
	int iCol;
	int iTop;
	int iBottom;
	int iNorth;
	int iSouth;
	int iWest;
	int iEast;
};

enum Direction
{
	EAST =1,
	WEST =2,
	NORTH =3,
	SOUTH =4,
	ENDDirection,
};

bool MoveDice(DiceInfo* Dice, int* Row, int* Col, int Direction);
void RollDice(DiceInfo* Dice, int Direction);
void CopyNum(DiceInfo* Dice, int** Map);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iRow = 0;
	int iCol = 0;
	int iCommand = 0;
	DiceInfo Dice { 0,0,0,0,0,0,0,0 };

	cin >> iRow >> iCol >> Dice.iRow >> Dice.iCol >> iCommand;

	int** iMap = new int* [iRow];

	for (int i = 0; i < iRow; ++i)
		iMap[i] = new int[iCol];

	for (int i = 0; i < iRow; ++i)
		for (int j = 0; j < iCol; ++j)
			cin >> iMap[i][j];

	for (int i = 0; i < iCommand; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		if (true == MoveDice(&Dice, &iRow, &iCol, iInput))
		{
			CopyNum(&Dice, iMap);
			cout << Dice.iTop << "\n";
		}
	}

	for (int i = 0; i < iRow; ++i)
	{
		delete iMap[i];
		iMap[i] = nullptr;
	}

	delete[]iMap;
	iMap = nullptr;

	return 0;
}

bool MoveDice(DiceInfo* Dice, int* Row, int* Col, int Direction)
{
	if ((EAST == Direction) && (Dice->iCol + 1 < *Col))
		++Dice->iCol;
	else if ((WEST == Direction) && (Dice->iCol - 1 >= 0))
		--Dice->iCol;
	else if ((NORTH == Direction) && (Dice->iRow - 1 >= 0))
		--Dice->iRow;
	else if ((SOUTH == Direction) && (Dice->iRow + 1 < *Row))
		++Dice->iRow;
	else 
		return false;

	RollDice(Dice, Direction);
	return true;
}

void RollDice(DiceInfo* Dice, int Direction)
{
	if (EAST == Direction)
	{
		int iTemp = Dice->iTop;
		Dice->iTop = Dice->iWest;
		Dice->iWest = Dice->iBottom;
		Dice->iBottom = Dice->iEast;
		Dice->iEast = iTemp;
	}
	else if (WEST == Direction)
	{
		int iTemp = Dice->iTop;
		Dice->iTop = Dice->iEast;
		Dice->iEast = Dice->iBottom;
		Dice->iBottom = Dice->iWest;
		Dice->iWest = iTemp;
	}
	else if (NORTH == Direction)
	{
		int iTemp = Dice->iTop;
		Dice->iTop = Dice->iSouth;
		Dice->iSouth = Dice->iBottom;
		Dice->iBottom = Dice->iNorth;
		Dice->iNorth = iTemp;
	}
	else if (SOUTH == Direction)
	{
		int iTemp = Dice->iTop;
		Dice->iTop = Dice->iNorth;
		Dice->iNorth = Dice->iBottom;
		Dice->iBottom = Dice->iSouth;
		Dice->iSouth = iTemp;
	}
}

void CopyNum(DiceInfo* Dice, int** Map)
{
	if (0 == Map[Dice->iRow][Dice->iCol])
	{
		Map[Dice->iRow][Dice->iCol] = Dice->iBottom;
	}
	else 
	{
		Dice->iBottom = Map[Dice->iRow][Dice->iCol];
		Map[Dice->iRow][Dice->iCol] = 0;
	}
}

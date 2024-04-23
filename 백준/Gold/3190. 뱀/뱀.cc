#include <iostream>
#include <list>
#include <map>

using namespace std;

enum Direction
{
	NORTH = 1,
	EAST =2,
	SOUTH =3,
	WEST =4,
	END,
};

enum Behaver
{
	GO =1,
	APPLE =2,
	STOP =3,
};

enum Tile
{
	EMPTY = 0,
	SNAKE =1,
	APPLETILE = 2,
};

struct Location
{
	int iRow;
	int iCol;
};

int CheckSnake(int** Arr, int* Row, int* Col, int* Direction, int* Max);
void InputSnake(int** Arr, int* Row, int* Col, list<Location>* List);
void EraseSnake(int** Arr, int* Row, int* Col, list<Location>* List);
void TurnSnake(map<int, char>* map, int* Direction, int* Second);


int main()
{
	int iMax = 0;
	list<Location> Loclist;
	map<int, char> mapTurn;

	cin >> iMax;

	int** iArr = new int* [iMax + 1];

	for (int i = 0; i <= iMax; ++i)
	{
		iArr[i] = new int[iMax + 1];
	}

	for (int i = 0; i <= iMax; ++i)
	{
		for (int j = 0; j <= iMax; ++j)
			iArr[i][j] = EMPTY;
	}

	int iApple = 0;

	cin >> iApple;

	for (int i = 0; i < iApple; ++i)
	{
		int iAppleRow = 0;
		int iAppleCol = 0; 

		cin >> iAppleRow >> iAppleCol;

		iArr[iAppleRow][iAppleCol] = APPLE;
	}

	int iTurn = 0;
	int iRow = 1;
	int iCol = 1;
	int iSecond = 0;
	int iDirection = EAST;

	cin >> iTurn;

	for (int i = 0; i < iTurn; ++i)
	{
		int iInputSecond = 0;
		char czInput = 0;

		cin >> iInputSecond >> czInput;

		mapTurn.insert({ iInputSecond ,czInput });
	}

	Loclist.push_back({ iRow ,iCol });

	while (1)
	{
		int iTemp = CheckSnake(iArr, &iRow, &iCol, &iDirection, &iMax);

		if (STOP == iTemp)
		{
			++iSecond;
			break;
		}
		else if (GO == iTemp)
		{
			InputSnake(iArr, &iRow, &iCol, &Loclist);
			EraseSnake(iArr, &iRow, &iCol, &Loclist);
			++iSecond;
		}
		else if (APPLE == iTemp)
		{
			InputSnake(iArr, &iRow, &iCol, &Loclist);
			++iSecond;
		}

		TurnSnake(&mapTurn, &iDirection, &iSecond);
	}
	
	cout << iSecond;

	for (int i = 0; i <= iMax; ++i)
	{
		delete iArr[i];
		iArr[i] = nullptr;
	}

	delete[]iArr;
	iArr = nullptr;

	Loclist.clear();
	mapTurn.clear();

	list<Location>().swap(Loclist);
	map<int, char>().swap(mapTurn);

	return 0;
}

int CheckSnake(int** Arr, int* Row, int* Col, int* Direction, int* Max)
{
	switch (*Direction)
	{
	case NORTH:
		--*Row;
		break;

	case EAST:
		++*Col;
		break;

	case SOUTH:
		++*Row;
		break;

	case WEST:
		--*Col;
		break;

	default:
		break;
	}

	if ((EMPTY >= *Row) || (*Max < *Row) || (EMPTY >= *Col) || (*Max < *Col))
		return STOP;

	if (SNAKE == Arr[*Row][*Col])
		return STOP;

	if (APPLETILE == Arr[*Row][*Col])
		return APPLE;

	if (EMPTY == Arr[*Row][*Col])
		return GO;
}

void InputSnake(int** Arr, int* Row, int* Col, list<Location>* List)
{
	Arr[*Row][*Col] = SNAKE;
	List->push_back({ *Row , *Col });
}

void EraseSnake(int** Arr, int* Row, int* Col, list<Location>* List)
{
	Arr[List->front().iRow][List->front().iCol] = EMPTY;
	List->pop_front();
}

void TurnSnake(map<int, char>* map, int* Direction, int* Second)
{
	if (map->end() == map->find(*Second))
		return;

	if ('L' == map->find(*Second)->second)
	{
		if (NORTH == *Direction)
			*Direction = WEST;
		else
			-- * Direction;
	}
	else
	{
		if (WEST == *Direction)
			*Direction = NORTH;
		else
			++ * Direction;
	}
}

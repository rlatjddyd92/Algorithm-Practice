#include <iostream>

using namespace std;

enum Status
{
	DIRTY =0,
	WALL =1,
	CLEAN =2,
	ENDSTATUS,
};

enum Direction
{
	NORTH =0,
	EAST =1,
	SOUTH =2,
	WEST =3,
	ENDDIRECTION,
};

struct RobotInfo
{
	int iDirection;
	int iRow;
	int iCol;
};

void CleanRoom(int** Room, RobotInfo* Info, int* Answer);
void CheckAround(int** Room, RobotInfo* Info, bool* Stop);
void GoToBack(int** Room, RobotInfo* Info, bool* Stop);
void TurnRobot(int** Room, RobotInfo* Info);
void GoToFront(RobotInfo* Info);

int main()
{
	int iMaxRow = 0;
	int iMaxCol = 0;
	bool bStop = 0;
	int iAnswer = 0;
	RobotInfo Robot;

	cin >> iMaxRow >> iMaxCol;

	int** iRoom = new int* [iMaxRow];

	for (int i = 0; i < iMaxRow; ++i)
	{
		iRoom[i] = new int[iMaxCol];
	}

	cin >> Robot.iRow >> Robot.iCol >> Robot.iDirection;

	for (int i = 0; i < iMaxRow; ++i)
		for (int j = 0; j < iMaxCol; ++j)
			cin >> iRoom[i][j];

	while (0 == bStop)
	{
		CleanRoom(iRoom, &Robot, &iAnswer);
		CheckAround(iRoom, &Robot, &bStop);
	}

	cout << iAnswer;

	for (int i = 0; i < iMaxRow; ++i)
	{
		delete iRoom[i];
		iRoom[i] = nullptr;
	}

	delete[]iRoom;
	iRoom = nullptr;

	return 0;
}

void CleanRoom(int** Room, RobotInfo* Info, int* Answer)
{
	if (DIRTY == Room[Info->iRow][Info->iCol])
	{
		Room[Info->iRow][Info->iCol] = CLEAN;
		++*Answer;
	}
}

void CheckAround(int** Room, RobotInfo* Info, bool* Stop)
{
	if (DIRTY == Room[Info->iRow - 1][Info->iCol])
		TurnRobot(Room, Info);
	else if (DIRTY == Room[Info->iRow + 1][Info->iCol])
		TurnRobot(Room, Info);
	else if (DIRTY == Room[Info->iRow][Info->iCol - 1])
		TurnRobot(Room, Info);
	else if (DIRTY == Room[Info->iRow][Info->iCol + 1])
		TurnRobot(Room, Info);
	else
		GoToBack(Room, Info, Stop);
}

void GoToBack(int** Room, RobotInfo* Info, bool* Stop)
{
	if ((NORTH == Info->iDirection)&& (WALL != Room[Info->iRow + 1][Info->iCol]))
	{
		++Info->iRow;
		return;
	}

	if ((EAST == Info->iDirection) && (WALL != Room[Info->iRow][Info->iCol - 1]))
	{
		--Info->iCol;
		return;
	}

	if ((SOUTH == Info->iDirection) && (WALL != Room[Info->iRow - 1][Info->iCol]))
	{
		--Info->iRow;
		return;
	}

	if ((WEST == Info->iDirection) && (WALL != Room[Info->iRow][Info->iCol + 1]))
	{
		++Info->iCol;
		return;
	}

	*Stop = 1;
}

void TurnRobot(int** Room, RobotInfo* Info)
{
	if (NORTH == Info->iDirection)
		Info->iDirection = WEST;
	else
		--Info->iDirection;

	if ((NORTH == Info->iDirection) && (0 == Room[Info->iRow - 1][Info->iCol]))
		GoToFront(Info);
			
	if ((EAST == Info->iDirection) && (0 == Room[Info->iRow][Info->iCol + 1]))
		GoToFront(Info);

	if ((SOUTH == Info->iDirection) && (0 == Room[Info->iRow + 1][Info->iCol]))
		GoToFront(Info);
		
	if ((WEST == Info->iDirection) && (0 == Room[Info->iRow][Info->iCol - 1]))
		GoToFront(Info);
}

void GoToFront(RobotInfo* Info)
{
	if (NORTH == Info->iDirection)
		--Info->iRow;

	if (EAST == Info->iDirection)
		++Info->iCol;

	if (SOUTH == Info->iDirection)
		++Info->iRow;

	if (WEST == Info->iDirection)
		--Info->iCol;
}

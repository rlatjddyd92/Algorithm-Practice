#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int iHeight = 0;
	int iWidth = 0;

	int iAnswer = 0; 

	int iLeftWall = 0;
	int iRightWall = 0;

	cin >> iHeight >> iWidth;

	vector<int> vecWater;
	vecWater.resize(iWidth+2);

	// 정방향으로 탐색 
	for (int i = 1; i <= iWidth; ++i)
	{
		cin >> vecWater[i];
	
		if (vecWater[iLeftWall] <= vecWater[i])
		{
			iRightWall = i;
			int LowWall = min(vecWater[iLeftWall], vecWater[iRightWall]);

			for (int j = iLeftWall + 1; j < iRightWall; ++j)
			{
				iAnswer += LowWall - vecWater[j];
			}

			iLeftWall = iRightWall;
		}
	}

	int iEnd = iRightWall;

	iLeftWall = iWidth+1;
	iRightWall = iWidth+1;

	for (int i = iWidth; i >= iEnd; --i)
	{
		if (vecWater[iRightWall] <= vecWater[i])
		{
			iLeftWall = i;
			int LowWall = min(vecWater[iLeftWall], vecWater[iRightWall]);

			for (int j = iRightWall - 1; j > iLeftWall; --j)
			{
				iAnswer += LowWall - vecWater[j];
			}

			iRightWall = iLeftWall;
		}
	}

	cout << iAnswer;

	vecWater.clear();

	return 0;
}
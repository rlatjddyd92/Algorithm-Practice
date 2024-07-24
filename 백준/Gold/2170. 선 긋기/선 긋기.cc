#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct LINE
{
	int iStart;
	int iEnd;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	LINE LAnswer = { 0,0 };
	int iAnswer = 0;

	cin >> iNum;

	vector<LINE> vecLine;
	vecLine.resize(iNum);

	for (int i = 0; i < iNum; ++i)
	{
		int iInput[2] = { 0, };
		cin >> iInput[0] >> iInput[1];
		vecLine[i].iStart = min(iInput[0], iInput[1]);
		vecLine[i].iEnd = max(iInput[0], iInput[1]);
	}
	
	stable_sort(vecLine.begin(), vecLine.end(), [](LINE Front, LINE Back) {
		if (Front.iStart < Back.iStart)
			return true;
		else if ((Front.iStart == Back.iStart) && (Front.iEnd < Back.iEnd))
			return true;

		return false;
		});

	LAnswer = vecLine[0];

	for (int i = 0; i < iNum;++i)
	{
		if ((LAnswer.iEnd >= vecLine[i].iStart) || (LAnswer.iStart >= vecLine[i].iEnd))
		{
			LAnswer.iStart = min(vecLine[i].iStart, LAnswer.iStart);
			LAnswer.iEnd = max(vecLine[i].iEnd, LAnswer.iEnd);
		}
		else
		{
			iAnswer += LAnswer.iEnd - LAnswer.iStart;
			LAnswer = vecLine[i];
		}
	}

	iAnswer += LAnswer.iEnd - LAnswer.iStart;

	cout << iAnswer;

	vecLine.clear();

	return 0;
}
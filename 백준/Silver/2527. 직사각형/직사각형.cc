#include <iostream>

using namespace std;

struct Info
{
	int iTop;
	int iBottom;
	int iLeft;
	int iRight;
};

bool IsB(Info A, Info B);
bool IsC(Info A, Info B);
bool IsD(Info A, Info B);

int main()
{
	for (int i = 0; i < 4; ++i)
	{
		Info AInfo;
		Info BInfo;

		int iInputX = 0;
		int iInputY = 0;

		cin >> iInputX >> iInputY;

		AInfo.iLeft = iInputX;
		AInfo.iBottom = iInputY;

		cin >> iInputX >> iInputY;

		AInfo.iRight = iInputX;
		AInfo.iTop = iInputY;

		cin >> iInputX >> iInputY;

		BInfo.iLeft = iInputX;
		BInfo.iBottom = iInputY;

		cin >> iInputX >> iInputY;

		BInfo.iRight = iInputX;
		BInfo.iTop = iInputY;

		if (IsB(AInfo, BInfo))
			cout << "b" << endl;
		else if (IsC(AInfo, BInfo))
			cout << "c" << endl;
		else if (IsD(AInfo, BInfo))
			cout << "d" << endl;
		else 
			cout << "a" << endl;
	}

	return 0;
}

bool IsB(Info A, Info B)
{
	if ((A.iBottom == B.iTop) || (B.iBottom == A.iTop))
		if ((A.iLeft < B.iRight) && (B.iLeft < A.iRight))
			return true;
		
	if ((A.iLeft == B.iRight) || (B.iLeft == A.iRight))
		if ((A.iBottom < B.iTop) && (B.iBottom < A.iTop))
			return true;

	return false;
}

bool IsC(Info A, Info B)
{
	if ((A.iBottom == B.iTop) || (B.iBottom == A.iTop))
		if ((A.iLeft == B.iRight) || (B.iLeft == A.iRight))
			return true;

	return false;
}

bool IsD(Info A, Info B)
{
	if ((A.iBottom > B.iTop) || (B.iBottom > A.iTop))
		return true;

	if ((A.iLeft > B.iRight) || (B.iLeft > A.iRight))
		return true;

	return false;
}

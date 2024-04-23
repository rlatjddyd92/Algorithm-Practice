#include <iostream>

using namespace std;

struct BoxInfo
{
	int iTop;
	int iBottom;
	int iLeft;
	int iRight;
};

int main()
{
	BoxInfo AInfo;
	BoxInfo BInfo;

	cin >> AInfo.iLeft >> AInfo.iBottom >> AInfo.iRight >> AInfo.iTop;
	cin >> BInfo.iLeft >> BInfo.iBottom >> BInfo.iRight >> BInfo.iTop;

	if ((AInfo.iLeft > BInfo.iRight) || (BInfo.iLeft > AInfo.iRight))
		cout << "NULL";
	else if ((AInfo.iBottom > BInfo.iTop) || (BInfo.iBottom > AInfo.iTop))
		cout << "NULL";
	else if ((AInfo.iLeft == BInfo.iRight) || (BInfo.iLeft == AInfo.iRight))
	{
		if ((AInfo.iBottom != BInfo.iTop) && (BInfo.iBottom != AInfo.iTop))
			cout << "LINE";
		else
			cout << "POINT";
	}
	else if ((AInfo.iBottom == BInfo.iTop) || (BInfo.iBottom == AInfo.iTop))
	{
		if ((AInfo.iLeft != BInfo.iRight) && (BInfo.iLeft != AInfo.iRight))
			cout << "LINE";
		else
			cout << "POINT";
	}
	else
		cout << "FACE";

	return 0;
}
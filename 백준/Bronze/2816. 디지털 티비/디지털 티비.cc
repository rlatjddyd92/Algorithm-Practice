#include <iostream>

using namespace std;

int main()
{
	int iKBS_First = 0;
	int iKBS_Second = 0;

	int iIndex = 0;

	int iNumberChannel = 0;

	cin >> iNumberChannel;

	for (int i = 0; i < iNumberChannel; ++i)
	{
		string strInput = {};
		cin >> strInput;
		if (strInput == "KBS1")
			iKBS_First = i;
		else if (strInput == "KBS2")
			iKBS_Second = i;
	}

	while ((iKBS_First != 0) || (iKBS_Second != 1))
	{
		if ((iKBS_First != 0) && (iIndex == iKBS_First))
		{
			while (iKBS_First != 0)
			{
				cout << 4;
				if (iIndex == iKBS_Second)
					++iKBS_Second;
				--iIndex;
				--iKBS_First;
			}
		}
		else if ((iKBS_First == 0) && (iIndex == iKBS_Second))
		{
			while (iKBS_Second != 1)
			{
				cout << 4;
				--iIndex;
				--iKBS_Second;
			}
		}
		else
		{
			cout << 1;
			++iIndex;
		}
	}

    return 0;
}
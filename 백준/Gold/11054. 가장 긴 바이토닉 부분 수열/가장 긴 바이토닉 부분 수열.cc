#include <iostream>

using namespace std;

struct LastNum
{
	int iLast;
	bool bIncrease;
};

bool Check_Last(LastNum* Arr, int Input, int Index);
void Check_Num(LastNum* Arr, int Input, int Index);

int main()
{
	int iNum = 0;
	LastNum NumArr[1001] = {};
	NumArr[0] = { 0,true };
	int iIndex = 0;

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		bool bResult = Check_Last(NumArr, iInput, iIndex);

		Check_Num(NumArr, iInput, iIndex);

		if (bResult)
			++iIndex;
	}
		
	cout << iIndex;
	
	return 0;
}

bool Check_Last(LastNum* Arr, int Input, int Index)
{
	if ((Arr[Index].bIncrease) && (Arr[Index].iLast < Input))
	{
		++Index;
		Arr[Index].iLast = Input;
		Arr[Index].bIncrease = true;
		return true;
	}
	else if (Arr[Index].iLast > Input)
	{
		++Index;
		Arr[Index].iLast = Input;
		Arr[Index].bIncrease = false;
		return true;
	}

	return false;
}

void Check_Num(LastNum* Arr, int Input, int Index)
{
	for (int i = Index; i > 0; --i)
	{
		if ((Arr[i - 1].iLast > Input) && (Arr[i].iLast < Input))
		{
			Arr[i].iLast = Input;
			Arr[i].bIncrease = false;
			break;
		}
	}

	for (int i = Index; i > 0; --i)
	{
		if ((Arr[i-1].bIncrease) && (Arr[i-1].iLast < Input))
		{
			if ((Arr[i].bIncrease) && (Arr[i].iLast > Input))
			{
				Arr[i].iLast = Input;
				break;
			}
			if (!Arr[i].bIncrease)
			{
				Arr[i].iLast = Input;
				Arr[i].bIncrease = true;
				break;
			}
		}
	}
}

#include <iostream>

using namespace std;

void Count_Moving(int Num);
void Show_Moving(int From, int Via, int To, int Num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;

	cin >> iNum;

	Count_Moving(iNum);
	Show_Moving(1, 2, 3, iNum);

	//system("pause");

	return 0;
}

void Count_Moving(int Num)
{
	int iCount = 1;

	for (int i = 1; i < Num; ++i)
		iCount += iCount + 1;

	cout << iCount << "\n";
}

void Show_Moving(int From, int Via, int To, int Num)
{
	if (Num > 1)
		Show_Moving(From, To, Via, Num - 1);

	cout << From << " " << To << "\n";

	if (Num > 1)
		Show_Moving(Via, From, To, Num - 1);
}

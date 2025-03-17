#include <iostream>
#include <vector>

using namespace std;

vector<int> vecGate;

int Find_Head(int iIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iGate = 0;
	int iPlain = 0; 
	int iCount = 0;

	cin >> iGate >> iPlain;

	vecGate.resize(iGate + 1);
	bool bIsOne = false;
	int iStop = false;

	for (int i = 0; i <= iGate; ++i)
		vecGate[i] = i;

	vecGate[0] = -1;

	for (int i = 0; i < iPlain; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		if (Find_Head(iInput) == -1)
			iStop = true;

		if (iStop == false)
			++iCount;
	}

	cout << iCount;

	vecGate.clear();

	return 0;
}

int Find_Head(int iIndex)
{
	if ((vecGate[iIndex] < iIndex) && (vecGate[iIndex] >= 0))
		vecGate[iIndex] = Find_Head(vecGate[iIndex]);

	return vecGate[iIndex]--;
}

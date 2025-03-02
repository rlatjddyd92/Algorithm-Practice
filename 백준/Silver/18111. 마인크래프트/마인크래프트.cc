#include <iostream>

using namespace std;

int main()
{
	int iRow = 0; 
	int iCol = 0; 
	int iBlock = 0;

	int iMax = 0; 

	cin >> iRow >> iCol >> iBlock;

	int* iLand = new int[iRow * iCol];

	for (int i = 0; i < (iRow* iCol); ++i)
	{
		cin >> *(iLand + i);

		if (iMax < *(iLand + i))
			iMax = *(iLand + i);
	}



	int iAnswerM = 10000000000;
	int iAnswerF = 0; 

	for (int i = iMax; i >= 0; --i)
	{
		int iTime = 0;
		int iUseBlock = 0;

		for (int j = 0; j < (iRow * iCol); ++j)
		{
			if (i < *(iLand + j))
			{
				iTime += (*(iLand + j)-i)*2;
				iUseBlock -= (*(iLand + j) - i);
			}
			else if (i > *(iLand + j))
			{
				iTime += (i-*(iLand + j));
				iUseBlock += (i - *(iLand + j));
			}
		}
		
		if (iBlock < iUseBlock)
			continue;

		if (iAnswerM > iTime)
		{
			iAnswerM = iTime;
			iAnswerF = i;
		}
	}

	cout << iAnswerM <<" "<< iAnswerF;

	delete[]iLand;
	iLand = nullptr;

	return 0;
}
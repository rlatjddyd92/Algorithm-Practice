#include <iostream>

using namespace std;

int main()
{
	int iTest = 0; 
	int iN = 0;
	int iM = 0; 
	int iAnswer = 1; 

	cin >> iTest;

	for (int i = 0; i < iTest; ++i)
	{
		int iNum[4][10] = { {2,3,5,7,11,13,17,19,23,29},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0} };
		int iAnswer = 1;

		cin >> iN >> iM;

		for (int j = 2; j <= iM; ++j)
		{
			int iTemp = j;
			int iSorc = 0;
			while (1)
			{
				if ((0 < iTemp / *(*(iNum) + iSorc)) && (0 == iTemp % *(*(iNum)+iSorc)))
				{
					++*(*(iNum+1) + iSorc);
					iTemp = iTemp / *(*iNum + iSorc);
				}
				else if ((0 < iTemp / *(*(iNum)+iSorc)) && (0 < iTemp % *(*(iNum)+iSorc)))
				{
					++iSorc;
				}
				else if (0 == iTemp / *(*(iNum)+iSorc))
				{
					break;
				}
			}
		}
		
		for (int j = 2; j <= (iM-iN); ++j)
		{
			int iTemp = j;
			int iSorc = 0;
			while (1)
			{
				if ((0 < iTemp / *(*(iNum)+iSorc)) && (0 == iTemp % *(*(iNum)+iSorc)))
				{
					++*(*(iNum + 2) + iSorc);
					iTemp = iTemp / *(*iNum + iSorc);
				}
				else if ((0 < iTemp / *(*(iNum)+iSorc)) && (0 < iTemp % *(*(iNum)+iSorc)))
				{
					++iSorc;
				}
				else if (0 == iTemp / *(*(iNum)+iSorc))
				{
					break;
				}
			}
		}

		for (int j = 2; j <= iN; ++j)
		{
			int iTemp = j;
			int iSorc = 0;
			while (1)
			{
				if ((0 < iTemp / *(*(iNum)+iSorc)) && (0 == iTemp % *(*(iNum)+iSorc)))
				{
					++*(*(iNum + 3) + iSorc);
					iTemp = iTemp / *(*iNum + iSorc);
				}
				else if ((0 < iTemp / *(*(iNum)+iSorc)) && (0 < iTemp % *(*(iNum)+iSorc)))
				{
					++iSorc;
				}
				else if (0 == iTemp / *(*(iNum)+iSorc))
				{
					break;
				}
			}
		}

		for (int i = 0; i < 10;++i)
		{
			*(*(iNum + 1) + i) -= *(*(iNum + 2) + i);
			*(*(iNum + 1) + i) -= *(*(iNum + 3) + i);
		}

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < *(*(iNum+1)+i); ++j)
			{
				iAnswer *= *(*iNum + i);
			}
		}


		std::cout << iAnswer << endl;
	}

	return 0;
}
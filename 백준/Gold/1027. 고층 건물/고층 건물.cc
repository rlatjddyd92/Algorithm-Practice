#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int iBuilding = 0;
	int iAnswer = 0;

	cin >> iBuilding;

	vector<double>vechigh(iBuilding);

	for (int i = 0; i < iBuilding; ++i)
	{
		cin >> vechigh[i];
	}

	for (int i = 0; i < iBuilding; ++i)
	{
		int iCount = 0;
		double fLimit = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			double fX = double(i) - double(j);
			double fY = vechigh[j] - vechigh[i];

			if (j == i - 1)
			{
				fLimit = fY / fX;
				//cout << vechigh[j] <<"("<< fLimit<<")" << " ";
				++iCount;
			}
			else if (fLimit < fY / fX)
			{
				fLimit = fY / fX;
				//cout << vechigh[j] << "(" << fLimit << ")" << " ";
				++iCount;
			}
		}

		fLimit = 0;

		for (int j = i + 1; j < iBuilding; ++j)
		{
			double fX = double(j) - double(i);
			double fY = vechigh[j] - vechigh[i];

			if (j == i + 1)
			{
				fLimit = fY / fX;
				//cout << vechigh[j] << "(" << fLimit << ")" << " ";
				++iCount;
			}
			else if (fLimit < fY / fX)
			{
				fLimit = fY / fX;
				//cout << vechigh[j] << "(" << fLimit << ")" << " ";
				++iCount;
			}
		}

		if (iAnswer < iCount)
			iAnswer = iCount;

		//cout << iCount << endl;
	}

	cout << iAnswer;

	vechigh.clear();

	return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		string sCommand = {};
		string sNumber = {};
		int iCount = 0;
		bool bReverse = false;
		bool bError = false;
		deque<int> dequeNum;

		cin >> sCommand;
		cin >> iCount;
		cin >> sNumber;

		int iTempNum = 0;

		for (int i = 0; i < sNumber.size(); ++i)
		{
			if ((sNumber[i] == ',') || (sNumber[i] == ']'))
			{
				if (iTempNum) dequeNum.push_back(iTempNum);
				iTempNum = 0;
			}
			else if (sNumber[i] == '[')
			{
				continue;
			}
			else
			{
				iTempNum *= 10;
				iTempNum += sNumber[i] - '0';
			}
		}

		for (int i = 0; i < sCommand.size(); ++i)
		{
			if (sCommand[i] == 'R')
			{
				if (bReverse) bReverse = false;
				else bReverse = true;
			}
			else
			{
				if (dequeNum.empty())
				{
					bError = true;
					break;
				}

				if (bReverse) dequeNum.pop_back();
				else dequeNum.pop_front();
			}
		}

		if (bError)
		{
			cout << "error" << "\n";
			continue;
		}
			

		cout << "[";

		int iSize = dequeNum.size();

		if (bReverse)
		{
			for (int i = 0; i < iSize; ++i)
			{
				cout << dequeNum.back();
				dequeNum.pop_back();
				if (!dequeNum.empty()) cout << ",";
			}
		}
		else
		{
			for (int i = 0; i < iSize; ++i)
			{
				cout << dequeNum.front();
				dequeNum.pop_front();
				if (!dequeNum.empty()) cout << ",";
			}
		}

		cout << "]\n";
	}

	return 0;
}
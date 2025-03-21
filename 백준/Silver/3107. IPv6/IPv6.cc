#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> vecIp;
	vector<string> vecReverse;
	string strInput = {};

	for (int i = 0; i < 8; ++i)
	{
		string strNew = "XXXX";
		vecIp.push_back(strNew);
		vecReverse.push_back(strNew);
	}

	

	cin >> strInput;

	int iIndex = 0;
	int iCount = 0;

	

	char szBefore = 'X';

	bool bIsReverse = false;

	string strNow = {};

	for (int i = 0; i < strInput.size(); ++i)
	{
		if ((szBefore == ':') && (strInput[i] == ':'))
		{
			bIsReverse = true;
			szBefore = 'X';
			iCount = 0;
		}
		else if ((szBefore != 'X') && (strInput[i] == ':'))
		{
			if (bIsReverse == false)
			{
				for (int j = 0; j < strNow.size(); ++j)
					vecIp[iCount][j + (4 - strNow.size())] = strNow[j];

				strNow.clear();
			}
			else
			{
				for (int j = 0; j < strNow.size(); ++j)
					vecReverse[iCount][j + (4 - strNow.size())] = strNow[j];

				strNow.clear();
			}
			

			iCount += 1;
		}
		else if (strInput[i] != ':')
		{
			strNow.push_back(strInput[i]);

			if (i + 1 == strInput.size())
			{
				if (bIsReverse == false)
				{
					for (int j = 0; j < strNow.size(); ++j)
						vecIp[iCount][j + (4 - strNow.size())] = strNow[j];

					strNow.clear();
				}
				else
				{
					for (int j = 0; j < strNow.size(); ++j)
						vecReverse[iCount][j + (4 - strNow.size())] = strNow[j];

					strNow.clear();
				}
			}
			
		}

		szBefore = strInput[i];

		
	}

	if (bIsReverse == true)
		for (int i = 0; i <= iCount; ++i)
			vecIp[i + (7 - iCount)] = vecReverse[i];





	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 4; ++j)
			if (vecIp[i][j] == 'X')
				vecIp[i][j] = '0';

	for (int i = 0; i < 8; ++i)
	{
		cout << vecIp[i];
		if (i < 7)
			cout << ":";
	}
	
	vecIp.clear();


	return 0;
}
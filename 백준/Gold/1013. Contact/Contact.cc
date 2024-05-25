#include <iostream>

#define ZERO '0'
#define ONE '1'

#define NO "NO"
#define YES "YES"

enum PATTEN
{
	PT_1 = 1,
	PT_100 = 2,
	PT_0101 = 3,
	PT_END
};

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
		string strAnser = NO;
		int iPatten = PT_END;
		string strInput = {};
		cin >> strInput;

		for (int j = 0; j < strInput.size(); ++j)
		{
			strAnser = NO;

			if ((iPatten == PT_END) && (strInput[j] == ZERO))
				iPatten = PT_0101;
			else if ((iPatten == PT_END) && (strInput[j] == ONE))
				iPatten = PT_100;
			else if ((iPatten == PT_1) && (strInput[j] == ZERO))
				iPatten = PT_0101;
			else if ((iPatten == PT_1) && (strInput[j] == ONE))
				strAnser = YES;
			else if ((iPatten == PT_100) && (strInput[j] == ZERO))
			{

			}
			else if ((iPatten == PT_100) && (strInput[j] == ONE))
			{
				if (strInput[j - 1] == ONE)
					break;
				else if ((j >= 2) && (strInput[j - 2] == ZERO))
				{
					iPatten = PT_1;
					strAnser = YES;
				}
			}
			else if ((iPatten == PT_0101) && (strInput[j] == ZERO))
			{
				if (strInput[j - 1] != ONE)
				{
					if ((j >= 3) && (strInput[j - 2] == ONE))
						if (strInput[j - 3] == ONE)
						{
							iPatten = PT_100;
							continue;
						}
							
					break;
				}
			}
			else if ((iPatten == PT_0101) && (strInput[j] == ONE))
			{
				if (strInput[j - 1] == ZERO)
					strAnser = YES;
				else 
					iPatten = PT_100;
			}
			else
				break;
		}

		cout << strAnser << "\n";
	}

	return 0;
}

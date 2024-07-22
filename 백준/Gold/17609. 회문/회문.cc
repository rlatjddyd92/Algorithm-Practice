#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		string strInput = {};
		cin >> strInput;

		int iStart[2] = {0,0};
		int iEnd[2] = { strInput.size() - 1, strInput.size() - 1 };
		bool bCanRemove[2] = { true, true };
		
		for (int i = 0; i < 2; ++i)
		{
			while (iStart[i] < iEnd[i])
			{
				if ((strInput[iStart[i]] != strInput[iEnd[i]]) && (bCanRemove[i]))
				{
					bCanRemove[i] = false;
					if (i == 0)
						if (strInput[iStart[i] + 1] == strInput[iEnd[i]])
							++iStart[i];

					if (i == 1)
						if (strInput[iStart[i]] == strInput[iEnd[i] - 1])
							--iEnd[i];
				}

				if (strInput[iStart[i]] == strInput[iEnd[i]])
				{
					++iStart[i];
					--iEnd[i];
				}
				else
					break;
			}
		}
		
		if ((iStart[0] < iEnd[0]) && (iStart[1] < iEnd[1]))
			cout << 2 << "\n";
		else if ((iStart[0] >= iEnd[0]) && (bCanRemove[0]))
			cout << 0 << "\n";
		else if ((iStart[1] >= iEnd[1]) && (bCanRemove[1]))
			cout << 0 << "\n";
		else 
			cout << 1 << "\n";
	}

	return 0;
}
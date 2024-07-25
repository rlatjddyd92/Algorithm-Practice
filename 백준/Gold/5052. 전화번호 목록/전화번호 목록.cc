#include <iostream>
#include <vector>
#include <algorithm>

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
		int iNum = 0;
		string strAnswer = "YES";
		cin >> iNum;

		vector<string> vecNum; 
		vecNum.resize(iNum);

		for (int j = 0; j < iNum; ++j)
			cin >> vecNum[j];

		stable_sort(vecNum.begin(), vecNum.end());

		for (int j = 0; j < iNum - 1; ++j)
		{
			strAnswer = "NO";
			for (int k = 0; k < vecNum[j].size(); ++k)
				if (vecNum[j][k] != vecNum[j + 1][k])
				{
					strAnswer = "YES";
					break;
				}

			if (strAnswer == "NO")
				break;
		}
			
		cout << strAnswer << "\n";

		vecNum.clear();
	}

	return 0;
}
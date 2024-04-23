#include <iostream>
#include <vector>

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
		int iInput = 0;
		int iAnswer = 1;
		cin >> iInput;

		vector<int> vecPlus;
		vecPlus.push_back(1);

		for (int i = 1; i <= iInput; ++i)
		{
			vecPlus.push_back(0);

			if (i % 2 == 0)
				++vecPlus.back();

			if (i >= 3)
				vecPlus.back() += vecPlus[i - 3];

			iAnswer += vecPlus.back();
		}

		cout << iAnswer << "\n";
	}

	return 0;
}
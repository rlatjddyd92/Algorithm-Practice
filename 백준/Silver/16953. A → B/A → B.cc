#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iStart = 0;
	int iEnd = 0;
	int iAnswer = 1;

	cin >> iStart >> iEnd;

	while (1)
	{
		if (iStart == iEnd)
			break;

		if (iStart > iEnd)
		{
			iAnswer = -1;
			break;
		}

		if (1 == iEnd % 10)
		{
			++iAnswer;
			iEnd = (iEnd - 1) / 10;
			continue;
		}
		else if (0 == iEnd % 2)
		{
			++iAnswer;
			iEnd = iEnd / 2;
			continue;
		}
		else
		{
			iAnswer = -1;
			break;
		}
	}

	cout << iAnswer;

	return 0;
}
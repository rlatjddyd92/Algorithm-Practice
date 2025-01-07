#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iBuilding = 0;
	int iAnswer = 0;

	cin >> iBuilding;

	stack<int> stackSky;
	stackSky.push(0);

	for (int i = 0; i < iBuilding; ++i)
	{
		int iIndex = 0;
		int iInput = 0;
		cin >> iIndex >> iInput;

		while (stackSky.top() > iInput)
		{
			stackSky.pop();
			++iAnswer;
		}

		if (iInput > stackSky.top())
			stackSky.push(iInput);
	}

	iAnswer += stackSky.size() - 1;

	cout << iAnswer;

	return 0;
}

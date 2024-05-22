#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct NUMBER
{
	int iIndex;
	int iNum;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;
	
	cin >> iNumber;

	vector<int> vecAns;

	vecAns.resize(iNumber);
	stack<NUMBER> stackNum;

	for (int i = 0; i < iNumber; ++i)
	{
		int iInput = 0;

		cin >> iInput;

		if ((i != 0) && (stackNum.top().iNum < iInput))
		{
			while (!stackNum.empty())
			{
				if (stackNum.top().iNum < iInput)
				{
					vecAns[stackNum.top().iIndex] = iInput;
					stackNum.pop();
				}
				else
					break;
			}
		}

		vecAns[i] = -1;
		stackNum.push({ i,iInput });
	}

	for (int i = 0; i < iNumber; ++i)
	{
		cout << vecAns[i];

		if (i + 1 < iNumber)
			cout << " ";
	}

	vecAns.clear();

	return 0;
}
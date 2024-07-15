#include <iostream>
#include <stack>

using namespace std;

struct PEOPLE
{
	long long iSize;
	long long iCount;
	long long iSame;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iCount = 0;
	long long iAnswer = 0;
	cin >> iCount;

	stack<PEOPLE> stackPeople;

	for (long long i = 0; i < iCount; ++i)
	{
		long long iInput = 0;
		long long iTempCount = 0;
		long long iTempSame = 1;
		cin >> iInput;

		while (!stackPeople.empty())
		{
			if (stackPeople.top().iSize <= iInput)
			{
				iTempCount += stackPeople.top().iSame;
				iAnswer += stackPeople.top().iCount;

				if (stackPeople.top().iSize == iInput)
					iTempSame += stackPeople.top().iSame;

				stackPeople.pop();
			}
			else
				break;
		}

		if (!stackPeople.empty())
			++iTempCount;

		stackPeople.push({ iInput ,iTempCount, iTempSame });
	}

	while (!stackPeople.empty())
	{
		iAnswer += stackPeople.top().iCount;
		stackPeople.pop();
	}

	cout << iAnswer;

	return 0;
}
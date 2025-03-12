#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iNumber = 0;
		int iAnswer = 0;
		cin >> iNumber;

		stack<int> stackOrder;
		stackOrder.push(0);

		for (int j = 0; j < 20; ++j)
		{
			int iInput = 0;
			cin >> iInput;

			stack<int> stackBuffer;
			while (stackOrder.top() > iInput)
			{
				stackBuffer.push(stackOrder.top());
				stackOrder.pop();
			}

			iAnswer += stackBuffer.size();

			stackOrder.push(iInput);

			while (stackBuffer.empty() == false)
			{
				stackOrder.push(stackBuffer.top());
				stackBuffer.pop();
			}
		}

		cout << iNumber << " " << iAnswer << "\n";

	}

    return 0;
}
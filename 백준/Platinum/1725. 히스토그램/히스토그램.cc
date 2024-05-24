#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct SqureInfo
{
	long long iHeight;
	long long iLength;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;
	long long iAnswer = 0;

	cin >> iNum;

	stack<SqureInfo> stackSqure;
	stackSqure.push({ 0,0 });

	for (int i = 0; i < iNum; ++i)
	{
		long long iInput = 0;
		long long iSize = 1;

		cin >> iInput;

		long long iTop = stackSqure.top().iHeight;

		if (iInput < iTop)
		{
			long long iTempLength = 0;

			while (!stackSqure.empty())
			{
				stackSqure.top().iLength += iTempLength;

				if (iAnswer < iTop * stackSqure.top().iLength)
					iAnswer = iTop * stackSqure.top().iLength;

				iTempLength = stackSqure.top().iLength;

				stackSqure.pop();
				iSize = iTempLength + 1;
				iTop = stackSqure.top().iHeight;
				if (iInput >= iTop) break;
			}
		}

		if (iInput == iTop)
			stackSqure.top().iLength += iSize;

		if (iInput > iTop)
			stackSqure.push({ iInput ,iSize });
	}

	long long iTempLength = 0;
		
	while (!stackSqure.empty())
	{
		long long iTop = stackSqure.top().iHeight;
		stackSqure.top().iLength += iTempLength;

		if (iAnswer < iTop * stackSqure.top().iLength)
			iAnswer = iTop * stackSqure.top().iLength;

		iTempLength = stackSqure.top().iLength;

		stackSqure.pop();
	}

	cout << iAnswer;

	return 0;
}

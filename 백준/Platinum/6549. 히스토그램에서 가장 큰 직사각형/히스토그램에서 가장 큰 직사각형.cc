#include <iostream>
#include <stack>

using namespace std;

struct SQURE
{
	long long llHeight;
	long long llLength;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int iNum = 0;
		long long llAnswer = 0;
		
		cin >> iNum;

		if (!iNum) break;

		stack<SQURE> stackSqure;
		stackSqure.push({ 0,0 });

		for (int i = 0; i < iNum; ++i)
		{
			long long llInput = 0;
			long long llSize = 1;
			cin >> llInput;

			if (llInput < stackSqure.top().llHeight)
			{
				long long llTempLength = 0;

				while (!stackSqure.empty())
				{
					if (llInput > stackSqure.top().llHeight) break;

					stackSqure.top().llLength += llTempLength;

					if (llInput == stackSqure.top().llHeight) break;
					
					if (llAnswer < stackSqure.top().llHeight * stackSqure.top().llLength)
						llAnswer = stackSqure.top().llHeight * stackSqure.top().llLength;

					llTempLength = stackSqure.top().llLength;
					llSize = llTempLength + 1;
					stackSqure.pop();
				}
			}

			if (llInput == stackSqure.top().llHeight)
				++stackSqure.top().llLength;

			if (llInput > stackSqure.top().llHeight)
				stackSqure.push({ llInput , llSize });
		}

		long long llTempLength = 0;

		while (!stackSqure.empty())
		{
			stackSqure.top().llLength += llTempLength;

			if (llAnswer < stackSqure.top().llHeight * stackSqure.top().llLength)
				llAnswer = stackSqure.top().llHeight * stackSqure.top().llLength;

			llTempLength = stackSqure.top().llLength;

			stackSqure.pop();
		}

		cout << llAnswer << "\n";
	}

	return 0;
}
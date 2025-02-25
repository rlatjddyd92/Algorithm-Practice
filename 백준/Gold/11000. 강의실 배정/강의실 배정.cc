#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct CLASS
{
	int iStart = 0;
	int iEnd = 0;

	bool operator<(const CLASS Next) const
	{
		return iEnd > Next.iEnd;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iClass = 0;

	priority_queue<CLASS> queueAnswer;
	vector<CLASS> vecInput;

	cin >> iClass;
	for (int i = 0; i < iClass; ++i)
	{
		int iStart = 0;
		int iEnd = 0;

		cin >> iStart >> iEnd;

		vecInput.push_back({ iStart , iEnd });
	}

	stable_sort(vecInput.begin(), vecInput.end(), [](CLASS First, CLASS Second) {return First.iStart < Second.iStart; });

	for (int i = 0; i < iClass; ++i)
	{
		if ((queueAnswer.empty() == true) || (queueAnswer.top().iEnd > vecInput[i].iStart))
			queueAnswer.push({ vecInput[i].iStart ,vecInput[i].iEnd });
		else
		{
			int iStartBuffer = queueAnswer.top().iStart;
			queueAnswer.pop();
			queueAnswer.push({ iStartBuffer ,vecInput[i].iEnd });
		}
	}

	cout << queueAnswer.size();

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> queueTree;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNumber = 0;
	int iSize = 0;

	cin >> iNumber >> iSize;

	for (int i = 0; i < iNumber; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		queueTree.push(iInput);
	}

	int iNowSize = queueTree.top();
	int iNowCut = iNowSize - iSize;
	int iCountTree = 1;
	queueTree.pop();

	while (queueTree.empty() == false)
	{
		if (iNowCut >= queueTree.top())
			break;

		if (iNowCut < queueTree.top())
		{
			iSize -= ((iNowSize - queueTree.top()) * iCountTree);
			iNowSize = queueTree.top();
		}

		++iCountTree;
		
		iNowCut = iNowSize - (iSize / iCountTree);
		iNowCut -= (iSize % iCountTree) > 0 ? 1 : 0;
		queueTree.pop();
	}

	cout << iNowCut;

	return 0;
}
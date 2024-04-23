#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct NodeInfo
{
	NodeInfo* pRoot;
	int iData;
	list<int> ScoreList;
};

NodeInfo* MakeNode(NodeInfo* Index, int Score);
NodeInfo* RemoveNode(NodeInfo* Index, int* Answer);

int main()
{
	char szInput[31] = "";
	int iAnswer = 0;
	bool bFail = 0;
	NodeInfo* pIndex = nullptr;
	list<char> charlist;

	cin >> szInput;

	for (int i = 0; i <= 30; ++i)
	{
		if (*"(" == szInput[i])
			charlist.push_back(*"(");
		else if (*"[" == szInput[i])
			charlist.push_back(*"[");
		else if ((*")" == szInput[i]) && (*"(" == charlist.back()))
			charlist.pop_back();
		else if ((*"]" == szInput[i]) && (*"[" == charlist.back()))
			charlist.pop_back();
		else if (*"\0"== szInput[i])
			break;
		else
		{
			bFail = 1;
			break;
		}
	}

	if (!charlist.empty())
		bFail = 1;

	if (1 == bFail)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= 30; ++i)
	{
		if (*"(" == szInput[i])
			pIndex = MakeNode(pIndex, 2);
		else if (*"[" == szInput[i])
			pIndex = MakeNode(pIndex, 3);
		else if (*")" == szInput[i])
			pIndex = RemoveNode(pIndex, &iAnswer);
		else if (*"]" == szInput[i])
			pIndex = RemoveNode(pIndex, &iAnswer);
		else
			break;
	}

	cout << iAnswer;

	charlist.clear();
	list<char>().swap(charlist);

	return 0;
}

NodeInfo* MakeNode(NodeInfo* Index, int Score)
{
	NodeInfo* Node = new NodeInfo;

	Node->pRoot = Index;
	Node->iData = Score;

	return Node;
}

NodeInfo* RemoveNode(NodeInfo* Index, int* Answer)
{
	if (nullptr == Index->pRoot)
	{
		if (Index->ScoreList.empty())
			*Answer += Index->iData * 1;
		else
		{
			int iTemp = 0;
			for_each(Index->ScoreList.begin(), Index->ScoreList.end(), [&iTemp](int Dest) {iTemp += Dest; });
			*Answer += Index->iData * iTemp;
		}
	}
	else if (Index->ScoreList.empty())
	{
		Index->pRoot->ScoreList.push_back(Index->iData * 1);
	}
	else
	{
		int iTemp = 0;
		for_each(Index->ScoreList.begin(), Index->ScoreList.end(), [&iTemp](int Dest) {iTemp += Dest; });
		Index->pRoot->ScoreList.push_back(Index->iData * iTemp);
	}

	NodeInfo* pTemp = Index->pRoot;
	Index->ScoreList.clear();
	Index->pRoot = nullptr;
	delete Index;
	Index = nullptr;

	return pTemp;
}

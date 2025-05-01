#include <iostream>
#include <vector>

using namespace std;

struct NODE
{
	int iIndex_Of_InOrder = -1;
	int iMin = 0;
	int iMax = 1000000;

	int iLeft = -1;
	int iRight = -1;
};

vector<NODE> vecNode;
vector<int> vecPost;

int iNode = 0;
int iNowIndexPost = 0;

void Check_Node(int iNewMin, int iNewMax);
void Cout_Answer(int iIndex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNode;

	vecNode.resize(iNode + 1);

	for (int i = 0; i < iNode; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecNode[iInput].iIndex_Of_InOrder = i;
	}

	for (int i = 0; i < iNode; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		vecPost.push_back(iInput);
	}

	iNowIndexPost = vecPost.size() - 1;

	Check_Node(0, iNode - 1);
	Cout_Answer(vecPost[vecPost.size() - 1]);

	vecNode.clear();
	vecPost.clear();

	return 0;
}

void Check_Node(int iNewMin, int iNewMax)
{
	NODE* Now = &vecNode[vecPost[iNowIndexPost]];
	Now->iMin = iNewMin;
	Now->iMax = iNewMax;
	--iNowIndexPost;

	while (1)
	{
		if (iNowIndexPost < 0)
			return;

		NODE* Next = &vecNode[vecPost[iNowIndexPost]];

		if ((Now->iLeft == -1) && ((Next->iIndex_Of_InOrder >= Now->iMin) && (Next->iIndex_Of_InOrder < Now->iIndex_Of_InOrder)))
		{
			Now->iLeft = vecPost[iNowIndexPost];
			Check_Node(Now->iMin, Now->iIndex_Of_InOrder - 1);
		}	
		if ((Now->iRight == -1) && ((Next->iIndex_Of_InOrder <= Now->iMax) && (Next->iIndex_Of_InOrder > Now->iIndex_Of_InOrder)))
		{
			Now->iRight = vecPost[iNowIndexPost];
			Check_Node(Now->iIndex_Of_InOrder + 1, Now->iMax);
		}
		else
			return;
	}
}

void Cout_Answer(int iIndex)
{
	if (iIndex < 1)
		return;

	cout << iIndex << " ";

	Cout_Answer(vecNode[iIndex].iLeft);
	Cout_Answer(vecNode[iIndex].iRight);
}

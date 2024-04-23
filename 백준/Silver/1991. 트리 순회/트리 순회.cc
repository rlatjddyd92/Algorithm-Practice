#include <iostream>
#include <map>

using namespace std;

struct Node
{
	char szRoot;
	char szLeft;
	char szRight;
	int iVisited;
};

void PreOrder(map<char, Node>* mapNode, char* Index, int Visit);
void InOrder(map<char, Node>* mapNode, char* Index, int Visit);
void PostOrder(map<char, Node>* mapNode, char* Index, int Visit);
bool GoToDown(map<char, Node>* mapNode, char* Index, int Visit);
bool GoToUp(map<char, Node>* mapNode, char* Index);

int main()
{
	int iNode = 0;
	char szIndex = {};
	map<char, Node> mapNode;

	cin >> iNode;

	for (int i = 0; i < iNode; ++i)
	{
		char szInputKey = {};
		char szInputLeft = {};
		char szInputRight = {};

		cin >> szInputKey >> szInputLeft >> szInputRight;

		if ('.' == szInputLeft)
			szInputLeft = '\0';

		if ('.' == szInputRight)
			szInputRight = '\0';


		if (mapNode.end() == mapNode.find(szInputKey))
		{
			szIndex = szInputKey;
			mapNode.insert({ szInputKey, {'\0',szInputLeft,szInputRight,0 } });
		}
		else
		{
			mapNode.find(szInputKey)->second.szLeft = szInputLeft;
			mapNode.find(szInputKey)->second.szRight = szInputRight;
		}
			
		if ('\0' != szInputLeft)
			mapNode.insert({ szInputLeft, {szInputKey,'\0','\0',0} });

		if ('\0' != szInputRight)
			mapNode.insert({ szInputRight, {szInputKey,'\0','\0',0} });
	}

	PreOrder(&mapNode, &szIndex, 0);
	cout << "\n";
	InOrder(&mapNode, &szIndex, 1);
	cout << "\n";
	PostOrder(&mapNode, &szIndex, 2);

	mapNode.clear();

	return 0;
}

void PreOrder(map<char, Node>* mapNode, char* Index, int Visit)
{
	while (1)
	{
		if (0 == mapNode->find(*Index)->second.iVisited)
		{
			cout << *Index;
			mapNode->find(*Index)->second.iVisited = 1;
		}

		if (false == GoToDown(mapNode, Index, Visit))
			if (false == GoToUp(mapNode, Index))
				break;
	}
}

void InOrder(map<char, Node>* mapNode, char* Index, int Visit)
{
	while (1)
	{
		if (1 == mapNode->find(*Index)->second.iVisited)
		{
			if (('\0' == mapNode->find(*Index)->second.szLeft)||(2 == mapNode->find(mapNode->find(*Index)->second.szLeft)->second.iVisited))
				if (('\0' != mapNode->find(*Index)->second.szRight) && (1 == mapNode->find(mapNode->find(*Index)->second.szRight)->second.iVisited))
				{
					cout << *Index;
					mapNode->find(*Index)->second.iVisited = 2;
				}

			if (false == GoToDown(mapNode, Index, Visit))
			{
				cout << *Index;
				mapNode->find(*Index)->second.iVisited = 2;

				if (false == GoToUp(mapNode, Index))
					break;
			}
		}
		else
		{
			if (false == GoToUp(mapNode, Index))
				break;
		}
	}
}

void PostOrder(map<char, Node>* mapNode, char* Index, int Visit)
{
	while (1)
	{
		if (2 == mapNode->find(*Index)->second.iVisited)
		{
			if (false == GoToDown(mapNode, Index, Visit))
			{
				cout << *Index;
				mapNode->find(*Index)->second.iVisited = 3;

				if (false == GoToUp(mapNode, Index))
					break;
			}
		}
	}
}

bool GoToDown(map<char, Node>* mapNode, char* Index, int Visit)
{
	if (('\0' != mapNode->find(*Index)->second.szLeft) && (Visit == mapNode->find(mapNode->find(*Index)->second.szLeft)->second.iVisited))
	{
		*Index = mapNode->find(*Index)->second.szLeft;
		return true;
	}
	else if (('\0' != mapNode->find(*Index)->second.szRight) && (Visit == mapNode->find(mapNode->find(*Index)->second.szRight)->second.iVisited))
	{
		*Index = mapNode->find(*Index)->second.szRight;
		return true;
	}

	return false;
}

bool GoToUp(map<char, Node>* mapNode, char* Index)
{
	if ('\0' == mapNode->find(*Index)->second.szRoot)
		return false;

	*Index = mapNode->find(*Index)->second.szRoot;
	return true;
}

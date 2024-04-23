#include <iostream>
#include <vector>

using namespace std;

void AddX(vector<bool>* vecNum, int X);
void RemoveX(vector<bool>* vecNum, int X);
void CheckX(vector<bool>* vecNum, int X);
void ToggleX(vector<bool>* vecNum, int X);
void All(vector<bool>* vecNum);
void Empty(vector<bool>* vecNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCommand = 0;
	vector<bool> vecNum(21);

	cin >> iCommand;

	for (int i = 0; i < iCommand; ++i)
	{
		string sInput = {};
		int iInput = 0;
		cin >> sInput;

		if ("add" == sInput)
		{
			cin >> iInput;
			AddX(&vecNum, iInput);
		}
		else if ("remove" == sInput)
		{
			cin >> iInput;
			RemoveX(&vecNum, iInput);
		}
		else if ("check" == sInput)
		{
			cin >> iInput;
			CheckX(&vecNum, iInput);
		}
		else if ("toggle" == sInput)
		{
			cin >> iInput;
			ToggleX(&vecNum, iInput);
		}
		else if ("all" == sInput)
		{
			All(&vecNum);
		}
		else if ("empty" == sInput)
		{
			Empty(&vecNum);
		}
	}

	vecNum.clear();
	vector<bool>().swap(vecNum);

	return 0;
}

void AddX(vector<bool>* vecNum, int X)
{
	vector<bool>::iterator iter = vecNum->begin();
	iter += X;
	*iter = 1;
}

void RemoveX(vector<bool>* vecNum, int X)
{
	vector<bool>::iterator iter = vecNum->begin();
	iter += X;
	*iter = 0;
}

void CheckX(vector<bool>* vecNum, int X)
{
	vector<bool>::iterator iter = vecNum->begin();
	iter += X;

	cout << *iter << "\n";
}

void ToggleX(vector<bool>* vecNum, int X)
{
	vector<bool>::iterator iter = vecNum->begin();
	iter += X;

	if (1 == *iter)
		*iter = 0;
	else
		*iter = 1;
}

void All(vector<bool>* vecNum)
{
	vector<bool>::iterator iter = vecNum->begin();

	for (iter; iter != vecNum->end(); ++iter)
		*iter = 1;
}

void Empty(vector<bool>* vecNum)
{
	vector<bool>::iterator iter = vecNum->begin();

	for (iter; iter != vecNum->end(); ++iter)
		*iter = 0;
}

#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iNum = 0;
	int iCut = 0;

	cin >> iNum >> iCut;

	string strInput = {};
	list<char> Answerlist;

	cin >> strInput;
	Answerlist.push_back(strInput[0]);

	for (int i = 1; i < strInput.size(); ++i)
	{
		while (((!Answerlist.empty()) && (Answerlist.back() < strInput[i])) && (iCut > 0))
		{
			Answerlist.pop_back();
			--iCut;
		}

		Answerlist.push_back(strInput[i]);
	}

	while (iCut > 0)
	{
		Answerlist.pop_back();
		--iCut;
	}

	while (!Answerlist.empty())
	{
		cout << Answerlist.front();
		Answerlist.pop_front();
	}

	Answerlist.clear();

	return 0;
}
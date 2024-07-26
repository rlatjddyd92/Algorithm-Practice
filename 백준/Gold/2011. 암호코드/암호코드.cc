#include <iostream>
#include <list>

using namespace std;

struct CHECK
{
	int iNum;
	int iCount;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strInput = {};

	cin >> strInput;

	list<CHECK> Countlist;

	Countlist.push_back({ 0,1 });
	Countlist.push_back({ 0,1 });

	for (int i = 0; i < strInput.size(); ++i)
	{
		CHECK tTemp = { strInput[i] - '0', 0 };

		if (Countlist.back().iNum != 0)
		if (((Countlist.back().iNum * 10) + tTemp.iNum <= 'Z' - 'A' + 1))
			tTemp.iCount += Countlist.front().iCount;

		if ((tTemp.iNum > 0) && (tTemp.iNum < 10))
			tTemp.iCount += Countlist.back().iCount;

		tTemp.iCount %= 1000000;

		Countlist.push_back(tTemp);
		Countlist.pop_front();
	}

	cout << Countlist.back().iCount;

	Countlist.clear();

	return 0;
}
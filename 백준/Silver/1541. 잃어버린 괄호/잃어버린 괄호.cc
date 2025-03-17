#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strInput = {};

	cin >> strInput;

	list<int> Numberlist;
	Numberlist.push_back(0);

	int iNowNumber = 0;
	bool bIsPlus = true;

	for (int i = 0; i < strInput.size(); ++i)
	{
		if (strInput[i] == '+')
		{
			if (bIsPlus == true)
				Numberlist.back() += iNowNumber;
			else 
				Numberlist.push_back(iNowNumber);

			bIsPlus = true;
			iNowNumber = 0;
		}
		else if (strInput[i] == '-')
		{
			if (bIsPlus == true)
				Numberlist.back() += iNowNumber;
			else
				Numberlist.push_back(iNowNumber);

			bIsPlus = false;
			iNowNumber = 0;
		}
		else
		{
			iNowNumber *= 10;
			iNowNumber += strInput[i] - '0';
		}
	}

	int iAnswer = 0;

	if (bIsPlus == true)
		Numberlist.back() += iNowNumber;
	else
		Numberlist.push_back(iNowNumber);

	iAnswer = Numberlist.front();
	Numberlist.pop_front();

	while (Numberlist.empty() == false)
	{
		iAnswer -= Numberlist.front();
		Numberlist.pop_front();
	}

	cout << iAnswer;

	Numberlist.clear();

	return 0;
}
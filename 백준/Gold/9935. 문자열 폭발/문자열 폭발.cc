#include <iostream>
#include <list>

using namespace std;

int main()
{
	string sInput = {};
	string sTrigger = {};
	string sAnswer = {};

	cin >> sInput;
	cin >> sTrigger;

	list<int> Triggerlist;

	Triggerlist.push_back(0);

	for (int i = 0; i < sInput.size(); ++i)
	{
		if (sInput[i] == sTrigger[Triggerlist.back()])
		{
			++Triggerlist.back();
			if (Triggerlist.back() == sTrigger.size())
			{
				Triggerlist.pop_back();

				if (!Triggerlist.size())
					Triggerlist.push_back(0);
			}
			continue;
		}
		
		if (sInput[i] == sTrigger[0])
		{
			Triggerlist.push_back(1);
			continue;
		}

		if (Triggerlist.back())
		{
			for (list<int>::iterator iter = Triggerlist.begin(); iter != Triggerlist.end(); ++iter)
				for (int i = 0; i < *(iter); ++i)
					sAnswer += sTrigger[i];

			Triggerlist.clear();
			Triggerlist.push_back(0);
		}
			
		sAnswer += sInput[i];
	}

	if (Triggerlist.back())
	{
		for (list<int>::iterator iter = Triggerlist.begin(); iter != Triggerlist.end(); ++iter)
			for (int i = 0; i < *(iter); ++i)
				sAnswer += sTrigger[i];
	}

	if (!sAnswer.size())
		cout << "FRULA";
	else
		cout << sAnswer;

	Triggerlist.clear();

	return 0;
}
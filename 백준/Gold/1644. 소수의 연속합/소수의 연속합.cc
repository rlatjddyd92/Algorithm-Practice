#include <iostream>
#include <list>

using namespace std;

bool bNum[2000001] = {};

int main()
{
	int iInput = 0;
	int iAnswer = 0;
	list<int> Checklist;
	list<int> Sumlist;

	cin >> iInput;

	for (int i = 2; i <= iInput; ++i)
	{
		++i;
		int iCount = 3;

		while ((i * iCount) <= iInput)
		{
			bNum[(i * iCount)/2] = true;
			iCount += 2;
		}
	}

	Checklist.push_back(2);

	for (int i = 2; i <= iInput; ++i)
	{
		++i;

		if (bNum[i / 2])
			continue;

		Checklist.push_back(i);
	}

	for (list<int>::iterator iterCheck = Checklist.begin() ; iterCheck != Checklist.end(); ++iterCheck)
	{
		Sumlist.push_back(0);

		for (list<int>::iterator itersum = Sumlist.begin(); itersum != Sumlist.end(); )
		{
			*itersum += *iterCheck;

			if (*itersum == iInput)
				++iAnswer;

			if (*itersum >= iInput)
				itersum = Sumlist.erase(itersum);
			else
				++itersum;
		}
	}

	cout << iAnswer;

	Checklist.clear();
	Sumlist.clear();

	return 0;
}
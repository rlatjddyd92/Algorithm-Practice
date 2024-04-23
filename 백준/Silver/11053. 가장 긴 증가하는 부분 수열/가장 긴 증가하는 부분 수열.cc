#include <iostream>
#include <list>
#include <functional>

using namespace std;

struct Info
{
	int iCount;
	int iLast;
};

int main()
{
	int iNum = 0;

	cin >> iNum;

	list<Info> Lastlist;

	Lastlist.push_back({ 0,0 });

	for (int i = 0; i < iNum; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		list<Info>::iterator iter = Lastlist.begin();

		while (1)
		{
			if (iInput > iter->iLast)
			{
				Lastlist.push_back({ iter->iCount + 1,iInput });
				Lastlist.sort([](Info Dest, Info Sorc) {return Dest.iLast > Sorc.iLast; });
				Lastlist.sort([](Info Dest, Info Sorc) {return Dest.iCount > Sorc.iCount; });
				break;
			}
			else
			{
				++iter;
			}
		}
	}

	cout << Lastlist.front().iCount;

	Lastlist.clear();
	list<Info>().swap(Lastlist);

	return 0;
}
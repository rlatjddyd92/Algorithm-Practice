#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct STUDENT
{
	int iSelect;
	int iGroup;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iStudent = 0;
		cin >> iStudent;
		int iAnswer = iStudent;

		vector<STUDENT> vecStudent;
		vecStudent.resize(iStudent + 1);

		for (int j = 1; j <= iStudent; ++j)
			cin >> vecStudent[j].iSelect;

		int iGroupNum = 0;

		for (int j = 1; j <= iStudent; ++j)
		{
			if (vecStudent[j].iGroup != 0)
				continue;

			++iGroupNum;
			list<int> Selectlist;
			Selectlist.push_back(j);

			while (!Selectlist.empty())
			{
				int iNow = Selectlist.back();
				vecStudent[iNow].iGroup = iGroupNum;
				if ((vecStudent[iNow].iSelect != iNow) && (vecStudent[vecStudent[iNow].iSelect].iGroup == 0))
					Selectlist.push_back(vecStudent[iNow].iSelect);
				else if ((vecStudent[iNow].iSelect != iNow) && (vecStudent[vecStudent[iNow].iSelect].iGroup != 0))
				{
					if (vecStudent[vecStudent[iNow].iSelect].iGroup != iGroupNum)
						Selectlist.clear();

					while (!Selectlist.empty())
					{
						if (Selectlist.front() != vecStudent[iNow].iSelect)
							vecStudent[Selectlist.front()].iGroup = -1;
						else
							break;

						Selectlist.pop_front();
					}
					iAnswer -= Selectlist.size();
					Selectlist.clear();
				}
				else
				{
					vecStudent[iNow].iGroup = iGroupNum;
					iAnswer -= 1;
					while (!Selectlist.empty())
					{
						vecStudent[Selectlist.front()].iGroup = -1;
						Selectlist.pop_front();
					}
				}
			}
		}

		cout << iAnswer << '\n';

		vecStudent.clear();
	}

	return 0;
}
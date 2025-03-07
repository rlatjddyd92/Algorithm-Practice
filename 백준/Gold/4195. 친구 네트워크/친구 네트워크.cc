#include <iostream>
#include <map>

#define EMPTY "000"

using namespace std;

map<string, pair<string, int>> mapPeople; // 이름, 그룹 대장(이름), 인원수 

pair<string, int> Findhead(pair<string, int> Name, string NewHead = EMPTY);
void MergeGroup(pair<string, int> iFirst, pair<string, int> iSecond);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase; ++i)
	{
		int iRoute = 0;
		cin >> iRoute;


		for (int j = 0; j < iRoute; ++j)
		{
			string NameA = {};
			string NameB = {};

			cin >> NameA >> NameB;

			if (mapPeople.find(NameA) == mapPeople.end())
			{
				pair<string, int> InfoA = { NameA, 1 };
				mapPeople.insert({ NameA , InfoA });
			}

			if (mapPeople.find(NameB) == mapPeople.end())
			{
				pair<string, int> InfoB = { NameB, 1 };
				mapPeople.insert({ NameB , InfoB });
			}

			MergeGroup({ NameA, mapPeople.find(NameA)->second.second }, { NameB, mapPeople.find(NameB)->second.second });

			cout << mapPeople.find(mapPeople.find(NameA)->second.first)->second.second << "\n";
		}

		mapPeople.clear();
	}

	return 0;
}

pair<string, int> Findhead(pair<string, int> Name, string NewHead)
{
	Name.second = max(Name.second, mapPeople.find(Name.first)->second.second); // 인원수 갱신 
	mapPeople.find(Name.first)->second.second = Name.second;

	if (mapPeople.find(Name.first)->second.first != Name.first)
		mapPeople.find(Name.first)->second = Findhead(mapPeople.find(Name.first)->second, NewHead);
	else if ((NewHead != EMPTY) && (mapPeople.find(Name.first)->second.first != NewHead)) // 헤드 바꾸기 
		mapPeople.find(Name.first)->second = Findhead(mapPeople.find(NewHead)->second, EMPTY);
		
	return mapPeople.find(Name.first)->second;
}

void MergeGroup(pair<string, int> iFirst, pair<string, int> iSecond)
{
	pair<string, int> HeadFirst = Findhead(iFirst);
	pair<string, int> HeadSecond = Findhead(iSecond);

	if (HeadFirst.first != HeadSecond.first)
	{
		iFirst.second = iSecond.second = HeadFirst.second + HeadSecond.second;

		string NewHead = min(HeadFirst.first, HeadSecond.first);

		if (NewHead == HeadFirst.first)
		{
			Findhead(iFirst);
			Findhead(iSecond, NewHead);
		}
		else
		{
			Findhead(iSecond);
			Findhead(iFirst, NewHead);
		}
	}
	else if (iFirst.second != HeadSecond.second)
	{
		iFirst.second = iSecond.second = max(HeadFirst.second, HeadSecond.second);

		Findhead(iFirst);
		Findhead(iSecond);
	}
}

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

void CheckNextGear(list<int>** Gearlist, int* GearTurn, int Gear);
void CheckBeforGear(list<int>** Gearlist, int* GearTurn, int Gear);
void TurnGear(list<int>** Gearlist, int* GearTurn);

int main()
{
	list<int>** pGearlist = new list<int>*[4];

	for (int i = 0; i < 4;++i)
	{
		pGearlist[i] = new list<int>;
	}

	int iInput = 0;

	for (int i = 0; i < 4;++i)
	{
		cin >> iInput;

		for (int j = 7; j >= 0;--j)
		{
			int iTemp = int(pow(10, j));
			pGearlist[i]->push_back(iInput / iTemp);
			iInput %= iTemp;
		}
	}

	int iCase = 0;

	cin >> iCase;

	for (int i = 0; i < iCase;++i)
	{
		int iGearTurn[4] = { 0 };
		int iGear = 0;
		int iTurn = 0;

		cin >> iGear >> iTurn;
		--iGear;
		iGearTurn[iGear] = iTurn;

		CheckNextGear(pGearlist, iGearTurn, iGear);
		CheckBeforGear(pGearlist, iGearTurn, iGear);
		TurnGear(pGearlist, iGearTurn);
	}

	int iAnswer = 0; 

	if (1 == pGearlist[0]->front())
		iAnswer += 1;

	if(1 == pGearlist[1]->front())
		iAnswer += 2;

	if(1 == pGearlist[2]->front())
		iAnswer += 4;

	if(1 == pGearlist[3]->front())
		iAnswer += 8;

	cout << iAnswer;

	for (int i = 0; i < 4; ++i)
	{
		delete pGearlist[i];
		pGearlist[i] = nullptr;
	}

	delete[]pGearlist;
	pGearlist = nullptr;

	return 0;
}

void CheckNextGear(list<int>** Gearlist, int* GearTurn, int Gear)
{
	if (3 <= Gear)
		return;

	list<int>::iterator iterA = Gearlist[Gear]->begin();
	list<int>::iterator iterB = Gearlist[Gear + 1]->begin();

	for (int i = 0; i < 2; ++i)
		++iterA;

	for (int i = 0; i < 6; ++i)
		++iterB;

	if (*iterA!=*iterB)
	{
		GearTurn[Gear + 1] = (GearTurn[Gear] * ( - 1));
		CheckNextGear(Gearlist, GearTurn, Gear + 1);	
	}
}

void CheckBeforGear(list<int>** Gearlist, int* GearTurn, int Gear)
{
	if (0 >= Gear)
		return;

	list<int>::iterator iterA = Gearlist[Gear]->begin();
	list<int>::iterator iterB = Gearlist[Gear - 1]->begin();

	for (int i = 0; i < 6; ++i)
		++iterA;

	for (int i = 0; i < 2; ++i)
		++iterB;

	if (*iterA != *iterB)
	{
		GearTurn[Gear - 1] = (GearTurn[Gear] * ( - 1));
		CheckBeforGear(Gearlist, GearTurn, Gear - 1);
	}
}

void TurnGear(list<int>** Gearlist, int* GearTurn)
{
    for (int i = 0; i < 4; ++i)
	{
		if (1 == GearTurn[i])
		{
			int iTemp = Gearlist[i]->back();
			Gearlist[i]->pop_back();
			Gearlist[i]->push_front(iTemp);
		}
		else if (-1 == GearTurn[i])
		{
			int iTemp = Gearlist[i]->front();
			Gearlist[i]->pop_front();
			Gearlist[i]->push_back(iTemp);
		}
	}
}

#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Building
{
	int Make_TotalTime(vector<int> TotalTime)
	{
		int iMax = 0;

		for (list<int>::iterator iter = m_Buildinglist.begin(); iter != m_Buildinglist.end(); ++iter)
		{
			if (TotalTime[*iter] == -1)
				return -1;

			if (iMax < TotalTime[*iter])
				iMax = TotalTime[*iter];
		}

		m_iTotalTime = iMax + m_iTime;

		return m_iTotalTime;
	}

	int m_iTime; // 해당 건물 짓는 시간
	int m_iTotalTime; // 이전 건물을 고려한 최종 시간 
	list<int> m_Buildinglist; // 해당 건물을 짓기 위해 필요한 건물
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
		int iBuilding = 0;
		int iRoute = 0;
		int iQuestion = 0;

		cin >> iBuilding >> iRoute;

		vector<Building> vecBuilding;
		vector<int> vecTotalTime;
		
		vecBuilding.resize(iBuilding + 1);
		vecTotalTime.resize(iBuilding + 1);

		for (int j = 1; j <= iBuilding; ++j)
			vecTotalTime[j] = -1;
		
		for (int j = 1; j <= iBuilding; ++j)
			cin >> vecBuilding[j].m_iTime;

		for (int j = 0; j < iRoute; ++j)
		{
			int iStart = 0;
			int iEnd = 0;

			cin >> iStart >> iEnd;

			vecBuilding[iEnd].m_Buildinglist.push_back(iStart);
		}

		while (1)
		{
			int iCount = 0;

			for (int j = 1; j <= iBuilding; ++j)
			{
				if (vecTotalTime[j] != -1)
					continue;

				++iCount;

				vecTotalTime[j] = vecBuilding[j].Make_TotalTime(vecTotalTime);

				//cout << j << " ";

				//for (int k = 1; k <= iBuilding; ++k)
					//cout << vecTotalTime[k] << " ";

				//cout << endl;
			}

			if (!iCount)
				break;
		}
		
		cin >> iQuestion;

		cout << vecTotalTime[iQuestion] << "\n";
	}

	return 0;
}